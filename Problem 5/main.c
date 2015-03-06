#include<stdio.h>
#include<conio.h>

int main()
{
	int i = 0,
		tc = 0;

	scanf("%d", &tc);
	
	unsigned int first_num[tc];
	unsigned int second_num[tc];

	// getting the input
	for(i; i < tc; i++)
		scanf("%x%x", &first_num[i], &second_num[i]); // getting the hexadecimal

	for(i = 0; i < tc; i++)
	{
		// adding the two numbers
		unsigned int result = first_num[i] + second_num[i];

		// printing with hexadecimal notation
		printf("Case #%d: %x\n", i + 1, result);

	}

	getch();
	return 0;
}