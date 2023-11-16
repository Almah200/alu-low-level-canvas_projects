#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdint.h>  // Include the header for intptr_t

#define ARRAY_LEN 100

int numbers[ARRAY_LEN] = {};  // Declare the numbers array globally

void gen_random_numbers(int *array, int len, int min, int max) {
    for (int i = 0; i < len; i++)
        array[i] = rand() % (max - min + 1) + min;
}

void* routine(void* arg) {
    int* index = (int*)arg;
    int sum = 0;
    for (int j = 0; j < 50; j++) {
        sum += numbers[*index + j];
    }
    printf("Local sum: %d\n", sum);
    free(arg);
    return (void*)(intptr_t)sum;
}

int main() {
    srand(time(0));

    gen_random_numbers(numbers, ARRAY_LEN, 10, 200);

    pthread_t th[2];
    int i;
    for (i = 0; i < 2; i++) {
        int* a = malloc(sizeof(int));
        *a = i * 50;
        if (pthread_create(&th[i], NULL, &routine, a) != 0) {
            perror("Failed to create thread");
        }
    }
    int globalSum = 0;
    for (i = 0; i < 2; i++) {
        void* r;
        if (pthread_join(th[i], &r) != 0) {
            perror("Failed to join thread");
        }
        globalSum += (intptr_t)r;
    }
    printf("Global sum: %d\n", globalSum);

    return 0;
}
