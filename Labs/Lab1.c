/**
 -------------------------
 Student Name: Chetas
 Student ID: 200671930
 Student email: pate9130@mylaurier.ca
 -------------------------
 **/
#include <stdio.h>
#include <limits.h>
void t1();
void t2();
void t3();

int main() {

	//setbuf(stdout, NULL);
	t1();
	printf("\n");
	t2();
	printf("\n");
	t3();
	return 0;
}

void t1() {
	int tall, small;
	char symbol = 84;
	double total;
	const int VAL = 43;

	printf("Enter number of tall trees: ");
	scanf("%d", &tall);

	printf("Enter number of short trees: ");
	scanf("%d", &small);

	total = tall + small;

	//Printing Prompt
	printf("Number of %c trees = %d\n", symbol, tall);
	printf("Number of %c trees = %d\n",(symbol-1),small);
	printf("Average height = %.2lf", (VAL / total));
	return;
}


void t2(){
	unsigned int year;
	short month;
	int day;
	char university[30];
	
	// your code here
	printf("Enter the year: ");
	scanf("%u", &year);

	printf("Enter month: ");
	scanf("%hi", &month);

	printf("Enter day: ");
	scanf("%d", &day);

	printf("Enter University: ");
	scanf("%s", university);

	printf("This is %s\n", university);
	printf("Today is : %d/%hi/%u", day, month, year);
	return;
}


void t3(){
	//your code here
	printf("Hints for C Language:");
	printf("Insert  \n  at  end  of  printf  for  newline.");
	printf("Use \"double quote\" not 'single quotes' for strings. ");
	printf("Use %%d for integer, %%f for float and %%lf for double.\n");

	return;
}

