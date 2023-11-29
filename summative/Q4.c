#include <stdio.h>
#include <string.h>

int grades[] = {23, 45, 31, 36, 32, 26, 29, 30, 33, 35, 28,37,19,20};
int n = 14;

void asc(int* arr, int n)
{
	
	int i, j, a;

	for (i = 0; i < n; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			if (grades[i] > grades[j])
			{
				int a = grades[i];
				grades[i] = grades[j];
				grades[j] = a;
			}
		}
	}

	 //printf("The numbers in ascending order are:\n");
	 for (i = 0; i < n; ++i){
		 printf("%d ", grades[i]);
   }
	printf("\n");
}

void desc(int* arr, int n)
{
	int i, j, a;

    
    for (i = 0; i < n; i++) {

        
        for (j = i + 1; j < n; j++) {

            
            if (grades[i] < grades[j]) {
                a = grades[i];
                grades[i] = grades[j];
                grades[j] = a;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        printf("%d ", grades[i]);
    }
    printf("\n");
}

int main()
{
	char ch[4];
    printf("Enter 'asc' for ascending order and 'desc' for descending order: ");
    scanf("%s", ch);

    void (*fun_ptr_arr[])(int*, int) = {asc, desc};

    if (strcmp(ch, "asc") == 0) {
        (*fun_ptr_arr[0])(grades, sizeof(grades) / sizeof(grades[0]));
    } else if (strcmp(ch, "desc") == 0) {
        (*fun_ptr_arr[1])(grades, sizeof(grades) / sizeof(grades[0]));
    } else {
        printf("Invalid input. Please enter 'asc' or 'desc'.\n");
    }

    return 0;
}
