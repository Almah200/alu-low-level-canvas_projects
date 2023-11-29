#include <stdio.h>

// Function to search for a given PIN among the generated and stored PINs
int searchForPin(int targetPin)
{
    int a, b, c, d, e;
    int iterationCount = 0; // Counter for the number of iterations
    int found = 0;          // Flag to indicate whether the target PIN is found

    // Open the file for reading
    FILE *file = fopen("generated_passwords.txt", "r");

    if (file == NULL)
    {
        perror("Error opening file");
        return -1; // Return -1 to indicate an error
    }

    // Iterate through the file to find the target PIN
    while (fscanf(file, "%d %d %d %d %d", &a, &b, &c, &d, &e) == 5)
    {
        // Increment the iteration count
        iterationCount++;

        // Check if the current PIN matches the target PIN
        if (a == targetPin / 10000 &&
            b == (targetPin / 1000) % 10 &&
            c == (targetPin / 100) % 10 &&
            d == (targetPin / 10) % 10 &&
            e == targetPin % 10)
        {
            found = 1; // Set the flag to indicate the PIN is found
            break;
        }
    }

    // Close the file
    fclose(file);

    // Return the number of iterations it took to find the PIN
    if (found)
    {
        printf("PIN found! Iterations: %d\n", iterationCount);
        return iterationCount;
    }
    else
    {
        printf("PIN not found. Iterations: %d\n", iterationCount);
        return -1; // Return -1 to indicate the PIN is not found
    }
}

int main()
{
	int targetPin;
	int iterationCount;

    // Get the target PIN from the user
    printf("Enter the PIN to search for: \n");
    scanf("%d", &targetPin);

    int result = searchForPin(targetPin);

    if (result == -1)
    {
            printf("Error opening file. Exiting.\n");
            return 1;
    }
    else
    {
	    // 100000 is the total number of passwords stored in the generated_passwords
	    double probability = ((double)result / 100000) * 100;
            printf("Password found! Iterations: %d\n", result);
	    printf("Probability of finding %d is %.2f%%\n", targetPin, probability);
            return 1;
    }


    return 0;
}
