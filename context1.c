#include <stdio.h>

/**
 *
 *
 *
 */
int main() {
	char firstnames[10][15] = {"Almarat", "John", "Dennis", "Vianney", "Tahlil", "Kodio", "kodi", "Rammy", "Hassan", "Amin"};
	char lastnames[10][15] = {"Ngutulu", "Ndugu", "Lorot", "Mmpita", "Mohamed", "Ahmed", "Arnu", "Hessen", "Sukar", "Bolis"};
	float Gsalaries[10] = {500, 80, 150, 200, 50, 600, 100, 1000, 300, 90};
	float Nsalaries[10];

    for (int a = 0; a < 10; ++a) {
        if (Gsalaries[a] <= 100) {
            Nsalaries[a] = (Gsalaries[a] * 0.95);
        } else if (100 < Gsalaries[a] && Gsalaries[a] <= 400) {
            Nsalaries[a] = (Gsalaries[a] * 0.75);
        } else {
            Nsalaries[a] = (Gsalaries[a] * 0.67);
        }
    }

    for (int i = 0; i < 10; ++i) {
        printf("%s %s, Gross Salary: %.1f, Net Salary: %.1f\n", firstnames[i], lastnames[i], Gsalaries[i], Nsalaries[i]);
	    }

    return 0;
}
