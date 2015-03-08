// Ivan Ray Altomera
// Aeron John Egar
// Ian Clark Selorico
// BSCS I - CSA
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>

// making a structure for time
typedef struct {

	unsigned int days;
	unsigned int hours;
	unsigned int minutes;
	unsigned int seconds;

} time;

int main()
{
	int T = 0,
		x = 0;

	scanf("%d", &T);

	// bounds checker
	if(T < 1 || T > 100)
		return -1;

	// initialize data
	time INPUT[T];
	memset(INPUT, 0, sizeof(INPUT));

	// input data
	for(; x < T; x++)
		scanf("%u%u%u%u", &INPUT[x].days, &INPUT[x].hours, &INPUT[x].minutes, &INPUT[x].seconds);

	// process data
	for(x = 0; x < T; x++)
	{
		// seconds to minutes
		INPUT[x].minutes += INPUT[x].seconds / 60;
		INPUT[x].seconds %= 60;

		// minutes to hours
		INPUT[x].hours += INPUT[x].minutes / 60;
		INPUT[x].minutes %= 60;

		// hours to days
		INPUT[x].days += INPUT[x].hours / 24;
		INPUT[x].hours %= 24;
	}

	// output data
	for(x = 0; x < T; x++)
	{
		// flagger
		char last = '0';

		if(INPUT[x].days != 0) last = 'd';
		if(INPUT[x].hours != 0) last = 'h';
		if(INPUT[x].minutes != 0) last = 'm';
		if(INPUT[x].seconds != 0) last = 's';

		// output begins here
		printf("Case #%d: ", x + 1);

		// days
		if(INPUT[x].days != 0) { 

			printf("%u days", INPUT[x].days);

			if(last != 'd') 
				printf(", ");

		}

		// hours
		if(INPUT[x].hours != 0)	{

			printf("%u hours", INPUT[x].hours);

			if(last != 'h') 
				printf(", ");

		}

		// minutes
		if(INPUT[x].minutes != 0) {

			printf("%u minutes", INPUT[x].minutes);

			if(last != 'm') 
				printf(", ");

		}

		// since seconds is the last element for this program
		if(INPUT[x].seconds != 0) printf("%u seconds", INPUT[x].seconds);

		// if input is null
		if(last == '0')	printf("Not available.");

		printf("\n");
	}

	getch();
	return 0;
}