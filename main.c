#include <stdio.h>
#include "employee.h"
#include "heap.h"

#define MAX_EMPLOYEES 5
const char end[3] = "n\n";

int main() {
	struct Employee array[MAX_EMPLOYEES];
	char response[3];
	int i;
	int stop = 0;
	int len;
	char str[50];
	char tempSal[20];

	printf("Enter up to %d employees: \n", MAX_EMPLOYEES);
	for(i = 0; i < MAX_EMPLOYEES; i++) {
		printf("Name: ");
		fgets(str, MAX_NAME_LEN, stdin);
		len = strlen(str);
		if( str[len-1] == '\n' )
    	str[len-1] = 0;
    	strcpy(array[i].name, str);
		printf("Salary: ");
		fgets(tempSal, 20, stdin);
		array[i].salary = atoi(tempSal);


		printf("Enter another user (y/n)? ");
		fgets(response, 3, stdin);
		if (strcmp(response, end) == 0) {
			stop = i+1;
			i = MAX_EMPLOYEES;
		}
		printf("\n");
	}

	
	heapSort(array, stop);

	printList(array, stop);
	return 0;
}
