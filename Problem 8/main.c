#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<string.h>

int main()
{	
	int test = 0, x = 0;

	printf("Number of test cases: ");
	scanf("%d", &test);

	char name[test][255] = {'\0'};

	// need to fix: 
	// not exceed 255 characters -- fixed (data will be truncated)

	while(x < test) 
		scanf("%255s", name[x++]);

	x = 0;

	while(x < test) {

		int y = 0;
		bool is_valid = false;

		while(y < strlen(name[x]))
		{
			is_valid = true; // predicts output is already valid

			// if the beginning of the
			// char of the string is
			// a digit exits false

			// else if the current length
			// of the string is more than
			// 20, exits false
			if(y == 0) {

				switch(name[x][y]) {
					case '0': case '2':
					case '4': case '6':
					case '8':
						is_valid = false;
				}

			} else if(y > 20) {

				is_valid = false;

			}

			// exits the loop
			if(!is_valid)
				break;

			// a simple hack
			// for a non-english alphabet
			is_valid = false;

			switch(name[x][y])
			{
				case '0': case '2':
				case '4': case '6':
				case '8': case '#':
				case '_': case 'a' ... 'z' :
					is_valid = true;
			}

			y++;
		}

		if(is_valid) printf("Case #%d: VALID\n", x);
		else 		 printf("Case #%d: NOT VALID\n", x);

		x++;
	}

	getch();
	return 0;

}