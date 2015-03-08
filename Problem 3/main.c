// Ivan Ray Altomera
// Aeron John Egar
// Ian Clark Selorico
// BSCS I - CSA
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

// FLAMES array
// corresponds with the iterator
char FLAMES[6][13] = {

	"Friends",
	"Lovers",
	"Acquaintance",
	"Married",
	"Enemies",
	"Sweethearts"

};

// cross_out_common_letters
// making an existing char to be '-'
// especially to those who are found to be
// repeated in both arrays
void cross_out_common_letters(char *first, char *second)
{
	int max_first = strlen(first),
		max_second = strlen(second),
		i = 0; // iterator

	// holds the current character
	char current = 0;

	for(; i < max_first; i++)
	{
		int j = 0; // iterator
		
		bool isExisting = false; // flag for characters that are found on both arrays

		current = tolower(first[i]);

		// checks the second array if the current char
		// exist on both arrays
		// crosses out the second array that has the same char as the current
		for(; j < max_second; j++)
		{
			if(current == tolower(second[j])) 
			{
				if(isExisting != true)
					isExisting = true;

				second[j] = '-';
			}
		}

		// if the current char exists on the second array
		// crosses out all the char of the first array
		for(j = 0; j < max_first && isExisting; j++)
			if(current == first[j]) 
				first[j] = '-';

	}		
}

// counts the number of letters
// by counting all not dash '-' characters
int count_remaining_letters(char *first, char *second)
{
	int letters_remaining = 0,
		x = 0; // iterator purposes

	for(x; x < strlen(first); x++)
		if(first[x] != '-' && !isspace(first[x]))
			letters_remaining++;

	for(x = 0; x < strlen(second); x++)
		if(second[x] != '-' && !isspace(second[x]))
			letters_remaining++;

	return letters_remaining;
}

int main()
{
	int T = 0,
		i = 0; // iteration

	scanf("%d ", &T);

	// bounds
	if(T < 1 || T > 100)
		return -1;

	// person arrays
	char first_person[T][255];
	char second_person[T][255];

	// initialize array
	memset(first_person, 0, sizeof(first_person));
	memset(second_person, 0, sizeof(second_person));

	// get input
	for(i = 0; i < T; i++)
	{ 
		scanf(" %[^\n]255s", first_person[i]);
		scanf(" %[^\n]255s", second_person[i]);
	}

	// iterate
	for(i = 0; i < T; i++)
	{
		// (literally) crosses out common letters
		cross_out_common_letters(first_person[i], second_person[i]); 

		int remaining = count_remaining_letters(first_person[i], second_person[i]);
		int love_value = (remaining - 1) % 6; // offset of one

		printf("Case #%d: %s\n", i + 1, FLAMES[love_value]);
	}

	getch();
	return 0;
}