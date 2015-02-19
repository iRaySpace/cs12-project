#include<stdio.h>
#include<conio.h>

// improvise?
void tower_of_hanoi(int n, int first, int last, int temp)
{
	if(n > 0) {

		tower_of_hanoi(n - 1, first, temp, last);
		printf("%d --> %d\n", first, last);
		tower_of_hanoi(n - 1, temp, last, first);

	}
}

int main()
{
	int num = 0;
	scanf("%d", &num);

	tower_of_hanoi(num, 1, 3, 2);

	getch();
	return 0;
}