#include <stdio.h>

/* function declaration */
int sumArray(int *arr, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int main ()
{
	int myResults[]={40, 60, 70, 90, 56, 30, 20, 80, 75, 49};
	int arraySize = sizeof(myResults) / sizeof(myResults[0]);

	int results = sumArray(myResults, arraySize);

	printf("%d\n", results);

	return 0;
}
