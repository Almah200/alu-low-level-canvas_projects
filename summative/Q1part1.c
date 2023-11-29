#include <stdio.h>

void generatedPins()
{
        int a, b, c, d, e;
        int pinCounter = 0; // to know the number of generated pins


        FILE *file = fopen("generated_passwords.txt", "w");

        if (file == NULL)
        {
                perror("Error opening file");
                return;
        }


        for (a=0; a<=9; a++)
        {
                for (b=0; b<=9; b++)
                {
                        for (c=0; c<=9; c++)
                        {
                                for (d=0; d<=9; d++)
                                {
                                        for (e=0; e<=9; e++)
                                        {
                                                pinCounter++;

                                                printf("%d %d %d %d %d\n", a, b, c, d, e);

                                                fprintf(file, "%d %d %d %d %d\n", a, b, c, d, e);
                                        }
                                }
                        }
                }
        }

        fclose(file);

        printf("Total number of generated PINS are: %d\n", pinCounter);
}

int main()
{
        generatedPins();

        return 0;
}
