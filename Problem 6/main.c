#include<stdio.h>
#include<conio.h>
#include<string.h>

#define MAX 50

void add_value(char* a, char* b)
{
	char c[50] = "\0";

	int x = strlen(a) - 1,
		y = strlen(b) - 1,
		z = 49,
		carry = 0;

	while(x != 0 - 1 && y != 0 - 1)
	{
		int i = a[x] - '0',
			j = b[y] - '0',
			k = i + j + carry;

		if(k > 9) {
			carry = k / 10;
			k -= 9;
		}

		c[z] = k + '0';

		x--;
		y--;
		z--;
	}

	while(x != 0 - 1)
	{
		int i = a[x--] - '0';
		c[z--] = i + '0';
	}

	while(y != 0 - 1)
	{
		int i = b[y--] - '0';
		c[z--] = i + '0';
	}

	z = 0;

	while(z < 50) {

		(c[z] == 0) ? // skip
					: printf("%c", c[z]);
		z++;

	}

}

int main()
{	
	int pair_of_num = 0, x = 0;

	scanf("%d", &pair_of_num);

	char A[pair_of_num][50] = {"\0"};
	char B[pair_of_num][50] = {"\0"};

	while(x < pair_of_num){

		scanf("%s", A[x]);
		scanf("%s", B[x]);

		add_value(A[x], B[x]);

		x++;

	}

	getch();
	return 0;
}