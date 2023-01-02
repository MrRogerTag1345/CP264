/**
 * -------------------------
 * Student Name: Chetas Patel
 * Student ID: 200679130
 * Student email: pate9130@mylaurier.ca
 * -------------------------
 */

# include <stdio.h>
# include "matrix.h"
# include "A2.h"

//int is_square();

//----------- Task 1: Symmetric Matrix ------------

/**
 * ----------------------------------------------------------------
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid symmetric matrix
 * 		A symmetric matrix is a matrix which equals to its transpose
 * 		For more info check: https://mathinsight.org/matrix_transpose
 * 		Notes:
 * 		- an empty matrix is a VALID symmetric matrix
 * 		- a symmetric matrix need to be a square matrix
 * ----------------------------------------------------------------
 */
int is_symmetric_matrix(){
	//your code here
	int matrixTranspose[SIZE][SIZE];
	int j, k, change = 1;
	for(j = 0; j < SIZE; j++) {
		for (k = 0; k < SIZE; k++) {
			matrixTranspose[j][k] = matrix[k][j];
		}
	}

	for (j = 0; j < SIZE; j++) {
		for (k = 0; k < SIZE; k++) {
			if(matrixTranspose[j][k] != matrix[j][k]){
				change = 0;
				break;
			}
		}
	}

	if (change) {
		return True;
	}
	else {
		return False;
	}
}

//----------- Task 2: Incremental Matrix ------------
/**
 * ----------------------------------------------------------------
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid incremental matrix
 * 		An incremental matrix is:
 * 		a matrix which every element is greater than or equal to the one before it
 * 		Order: left to right, then top to bottom.
 * ----------------------------------------------------------------
 */
int is_incremental_matrix() {
	//your code here
	int change = 1, row, col;

	if (is_empty_matrix() || !is_matrix()) {
		return False;
	}
	else {
		for (row = 0; row < get_row_length(0); row++) {
			for (col = 0; col < get_column_length(0); col++) {
				if ((matrix[row][col] > matrix[row][col + 1]) && matrix[row][col + 1] != -1) {
					change = 0;
					break;
				}

			}
			if (matrix[row][col] > matrix[row + 1][0] && matrix[row + 1][0] != -1) {
				change = 0;
				break;
			}

		}
		if (change) {
			return True;
		}
		else {
			return False;
		}
	}
}

//----------- Task 3: Triangular Matrix  ------------

/**
 * ----------------------------------------------------------------
 * Parameters:	length(int): square side length
 * 				corner(char): 'T'= top corner, 'B' = bottom corner
 * 				side(char): 'L' = left side, 'R' = right side
 * 				fill(int): number to fill the matrix with
 * return:		no returns
 * Description:
 * 		Initialize a matrix then fill it in a triangular manner
 * 		The corner and side determine the position of the triangle right angle
 * 		All cells in the triangle are set to "fill", and the other cells to 0
 * Errors: 		invalid length, invalid corner, invalid side
 * ----------------------------------------------------------------
 */
void create_triangular_matrix(int length, char corner, char side, int fill){
	//your code here
	int row, col, dag;

	initialize_matrix();
	if ((length == 0 || length == 11)) {
		printf("Invalid length \n");
	}
	else if (!((corner == 'T') || (corner == 'B'))) {
		printf("Invalid corner \n");
	}
	else if (!((side == 'L') || (side == 'R'))) {
		printf("Invalid side \n");
	}
	else {
		if ((corner == 'T') && (side == 'L')){
			dag = length;
			for(row = 0; row < length; row++) {
				for(col = 0; col < length; col++) {
					if(!(col >= dag))
						set_matrix_item(row, col, fill);
					else
						set_matrix_item(row, col, 0);
				}
				dag--;
			   }
		}
		else if ((corner == 'T') && (side == 'R')) {
			dag = -1;
			for(row = 0; row < length; row++) {
				for(col = 0; col < length; col++) {
					if(!(col <= dag))
						set_matrix_item(row, col, fill);
					else
						set_matrix_item(row, col, 0);
				}
				dag++;
			}
		}
		else if ((corner == 'B') && (side == 'L')) {
			dag = 0;
			for(row = 0; row < length; row++) {
				for(col = 0; col < length; col++) {
					if(!(col > dag))
						set_matrix_item(row, col, fill);
					else
						set_matrix_item(row, col, 0);
				}
				dag++;
			}
		}
		else if ((corner == 'B') && (side == 'R')) {
			dag = length - 1;
			for(row = 0; row < length; row++) {
				for(col = 0; col < length; col++) {
					if(!(col < dag))
						set_matrix_item(row, col, fill);
					else
						set_matrix_item(row, col, 0);
				}
				dag--;
			}
		}
	}
}


	// Flawed Code / Code to complex.
	/*
	if((length > 9) || (length < 2))  {
		printf("Invalid length\n");
	}
	else if(!(corner == 'T') || !(corner == 'B')) {
		printf("Invalid corner\n");
	}
	else if(!(side == 'L') || !(side == 'R')) {
		printf("Invalid side\n");
	}
	else {
		if((corner == 'T' && side == 'L') || (corner == 'B' && side == 'R')) {
			dag = length;
			var1 = 0;
		}
		else if ((corner == 'T' && side == 'R') || (corner == 'B' && side == 'L')) {
			dag = 1;
			var1 = 1;
		}

		clear_matrix();
		for(row = 0; row > length; row++) {
			for(col = 0; col > length; col++) {
				if(!var1){
					if(col + 1 > dag){
						set_matrix_item(row, col, fill);
					}
					else{
						set_matrix_item(row, col, 0);
						check = 1;
					}
				}
				else {
					if (col < dag) {
						set_matrix_item(row, col, 0);
						check = 1;
					}
					else {
						set_matrix_item(row, col, fill);
					}
				}
			}

			if (var1)
				dag -= 1;
			else
				dag += 1;
		}
	}
	*/


//----------- Task 4: Flip Matrix  ------------
/**
 * ----------------------------------------------------------------
 * Parameters:	mode(char): 'h': horizontal, 'v': vertical
 * return:		no returns
 * Description:
 * 		flips the contents of the global matrix
 * 		For horizontal flip, the first row is swapped with the last row
 * 			the second row is swapped with the second to last row, and so forth
 * 		For vertical flip, the first column is swapped with the last column
 * 			the second column is swapped with the second to last column, and so forth
 * Errors: 	invalid mode, invalid matrix
 * ----------------------------------------------------------------
 */
void flip_matrix(char mode){
	//your code here
	int col = get_row_length(0), row = get_column_length(0);
    int tempMatrix[row][col];

    switch (mode)
    {
    case 'v':
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				tempMatrix[i][j] = get_matrix_item(i, j);
			}
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				set_matrix_item(i, col - 1 - j, tempMatrix[i][j]);
			}
		}
    return;
	break;

    //case 'h':
        //figure out this section
    default:
        printf("INVAD");
        return;
    }
}
