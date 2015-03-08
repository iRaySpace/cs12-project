// Ivan Ray Altomera
// Aeron John Egar
// Ian Clark Selorico
// BSCS I - CSA
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<math.h>

int main()
{
	int T = 0, // test cases
		it = 0; // iterator

	scanf("%d", &T); // getting the input of teh test cases

	// exits as -1 when bounds are overlapped
	if(T < 1 || T > 100)
		return -1;

	// first number and the second number
	unsigned int a[T];
	unsigned int b[T];

	// list of carry operations
	int carry_op[T];

	for(it; it < T; it++) {

		// getting input as unsigned int
		scanf("%u", &a[it]);
		scanf("%u", &b[it]);

		// initializes all of the carry_op as zero
		carry_op[it] = 0;

	}

	for(it = 0; it < T; it++) {

		// NEEDS IMPROVEMENT HERE!!!!
		// gets the highest possible digits
		int max = (a[it] < b[it]) 
				? (int) log10(b[it]) + 1 
				: (int) log10(a[it]) + 1;

		int min = (a[it] < b[it])
				? (int) log10(a[it]) + 1
				: (int) log10(b[it]) + 1;

		if(a[it] < b[it])
			memset(a, '0', max - min);
		else
			memset(b, '0', max - min);

		// initializes a set of chars or strings
		// for the first and second number
		char first[max];
		char second[max];

		// from unsigned int to string
		sprintf(first, "%u", a[it]);
		sprintf(second, "%u", b[it]);

		// sum and carry temporary storage
		int sum = 0,
			carry = 0;

		// iterator
		int x = 0;

		// iterates over the series of characters
		for(x = max - 1; x >= 0; x--) {

			// gets the sum of selected digit
			sum = (first[x] - '0')
				+ (second[x] - '0')
				+ carry;

			// if sum is more than ten
			// increment the carry_op counter
			if(sum >= 10)
				carry_op[it]++;

			// set the carry temp
			carry = (sum >= 10) ? 1 : 0;

		}

		// tertiary operator to be printed
		(carry_op[it] != 0) ? printf("%d carry operations.\n", carry_op[it])
							: printf("No carry operations.\n");

	}

	getch();
	return 0;
	
}