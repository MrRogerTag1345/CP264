/**
 * -------------------------
 * Student Name: Chetas Patel
 * Student ID: 200679130
 * Student email: pate9130@mylaurier.ca
 * -------------------------
 */

# include <stdio.h>
# include "A3.h"
int checkForRepeate(int *array, int length, int value);

int find_index_array(int* array, const int size, int value){
	//your code here

	if ((array == NULL) || (size <= 0) || (size > MAX_ARRAY_SIZE)) {
		return -1;
	}

	for (int i = 0; i < size; i++) {
		if (array[i] == value) {
			return i;
		}

	}

	return -1;
}

int find_max_index(int* array, const int size){
	int max_value = 0;
	int index;

	if ((array == NULL) || (size <= 0) || (size > MAX_ARRAY_SIZE)) {
		return -1;
	}

	for (int i = 0; i < size; i++) {
	    if  (array[i] > max_value) {
	        max_value = array[i];
	        index = i;
	    }
	}
	return index;
}

short get_array_size(short* array, short* end_ptr){
	//your code here
	short returnSize = 0;
	int found = 0;
	short i = 0;

	if ((array == NULL) || (end_ptr == NULL)) {
	    return 0;
	}


	while(!found) {
	    if (array[i] == *end_ptr) {
	        found = 1;
	    }
	    returnSize++;
	    i++;
	}

	/*
	int length = sizeof(array)/sizeof(array[0]);
    int length2 = sizeof(*end_ptr);
    */
	return returnSize;
}

int* find_mode(int* array, const int size){
	//your code here

	if (array == NULL) {
	    printf("Error(find_mdoe): array is NULL\n");
	    return NULL;
	}
	if ((size > MAX_ARRAY_SIZE) || (size <= 0)) {
	    printf("Error(find_mdoe): invalid size\n");
	    return NULL;
	}

	int resultArray[size];
	int modeArray[size];
	int placeCounter = 0;;
	int count = 0;
	int temp = 0;
	int result;

	for(int i = 0; i < size; i++) {
	    for(int j = 0; j < size; j++) {
	        if (array[i] == array[j]) {
	            count++;
	        }
	    }
	    if (!(checkForRepeate(resultArray, size, array[i]))) {
	        resultArray[placeCounter] = array[i];
	        modeArray[placeCounter] = count;
	        placeCounter++;
	    }
	    count = 0;
	}
    resultArray[placeCounter] = -1;

    for(int i = 0; resultArray[i] != -1; i++) {
        temp++;
    }

	result = find_max_index(modeArray, temp);
	result = resultArray[result];


	for (int k = 0; k < size; k++) {
	    if (array[k] == result) {
	        return &array[k];
	    }
	}
}

int checkForRepeate(int *array, int length, int value) {
    for (int i = 0; i < length; i++) {
        if (array[i] == value) {
            return 1;
        }
    }

    return 0;
}


void update_pointer(double* arr, const int size, double threshold, double ** ptr){
	//your code here
	if (arr == NULL) {
	    printf("Error(update_pointer): array is NULL\n");
	    return;
	}
	else if ((size > MAX_ARRAY_SIZE) || (size <= 0)) {
	    printf("Error(update_pointer): invalid size\n");
	    return;
	}
	else if (ptr == NULL) {
	    printf("Error(update_pointer): invalid ptr\n");
	    return;
	}
	
	
	for (int i = 0; i < size; i++) {
	    if (arr[i] >= threshold) {
	       *ptr = &arr[i];
	    }
	}

	return;
	
}

void find_next(int* array1, int* array2, const int size, int** ptr1){
	//your code here
    if(array1 == NULL || array2 == NULL) {
		printf("Error(find_next): one of the arrays is NULL\n");
	}

	else if((size > MAX_ARRAY_SIZE) || (size <= 0)) {
		printf("Error(find_next): invalid size\n");
	}

	if(ptr1 == NULL) {
		printf("Error(find_next): pointer is NULL");
	}

	int i = 0, j = 0;
	int target = **ptr1;

	for(i; i < size && j < size;) {
		if(array1[i] < array2[j]) {
			if(array1[i] > target) {
				**ptr1 = array1[i];
				return;
			}
			i += 1;
		} 
		else {
			if(array2[j] > target) {
				**ptr1 = array2[j];
				return;
			}
			j += 1;
		}
	}

	for(i; i < size;) {
		if(array1[i] > target) {
			**ptr1 = array1[i];
			return;
		}
		i += 1;
	}

	for(j; j < size;) {
		if(array2[j] > target) {
			**ptr1 = array2[j];
			return;
		}
		j += 1;
	}

	*ptr1 = NULL;
	return;
}
