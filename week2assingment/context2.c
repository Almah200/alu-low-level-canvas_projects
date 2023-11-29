#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char password[41];
    char twoWords[2][20];

    /* Ask the user to Enter 2 words */
    printf("Enter 2 words of your choice to generate a strong password for you: ");

    /* Scan the two words */
    for (int i = 0; i < 2; i++) {
        scanf("%s", twoWords[i]);
    }

    /* Capitalize the first letter of the first word */
    char firstLetter = toupper(twoWords[0][0]);

    /* Generate a random special character */
    char specialChars[] = "!@#$%^&*"; // List of special characters
    srand(time(NULL));
    int randomIndex = rand() % (sizeof(specialChars) - 1);
    char specialChar1 = specialChars[randomIndex];

    /* Reverse the second word */
    char reversedSecondWord[20];
    int len = strlen(twoWords[1]);
    for (int i = 0; i < len; i++) {
        reversedSecondWord[i] = tolower(twoWords[1][len - i - 1]);
    }
    reversedSecondWord[len] = '\0';

      /* Generate a random special character before the number */
    randomIndex = rand() % (sizeof(specialChars) - 1);
    char specialChar2 = specialChars[randomIndex];


    /* Generate a random number between 0 and 9 */
    int randomNumber = rand() % 10;

    /* Create the password */
    snprintf(password, sizeof(password), "%c%c%s%c%d", firstLetter, specialChar1, reversedSecondWord, specialChar2, randomNumber);

    /* Ensure the password length is at least 8 characters */
    while (strlen(password) < 8) {
        int randomDigit = rand() % 10;
        char randomChar = specialChars[rand() % (sizeof(specialChars) - 1)];
        snprintf(password + strlen(password), sizeof(password) - strlen(password), "%c%d", randomChar, randomDigit);
    }

    printf("Generated Password: %s\n", password);

    return 0;
}
