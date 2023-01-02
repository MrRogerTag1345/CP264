/*
-------------------------------------
File:    Lab2.c
Project: Lab 2
file description
-------------------------------------
Author:  Chetas Patel
ID:      200679130
Email:   pate9130@mylaurier.ca
Version  2022-09-24
-------------------------------------
>
 */
/**
 * --------------------------------------------------------
 * Computes the value of r using the four input parameters: w,x,y and z.
 * The value of r is computed according to the equation: 
 * r = log(y) *fabs(w-x)/sqrt(z) + ........................
 * The function returns no value
 * ----------------------------------------------------------
 */
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
void solve2(short w, int x, float y, double z) {
	//your code here
	double r;
	r = ((log(y) * fabs(w - x)) / sqrt(z)) + (pow(M_E, 4) * ceil((y * pow(z, 3)) / x)) - (cbrt(pow(x, y) - y));


	printf("w =       %hd         x =       %d\n", w, x);
	printf("y =       %-5.2f     z =       %-8.4lf\n", y, z);
	printf("r =       %.4lf\n", r);
	return;
}

/**
 * --------------------------------------------------------
 * Generates and returns a random integer.
 * the mode input parameter controls how the random number is generated, as follows:
 * 1-	If mode is �1�: The function generates a random number in the range [0,x1], i.e. inclusive both ends.
 * 2-	If mode is �2�: The function generates a random number in the range (0,x2), i.e. exclusive both ends.
 * 3-	If mode is �i�: The function generates a random number in the range [x1,x2], i.e. inclusive both ends.
 * 4-	If mode is �x�: The function generates a random number in the range (x1,x2), i.e. exclusive both ends.
 * 5-	If mode is �L�: The function generates a random number in the range [x1,x2), i.e. inclusive only from the left which is x1.
 * 6-	If mode is �R�: The function generates a random number in the range (x1,x2], i.e. inclusive only from the right which is x2.
 * 7-	For any other mode value, the function generates a random number between 0 and RAND_MAX.
 * The function is implemented using switch-case statement.
 * Assume that x1 is always less than x2 by at least 2.
 * ----------------------------------------------------------
 */
unsigned int rand_int(unsigned int x1, unsigned int x2, char mode) {
	//your code here
	int result_random;
		switch (mode) {
		case '1':
			result_random = rand() % (x1 + 1);
			break;
		case '2':
			result_random = (rand() % (x2)) + 1;
			break;
		case 'i':
			result_random = (rand() % (x2 - x1 + 1)) + x1;
			break;
		case 'x':
			result_random = (rand() % (x2 - x1 - 1)) + x1 + 1;
			break;
		case 'L':
			result_random = (rand() % (x2 - x1)) + x1;
			break;
		case 'R':
			result_random = (rand() % (x2 - x1)) + x1 + 1;
			break;

		default:
			result_random = (rand() % RAND_MAX) + 1;
		}
		return result_random;
	
	return 0;
}
