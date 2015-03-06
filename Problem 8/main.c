#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>

#define MAX_LENGTH 20

// checks if the string is
// within the MAX_LENGTH
bool is_within_length(char* string)
{
	if(strlen(string) > MAX_LENGTH)
		return false;

	return true;
}

// checks if the first character
// of the string is a digit
bool begins_with_digit(char* string)
{
	if(isdigit(string[0]))
		return true;

	return false;
}

// checks if the string has only
// selected characters:
// the English letters
// odd numbers
// (#) number sign
// (_) underscore
bool has_only_selected_chars(char* string)
{
	int x;

	for(x = 0; x < strlen(string); x++)
	{
		switch(string[x])
		{
			case 'a' ... 'z':
			case 'A' ... 'Z':
			case '0': case '2': 
			case '4': case '6':
			case '8': case '#':
			case '_': break;
			default:  return false; // skips everything if found that is not included
		}
	}

	return true; // if no fail return true
}

int main()
{
	int T = 0, // test cases
		x = 0; // iterator

	scanf("%d", &T); // inputs

	if(T < 1 || T > 100) // check bounds
		return -1;

	// initializing an identifiers array
	// by setting it as all NULL
	char identifiers[T][255];
	memset(identifiers, '\0', sizeof(identifiers));

	// gets input from the user
	for(x; x < T; x++)
		scanf("%255s", identifiers[x]);

	for(x = 0; x < T; x++)
	{
		// assumes all the input is VALID
		bool is_valid = true;

		// checks the length
		if(!is_within_length(identifiers[x]))
			is_valid = false;

		// check if it begins with a digit
		if(begins_with_digit(identifiers[x]))
			is_valid = false;

		// checks if it has only selected characters
		if(!has_only_selected_chars(identifiers[x]))
			is_valid = false;

		printf("Case #%d: ", x + 1);

		(is_valid) ? printf("VALID\n")
				   : printf("NOT VALID\n");
	}

	getch();
	return 0;
}