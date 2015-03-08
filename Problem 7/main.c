// Ivan Ray Altomera
// Aeron John Egar
// Ian Clark Selorico
// BSCS I - CSA
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>

// checks if the given col is even
bool is_sum_even_col(char* col, int size)
{
	int x = 0, // iteration
		sum = 0; // summation of all data of indexes

	for(x = 0; x < size; x++)
		sum += col[x];

	if(sum % 2 != 0)
		return false;

	return true;
}

// checks if the given row is even
bool is_sum_even_row(char* row, int size)
{
	int x = 0,
		sum = 0;

	for(x; x < size; x++)
		sum += row[size * x]; // since array is a contiguously storage of data

	if(sum % 2 != 0)
		return false;

	return true;
}

int main()
{
	int T = 0,
		z = 0; // same as above

	scanf("%d", &T);
	
	// bounds
	if(T < 1 || T > 100)
		return -1;

	// sets all isparity as false
	bool isparity[T];
	memset(isparity, 0, sizeof(isparity));

	for(z; z < T; z++) {

		int N = 0,
			x = 0,
			y = 0;

		scanf("%d", &N);

		// if N is greater or equal to one EXIT
		while(N >= 10) {
			printf("Not valid. Input again.");
			scanf("%d", &N);
		}

		// initialize MATRIX
		char matrix[N][N];
		memset(matrix, '\0', sizeof(matrix));

		// assign new boolean
		bool valid_input = false;

		do {

			valid_input = true; // assumes all input is true

			// gets data
			for(y = 0; y < N; y++)
				for(x = 0; x < N; x++)
					scanf("%d", &matrix[y][x]);

			// checks data
			for(y = 0; y < N; y++)
				for(x = 0; x < N; x++)
					if(matrix[y][x] != 0 && matrix[y][x] != 1)
						valid_input = false;

			// remind user
			if(!valid_input) printf("Not valid. Input again.\n");

		} while(!valid_input);

		// assumes that all input is parity
		isparity[z] = true;

		// checks for all columns if even
		for(y = 0; y < N; y++) {

			if(!is_sum_even_col(matrix[y], N))
				isparity[z] = false;

			if(!isparity[z])
				break;

		}

		// checks for all rows if even
		for(x = 0; x < N; x++) {

			char* ptr = &matrix[0][x]; // pointer to the first element based on x

			if(!is_sum_even_row(ptr, N))
				isparity[z] = false;

			if(!isparity[z])
				break;

		}

	}

	for(z = 0; z < T; z++)
	{
		printf("Case #%d: ", z + 1);

		(isparity[z]) ? printf("OK\n")
					  : printf("NOT OK\n");
	}

	getch();
	return 0;

}