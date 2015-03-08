// Ivan Ray Altomera
// Aeron John Egar
// Ian Clark Selorico
// BSCS I - CSA
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

	// counts the number of words
	for(; ptr != NULL; i++)
		ptr = strtok(NULL, " ");
	
	return i;
}

int main()
{
	int T = 0,
		x = 0;

	scanf("%d", &T);

	// bounds checker
	if(T < 1 || T > 100)
		return -1;

	// string initialize
	char str[T][255];
	memset(str, 0, sizeof(str));

	while(x < T)
		scanf(" %255[^\n]s", str[x++]);


	for(x = 0; x < T; x++)
	{
		int i = 0; // iteration
		int words = count_words(str[x]); // counts words

		char *iter = strtok(str[x], " "),
			 *main_ptr[words]; // declares main_ptr based on number of words

		while(iter != NULL)
		{
			main_ptr[i++] = iter; // sets main_ptr to point the specific word given by iter
			iter = strtok(NULL, " "); // point another word
		}

		i = words - 1; // offset by one (array)

		// output the results
		printf("Case #%d: ", x + 1);

		while(i >= 0)
			printf("%s ", main_ptr[i--]);

		printf("\n");

	}

	getch();
	return 0;
}