#include <stdio.h>
#include <string.h>

/* function declaratioj */
void printStudentGrades(char *name, int* grades)
{
    printf("%s: ", name);
    for (int i = 0; i < 10; i++) {
        printf("%d ", grades[i]);
    }
    printf("\n");
}

 int main()
{
	char studentInfo[5][11];
	int studentGrades[5][10];


	/* student 1 */
	strcpy(studentInfo[0], "John");
	studentGrades[0][0] = 10;
	studentGrades[0][1] = 20;
	studentGrades[0][2] = 70;
	studentGrades[0][3] = 85;
	studentGrades[0][4] = 60;
	studentGrades[0][5] = 50;
	studentGrades[0][6] = 55;
	studentGrades[0][7] = 89;
	studentGrades[0][8] = 40;
	studentGrades[0][9] = 90;

	/* student 2 */
	strcpy(studentInfo[1], "Alice");
        studentGrades[1][0] = 25;
        studentGrades[1][1] = 40;
        studentGrades[1][2] = 60;
        studentGrades[1][3] = 55;
        studentGrades[1][4] = 30;
        studentGrades[1][5] = 60;
        studentGrades[1][6] = 75;
        studentGrades[1][7] = 49;
        studentGrades[1][8] = 80;
        studentGrades[1][9] = 100;

      /* student 3 */
	strcpy(studentInfo[2], "Mama");
        studentGrades[2][0] = 35;
        studentGrades[2][1] = 50;
        studentGrades[2][2] = 90;
        studentGrades[2][3] = 0;
        studentGrades[2][4] = 80;
        studentGrades[2][5] = 40;
        studentGrades[2][6] = 65;
        studentGrades[2][7] = 79;
        studentGrades[2][8] = 80;
        studentGrades[2][9] = 50;

	/* student 4 */
	strcpy(studentInfo[3], "Kaka");
        studentGrades[3][0] = 40;
        studentGrades[3][1] = 60;
        studentGrades[3][2] = 80;
        studentGrades[3][3] = 45;
        studentGrades[3][4] = 30;
        studentGrades[3][5] = 60;
        studentGrades[3][6] = 75;
        studentGrades[3][7] = 69;
        studentGrades[3][8] = 70;
        studentGrades[3][9] = 50;

	/* student 5 */
	strcpy(studentInfo[4], "Ngoti");
        studentGrades[4][0] = 56;
        studentGrades[4][1] = 70;
        studentGrades[4][2] = 80;
        studentGrades[4][3] = 95;
        studentGrades[4][4] = 30;
        studentGrades[4][5] = 70;
        studentGrades[4][6] = 25;
        studentGrades[4][7] = 69;
        studentGrades[4][8] = 70;
        studentGrades[4][9] = 90;

	/* Create pointers to the arrays */
	char *namePointers[5];
	int *gradesPointers[5];
	
	for (int student = 0; student < 5; student++) {
		namePointers[student] = studentInfo[student];
		gradesPointers[student] = studentGrades[student];
	}

    /* Now, you can print the student names and their grades using array pointers */
	for (int student = 0; student < 5; student++) {
		
		printStudentGrades(namePointers[student], gradesPointers[student]);
	}
	
	return 0;
}
