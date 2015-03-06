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

	while(i < max_first)
	{
		int j = 0; // iterator
		
		bool isExisting = false; // flag for characters that are found on both arrays

		current = tolower(first[i]);

		// checks the second array if the current char
		// exist on both arrays
		// crosses out the second array that has the same char as the current
		while(j < max_second)
		{
			if(current == tolower(second[j])) 
			{
				if(isExisting != true)
					isExisting = true;

				second[j] = '-';
			}

			j++;
		}

		j = 0;

		// if the current char exists on the second array
		// crosses out all the char of the first array
		while(j < max_first && isExisting) 
		{
			if(current == first[j]) 
				first[j] = '-';

			j++;
		}


		i++;
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
	int x = 0,
		i = 0; // iteration

	scanf("%d ", &x);

	char first_person[x][255];
	char second_person[x][255];

	while(i < x)
	{ 
		scanf(" %[^\n]255s", first_person[i]);
		scanf(" %[^\n]255s", second_person[i]);
		i++;
	}

	i = 0;

	while(i < x)
	{
		cross_out_common_letters(first_person[i], second_person[i]);

		int love_value = (count_remaining_letters(first_person[i], second_person[i]) - 1) % 6;

		printf("Case #%d: %s", i + 1, FLAMES[love_value]);

		i++;
	}

	getch();
	return 0;
}