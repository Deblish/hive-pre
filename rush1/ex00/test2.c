#include <unistd.h>
#include <stdio.h> //remove this
#include <stdlib.h>

void matrix_filler(int **matrix, int size, int value)
{
	int i;
	int j;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			matrix[i][j] = value;
			j++;
		}
		i++;
	}
}
void matrix_printer(int **matrix, int size)
{
	int i;
	int j;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			//matrix[i][j]; //write
			printf("%i ", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
int eye(int *rowhouse, int size)
{
	int counter = 0;
	int tallest = 0;
	int *house = rowhouse;
	
	while(house - rowhouse < size)
	{
		if (*house > tallest)
		{
			tallest = *house;
			counter++;
		}
		house++;
	}
	return counter;
}
int constraints(int **matrix, int size, int row, int col, int value, int *views)
{
	//matrix_printer(matrix, size);
	//duplicates?
	int i;
	i = 0;
	while (i < size)
	{
		//value is already placed
		if ((matrix[row][i] == value) || (matrix[i][col] == value))
			return 0;
		i++;
	}
	
	//lets try the value in the position
	int original = matrix[row][col];
	matrix[row][col] = value;
	//lets create temporal arrays to verify with our eye
	int R[size];
	int C[size];
	i = 0;
	while (i < size)
	{
		R[i] = matrix[row][i];
		C[i] = matrix[i][col];
		i++;
	}
	
	//int views[16] = {4,3,2,1,1,2,2,2,4,3,2,1,1,2,2,2};
	//lets see
	int valid = 1;
	//top
	if (row == 0)
		valid = valid && (eye(C, size) <= views[col]);
	//down
	if (row == size - 1)
		valid = valid && (eye(C, size) <= views[size + col]);
	//left
	if (col == 0)
		valid = valid && (eye(R, size) <= views[2 * size + row]);
	//right
	if (col == size - 1)
		valid = valid && (eye(R, size) <= views[3 * size + row]);
	//thanks for visiting, here's your old value
	matrix[row][col] = original;

	return valid;
}
int backtracker(int **matrix, int size, int row, int col, int *views)
{
	//printing
	//matrix_printer(matrix, size);
	//you reached the end of this column, go to the next one
	if (col == size)
	{
		col = 0;
		row++;
	}
	//you finished the matrix
	if (row == size)
		return (1); //getting out of the matrix :o
	//skip filled cells
	if (matrix[row][col] != 0)
		return backtracker(matrix, size, row, col + 1, views);
	int value;
	value = 0;
	while (value <= size)
	{
		//is this value valid man?
		if (constraints(matrix, size, row, col, value, views))
		{
			matrix[row][col] = value;
			//oh sh*t here we go again
			if (backtracker(matrix, size, row, col + 1, views))
				//you did it, you crazy son of a b*tch, you did it
				return (1);
			//not a solution
			matrix[row][col] = 0; //changed
		}
		value++;
	}
	//we tried every value and failed, go back dud, this path is dead
	return (0);
}
int main()
{
	//char *views_string;
	//up[], down[], left[], right[]
	//views_string = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	int views[16] = {4,3,2,1,1,2,2,2,4,3,2,1,1,2,2,2};
	//int views[25] = {2,2,4,1,3,4,2,2,3,1,2,1,2,3,3,2,3,4,2,1};
	//int views[25] = {2,2,4,1,3,4,2,2,3,1,2,1,2,3,3,2,3,4,2,1};
	int size = 4;
	int value = 0;
	//int matrix[size][size];
	int **matrix;
	matrix = malloc(size * sizeof(int *));
	
	int i;
	i = 0;
	while (i < size)
	{
		matrix[i] = malloc(size * sizeof(int));
		i++;
	}
	matrix_filler(matrix, size, value);
	if (backtracker(matrix, size, 0, 0, views))
		//solution found, print it
		matrix_printer(matrix, size);
	else
		//printf("no solution for this\n");
		matrix_printer(matrix, size);
	return (0);
}
