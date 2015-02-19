#include<stdio.h>
#include<conio.h>
#include<math.h>

// convert it into test cases
int main()
{
	unsigned int a = 555;
	unsigned int b = 555;

	int i = 0;

	int num = 0;
	int carry = 0;

	num = (a < b) ? (int) log10(b) + 1 : (int) log10(a) + 1;

	char first[num];
	char second[num];

	sprintf(first, "%u", a);
	sprintf(second, "%u", b);

	int temp, temp2 = 0;

	for(int i = num - 1; i >= 0; i--)
	{

		temp = (first[i] - '0')
			 + (second[i] - '0')
			 + temp2;

		if(temp >= 10)
			carry++;

		temp2 = (temp >= 10) ? 1 : 0;

	}

	printf("%d", carry);

	getch();
	return 0;
}