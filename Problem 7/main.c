#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

#define MAX 10

int main()
{
	int s = 0, // size for the boolean matrix
		x = 0, 
		y = 0; // used for iterating purposes

	bool is_parity = true; // assuming it is already parity

	scanf("%d", &s);
	// needed to implement
	// getting integer limited to 10 as max size

	int b_matrix[s][s] = {0};

	// getting the input from user
	// 1s and 0s
	for(y = 0; y < s; y++)
		for(x = 0; x < s; x++)
			scanf("%d", &b_matrix[y][x]);

	for(y = 0; y < s; y++)
	{
		// if is parity
		// get out of the loop
		if(!is_parity)
			break;

		int row_sum = 0,
			col_sum = 0;

		// sums up the row and columns
		for(x = 0; x < s; x++) {
			row_sum += b_matrix[y][x];
			col_sum += b_matrix[x][y];
		}

		// if it is not an even
		// it is not parity
		if(row_sum % 2 != 0 || col_sum % 2 != 0)
			is_parity = false;
	}

	// simplified if statement
	// by using ternary operator
	(is_parity) ? printf("OK")
				: printf("NOT OK"); 

	getch();
	return 0;
}