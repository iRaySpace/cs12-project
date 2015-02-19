// Mabuhay ang Na'vi!
#include<stdio.h>
#include<conio.h>
#include<string.h>

int count_words(char *str)
{
	int i = 0;
	
	// Make a copy first
	char copy[255];
	memset(copy, '\0', sizeof(copy)); // setting copy into null
	strcpy(copy, str); // new tricks here <--

	// REMINDER:
	// I made a copy of the str array not because it is somekind of a
	// tricks but strtok really tokenize strings it takes characters
	// piece by piece putting it away if no one holds its address

	// tokenize the copy array
	char *ptr = strtok(copy, " ");

	// NEED to be replace with something char iterator
	// to count spaces
	while(ptr != NULL)
	{
		ptr = strtok(NULL, " ");
		i++;
	}
	
	return i;
}

int main()
{
	int tc = 0,
		x = 0;

	scanf("%d", &tc);

	char str[tc][255];

	while(x < tc)
		scanf(" %255[^\n]s", str[x++]);

	x = 0;

	while(x < tc)
	{
		int i = 0;
		int words = count_words(str[x]); // counts words

		char *iter = strtok(str[x], " "),
			 *main_ptr[words]; // declares main_ptr based on number of words

		while(iter != NULL)
		{
			main_ptr[i++] = iter; // sets main_ptr to point the specific word given by iter
			iter = strtok(NULL, " "); // point another word
		}

		i = words - 1; // offset by one (array)

		// STACKS with backward iteration
		while(i >= 0)
			printf("%s ", main_ptr[i--]);

		printf("\n");

		x++;
	}

	getch();
	return 0;
}