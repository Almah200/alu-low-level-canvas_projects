#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct player {
    char name[20];
    int attempts;
    int score;
};

int main() {
    struct player players[3];
    int number, guess, found;
    srand(time(NULL));
    number = rand() % 100;

    printf("Enter the names of the players:\n");
    for (int i = 0; i < 3; i++) {
        printf("Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].attempts = 0;
        players[i].score = 0;
    }

    printf("The game is starting\n");

    while (found != 1) {
        for (int i = 0; i < 3; i++) {
            printf("%s, Enter your guess of a number between 0 and 100: ", players[i].name);
            scanf("%d", &guess);
            players[i].attempts++;

            if (guess == number) {
                printf("Congrats, %s, you got it right!\n", players[i].name);
                printf("Guessed number: %d\n", number);
                printf("Number of attempts: %d\n", players[i].attempts);
                players[i].score += 10; /* Update the score */
                found = 1;
                break; /* Player i won, so exit the loop */
            } else if (guess > number) {
                printf("The number %s, guessed is high\n", players[i].name);
            } else {
                printf("The number %s, guessed is low\n", players[i].name);
            }
        }
    }

    /* Display the final scores */
    printf("Final Scores:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    return 0;
}
