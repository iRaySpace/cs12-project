#include<stdio.h>
#include<conio.h>

int main()
{
	int x = 0,
		tc = 0;

	scanf("%d", &tc);

	if(!(tc >= 1 || tc <= 100))
		return -1;

	unsigned short int days[tc],
					   hours[tc],
					   minutes[tc],
					   seconds[tc];

	while(x < tc) {
		scanf("%hu %hu %hu %hu", &days[x], &hours[x], &minutes[x], &seconds[x]);
		x++;
	}

	x = 0;

	while(x < tc) {
		
		minutes[x] += seconds[x] / 60;
		seconds[x] %= 60;

		hours[x] += minutes[x] / 60;
		minutes[x] %= 60;

		days[x] += hours[x] / 24;
		hours[x] %= 24;

		x++;
	}

	x = 0;

	while(x < tc) {

		printf("Case #%d: ", x + 1);
		
		char last = '\0';

		if(days[x]) last = 'd';
		if(hours[x]) last = 'h';
		if(minutes[x]) last = 'm';
		if(seconds[x]) last = 's';

		(last == 'd' && days[x]) ? printf("%hu days", days[x])
								 : printf("%hu days, ", days[x]);

		(last == 'h' && hours[x]) ? printf("%hu hours", hours[x])
								  : printf("%hu hours, ", hours[x]);

		(last == 'm' && minutes[x]) ? printf("%hu minutes", minutes[x])
								    : printf("%hu minutes, ", minutes[x]);

		if(seconds[x]) printf("%hu seconds", seconds[x]);
		
		if(last == '\0') 
			printf("Not available.");

		printf("\n");

		x++;
	}

	getch();
	return 0;
}