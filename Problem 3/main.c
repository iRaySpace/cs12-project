#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

char FLAMES[6][13] = {

	"Friends",
	"Lovers",
	"Acquaintance",
	"Married",
	"Enemies",
	"Sweethearts"

};

void cross_out_common_letters(char *first, char *second)
{
	int max_first = strlen(first),
		max_second = strlen(second),
		i = 0;

	char current = 0;


	while(i < max_first)
	{
		int j = 0;
		
		bool isExisting = false;

		current = tolower(first[i]);

		while(j < max_second)
		{
			if(current == second[j]) 
			{
				if(isExisting != true)
					isExisting = true;

				second[j] = '-';
			}

			j++;
		}

		j = 0;

		while(j < max_first) 
		{
			if(current == first[j] && isExisting) 
				first[j] = '-';

			j++;
		}


		i++;
	}		
}

int count_remaining_letters(char *first, char *second)
{
	int letters_remaining = 0,
		x = 0;

	while(x < strlen(first))
		if(first[x++] != '-')
			letters_remaining++;

	x = 0;

	while(x < strlen(second))
		if(second[x++] != '-')
			letters_remaining++;

	return letters_remaining;
}

int main()
{
	int x = 0,
		i = 0; // iteration

	scanf("%d ", &x);


	if(!(x >= 1 || x <= 100))
		return -1;

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
		
		int love_value = count_remaining_letters(first_person[i], second_person[i]) % 6;

		printf("Case #%d: %s", i + 1, FLAMES[love_value - 1]);

		i++;
	}

	getch();
	return 0;
}