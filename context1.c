#include <stdio.h>

/**
 *
 *
 *
 */
int main() {
    char firstnames[10][15] = {"Almarat", "John", "Dennis", "Vianney", "Tahlil", "Kodio", "kodi", "Rammy", "Hassan", "Amin"};
    char lastnames[10][15] = {"Ngutulu", "Ndugu", "Lorot", "Mmpita", "Mohamed", "Ahmed", "Arnu", "Hessen", "Sukar", "Bolis"};
    int Gsalaries[10] = {500, 80, 150, 200, 50, 600, 100, 1000, 300, 90};
    int Nsalaries[10];

    for (int a = 0; a < 10; ++a) {
        if (Gsalaries[a] < 100) {
            Nsalaries[a] = Gsalaries[a] - (0.3 * Gsalaries[a] * 0.2);
        } else if (100 < Gsalaries[a] && Gsalaries[a] <= 400) {
            Nsalaries[a] = Gsalaries[a] - (0.2 * Gsalaries[a] * 0.3);
        } else {
            Nsalaries[a] = Gsalaries[a] - (0.28 * Gsalaries[a] * 0.3);
        }
    }

    for (int i = 0; i < 10; ++i) {
        printf("%s %s,Net Salary: %d\n", firstnames[i], lastnames[i], Nsalaries[i]);
    }

    return 0;
}
