#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

void init_mine_field(char* mine_field, int num_of_char)
{
	int i = 0;

	for(; i < num_of_char; i++)
		if(mine_field[i] == '.') 
			mine_field[i] = '0';
}

bool within_bounds(int min, int max, int num)
{
	if(num < min || num > max - 1)
		return false;

	return true;
}

bool is_mine(char x)
{
	if(x == '*')
		return true;

	return false;
}

int main()
{
	int n = 0, // number of lines
		m = 0, // number of characters
		x = 0, // iterating purposes
		y = 0; // same as above

	scanf("%d%d", &n, &m);

	char mine_field[n][m];

	// initialize all the mind_field array to nul
	for(y = 0; y < n; y++)
		memset(mine_field[n], '\0', sizeof(mine_field[n]));

	// getting the needed data
	for(y = 0; y < n; y++)
		for(x = 0; x < m; x++)
			scanf(" %c", &mine_field[y][x]);

	// set all dots to zero for another process
	for(y = 0; y < n; y++)
		init_mine_field(mine_field[y], m);

	for(y = 0; y < n; y++)
	{
		for(x = 0; x < m; x++)
		{
			if(mine_field[y][x] == '*')
			{
				// coordinates
				int top = y - 1;
				int bot = y + 1;
				int lef = x - 1;
				int rig = x + 1;

				int temp = 0; // used for converting int to char and likewise

				// verticals and horizontals

				if(within_bounds(0, n, top) && !is_mine(mine_field[top][x])) {
					temp = (mine_field[top][x] - '0') + 1;
					mine_field[top][x] = temp + '0';
				}

				if(within_bounds(0, n, bot) && !is_mine(mine_field[bot][x])) {
					temp = (mine_field[bot][x] - '0') + 1;
					mine_field[bot][x] = temp + '0';
				}

				if(within_bounds(0, m, lef) && !is_mine(mine_field[y][lef])) {
					temp = (mine_field[y][lef] - '0') + 1;
					mine_field[y][lef] = temp + '0';
				}

				if(within_bounds(0, m, rig) && !is_mine(mine_field[y][rig])) {
					temp = (mine_field[y][rig] - '0') + 1;
					mine_field[y][rig] = temp + '0';
				}

				// diagonals

				if(within_bounds(0, n, top) && within_bounds(0, m, lef) && !is_mine(mine_field[top][lef])) {
					temp = (mine_field[top][lef] - '0') + 1;
					mine_field[top][lef] = temp + '0';
				}

				if(within_bounds(0, n, bot) && within_bounds(0, m, rig) && !is_mine(mine_field[bot][rig])) {
					temp = (mine_field[bot][rig] - '0') + 1;
					mine_field[bot][rig] = temp + '0';
				}
				
				if(within_bounds(0, n, bot) && within_bounds(0, m, lef) && !is_mine(mine_field[bot][lef])) {
					temp = (mine_field[bot][lef] - '0') + 1;
					mine_field[bot][lef] = temp + '0';
				}

				if(within_bounds(0, n, top) && within_bounds(0, m, rig) && !is_mine(mine_field[top][rig])) {
					temp = (mine_field[top][rig] - '0') + 1;
					mine_field[top][rig] = temp + '0';
				}
			}
		}
	}

	for(y = 0; y < n; y++) {

		for(x = 0; x < m; x++)
			printf("%c", mine_field[y][x]);

		printf("\n");

	}

	getch();
	return 0;
}