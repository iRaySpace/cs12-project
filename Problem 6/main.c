#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// IMPORTANT:
// WHAT ABOUT INVALID INPUTS
// 1. 9999--0aeo0
// 2. -99999
// FIX IT

// checks if the value of char is
// null or zero in literal '0'
bool is_zero(char a)
{
	if(a == '0' || a == 0)
		return true;

	return false;
}

// move numbers starting point
void move_number(char* string, int max)
{
	int z = 0,
		start = 0;

	// Example:
	// 0123246
	// start: 1
	// because zeroes are counted
	// thereby it is where the loop will start
	while(true) {

		// goes through the zeroes
		// flag the zeroes
		if(is_zero(string[z])) 
			start++;
		if(is_zero(string[z]) && !is_zero(string[z+1]) || !is_zero(string[z]))
			break;

		z++;

	}

	// Example:
	// cycling through 0123246
	// the 0 will then have the value of 1
	// 1 = 2
	// 2 = 3
	// 3 = 2
	// 2 = 4
	// 4 = 6
	// 6 = 0
	// Thus: "123246" is the final value
	for(z = 0; z <= max; z++, start++) {

		if(start > max)
			string[z] = 0;
		else
			string[z] = string[start];

	}
}

void add_value(char* first, char* second, char* result)
{
	// Example:
	// Why?
	// If the input is 00000000100
	// It would put digits up to the first in line
	// Since zeroes aren't significant
	move_number(first, strlen(first));
	move_number(second, strlen(second));

	int x = strlen(first) - 1,
		y = strlen(second) - 1;

	// Remember (offset by one):
	// Why?
	// I assume that everything you've added
	// has a carry
	// Example:
	// 999 = 3 digits
	// 1 = 1 digit
	// If you add them
	// You get 4 digits
	// That's why.
	// What if it is
	// 123 = 3 digits
	// 123 = 3 digits
	// You get 4 digits?
	// Yes. However...
	// '0246' Remember like above.
	// See move_numbers()
	int max = (x > y) ? x + 1 : y + 1;
	int max_two = max;

	// Holds the carry
	int carry = 0;

	for(; max > 0; max--)
	{
		int one, two;

		// Example:
		// From '3' to 3
		// Remember: '3' != 3
		// Also if it is out of bounds
		// It must be zero
		if(x >= 0) one = first[x] - '0';
		else one = 0;

		// Same above
		if(y >= 0) two = second[y] - '0';
		else two = 0;

		x--;
		y--;

		// Example:
		// 3 + 3 + 0 = 6
		int sum = one + two + carry;

		// Example:
		// Since no carry has done based above
		// It will be zero
		// Else
		// 3 + 9 = 12
		// Carry one
		// Then ten from the sum is removed
		carry = (sum >= 10) ? 1 : 0;
		sum %= 10;

		// Example:
		// From 3 to '3'
		result[max] = sum + '0';

	}

	// uncomment this line see if this is really true
	// printf("%d", result[0]);
	// printf("%c\n", result[1]);

	// Passing:
	// result: 0123246
	// max_two: 7
	move_number(result, max_two);
}

int main()
{

	int T = 0,
		x = 0;

	scanf("%d", &T);

	// please counteract negative numbers
	if(T < 1 || T > 200)
		return -1;

	char first[T][50],
		second[T][50],
		result[T][100];

	while(x < T) 
	{
		// setting all of the arrays as empty
		memset(first[x], '\0', sizeof(first[x]));
		memset(second[x], '\0', sizeof(second[x]));
		memset(result[x], '\0', sizeof(result[x]));

		// Example:
		// first: 123123
		// second: 123
		scanf("%s%s", first[x], second[x]);

		// passing:
		// result: NULL
		// first: 123123
		// second: 123
		add_value(first[x], second[x], result[x]);

		x++;
	}

	x = 0;

	while(x < T)
	{
		if(strlen(result[x]) == 0)
			printf("Case #%d: 0", x + 1);
		else
			printf("Case #%d: %s", x + 1, result[x]);

		x++;
	}
	
	getch();
	return 0;
}