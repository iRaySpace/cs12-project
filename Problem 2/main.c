// Ivan Ray Altomera
// Aeron John Egar
// Ian Clark Selorico
// BSCS I - CSA
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

// initializes the mine field
// from "." to "0"
// for easy manipulation of data
void init_mine_field(char* mine_field, int num_of_char)
{
	int i = 0;

	for(; i < num_of_char; i++)
		if(mine_field[i] == '.') 
			mine_field[i] = '0';
}

// checks if mine
bool is_mine(char* x)
{	
	if(*x == '*')
		return true;

	return false;
}

int main()
{
	int n = 0, // number of lines
		m = 0, // number of characters
		x = 0, // iterating purposes
		y = 0; // same as above

	bool valid_input; // used for validation

	scanf("%d%d", &n, &m);

	// bounds checker
	if(n < 1 || n > 100 || m < 1 || m > 100)
		return -1;

	char mine_field[n][m];
	memset(mine_field, 0, sizeof(mine_field));

	// getting the needed data
	for(y = 0; y < n; y++)
		for(x = 0; x < m; x++)
			scanf(" %c", &mine_field[y][x]);

	do {

		valid_input = true; // assumes input is valid

		// checks for any errors
		for(y = 0; y < n; y++)
			for(x = 0; x < m; x++) 
				if(mine_field[y][x] != '.' && mine_field[y][x] != '*')
					valid_input = false;

		if(!valid_input) printf("Not valid. Input again.\n"); // print error

		// input again..
		if(!valid_input)
			for(y = 0; y < n; y++)
				for(x = 0; x < m; x++)
					scanf(" %c", &mine_field[y][x]);

	} while(!valid_input);

	// set all dots to zero for another process
	for(y = 0; y < n; y++)
		init_mine_field(mine_field[y], m);

	for(y = 0; y < n; y++)
	{
		for(x = 0; x < m; x++)
		{
			if(is_mine(&mine_field[y][x]))
			{
				char *top = (y > 0) ? &mine_field[y - 1][x] : NULL,
					 *rig = (x < m - 1) ? &mine_field[y][x + 1] : NULL,
					 *bot = (y < n - 1) ? &mine_field[y + 1][x] : NULL,
					 *lef = (x > 0) ? &mine_field[y][x - 1] : NULL;

				if(top != NULL && !is_mine(top)) (*top)++;
				if(rig != NULL && !is_mine(rig)) (*rig)++;
				if(bot != NULL && !is_mine(bot)) (*bot)++;
				if(lef != NULL && !is_mine(lef)) (*lef)++;

				char *tr = (top != NULL && rig != NULL) ? &mine_field[y - 1][x + 1] : NULL,
					 *br = (bot != NULL && rig != NULL) ? &mine_field[y + 1][x + 1] : NULL,
					 *bl = (bot != NULL && lef != NULL) ? &mine_field[y + 1][x - 1] : NULL,
					 *tl = (top != NULL && lef != NULL) ? &mine_field[y - 1][x - 1] : NULL;

				if(tr != NULL && !is_mine(tr)) (*tr)++;
				if(br != NULL && !is_mine(br)) (*br)++;
				if(bl != NULL && !is_mine(bl)) (*bl)++;
				if(tl != NULL && !is_mine(tl)) (*tl)++;
			}
		}
	}

	// output data
	for(y = 0; y < n; y++) {

		for(x = 0; x < m; x++)
			printf("%c", mine_field[y][x]);

		printf("\n");

	}

	getch();
	return 0;
}