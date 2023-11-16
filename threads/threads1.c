#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define ARRAY_LEN 4
/* Section array */
int sections[ARRAY_LEN] = {1, 2, 3, 4};
/* Generate temperatures */
void genRandomTemperatures(int *array, int len, int min, int max){
    for (int i = 0; i < len; i++)
        array[i] = rand() % (max - min + 1) + min;
}

/*Generate Humility */

void genRandomHumidity(int *array, int len, int min, int max){
    for (int i = 0; i < len; i++)
        array[i] = rand() % (max - min + 1) + min;
}

/* Generat soil moisture */
void genRandomSoilMoisture(int *array, int len, int min, int max){
    for (int i = 0; i < len; i++)
        array[i] = rand() % (max - min + 1) + min;
}

void* routine(void* arg) {
    int section = *((int*)arg);
    free(arg);

    int temp;
    int humidity;
    int soilMoisture;

    genRandomTemperatures(&temp, 1, 0, 50);
    genRandomHumidity(&humidity, 1, 0, 100);
    genRandomSoilMoisture(&soilMoisture, 1, 0, 1023);

    printf("Section %d. Temp:[%d], Hum:[%d], Soil Mois:[%d]\n",
           section, temp, humidity, soilMoisture);

    return NULL;

};

int main() {
    srand(time(0));

    pthread_t th[4];
    int i;
    for (i = 0; i < 4; i++) {
        int* section = malloc(sizeof(int));
        *section = sections[i];
        if (pthread_create(&th[i], NULL, &routine, section) != 0) {
            perror("Failed to create thread");
            return 1;
        }
        //printf("Thread %d has started\n", i);
    }

    // Wait for all threads to finish
    for (i = 0; i < ARRAY_LEN; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
            return 2;
        }
        //printf("Thread %d has finished execution\n", i);
    }

    return 0;
}
