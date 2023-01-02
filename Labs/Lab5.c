/*
 * ---------------------------------
 * Student Name: Chetas Patel
 * Student ID: 200679130
 * Student Email: pate9130@mylaurier.ca
 * ---------------------------------
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void count_letters(const char *filename, int counters[26]);
void write_results(const char *filename, int counters[26]);
void append_sum(const char *filename, int counters[26]);

int main() {
	setbuf(stdout, NULL);

	char filename[20] = "text1.txt";
	int counters[26] = { 0 };

	count_letters(filename, counters);

	filename[4] = '2';
	write_results(filename, counters);

	append_sum(filename, counters);

	printf("Check text2.txt for output\n");

	return 0;
}

void count_letters(const char *filename, int counters[26]) {
	//your code here
	FILE *file = fopen(filename, "r");

	int letterSmall = 97;
	int letterLarge = 65;
	char car;

	if (!file) {
		printf("Error(count_letters): Could not open file %s\n", filename);
		return;
	}

	while((car = fgetc(file)) != EOF) {
		for(int i = 0; i < 26; i++) {
			if(((letterSmall >= 97) && (letterSmall <= 122)) || ((letterLarge >= 65) && (letterLarge <= 90))) {
				if((((int)(car)) == letterSmall) || (((int)(car)) == letterLarge)) {
					counters[i]++;
				}
			}
			letterLarge++;
			letterSmall++;
		}
		letterSmall = 97;
		letterLarge = 65;
	}
	fclose(file);

	return;
}

void write_results(const char *filename, int counters[26]) {
	//your code here
	FILE *file = fopen(filename, "w");
	int letterSmall = 97;

	if(file) {
		for (int i = 0; i < 26; i++) {
			fprintf(file, "count(%c) = %d\n", ((char)(letterSmall)), counters[i]);
			letterSmall++;
		}
	}
	else {
		printf("Error(count_letters): Could not open file %s\n", filename);
	}

	fclose(file);
	return;

}

void append_sum(const char *filename, int counters[26]) {
	//your code here
	FILE * file = fopen(filename, "a");
	int sum = 0;

	if (!file) {
		printf("Error(count_letters): Could not open file %s\n", filename);
		return;
	}

	for(int i = 0; i < 26; i++) {
		sum += counters[i];
	}


	fprintf(file, "Total = %d", sum);
	fclose(file);
	return;
}

