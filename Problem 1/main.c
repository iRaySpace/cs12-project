// Ivan Ray Altomera
// Aeron John Egar
// Ian Clark Selorico
// BSCS I - CSA
#include<stdio.h>
#include<conio.h>

// defining constants
#define START 1
#define TEMP 2
#define END 3


// tower of hanoi function
// n : number of disks
// first : starting point of the disks
// last : destination point of the disks
// temp : temporary area for disks
void tower_of_hanoi(int n, int first, int last, int temp)
{
	// to stop recursions
	if(n > 0) {
		// idea:
		// move n - 1 disk from a to b using c
		// move last disk from a to c
		// move n - 1 disk from b to c using a
		tower_of_hanoi(n - 1, first, temp, last);
		printf("%d --> %d\n", first, last); //
		tower_of_hanoi(n - 1, temp, last, first);
	}
}

int main()
{
	int T = 0;
	scanf("%d", &T);

	// execute tower_of_hanoi
	tower_of_hanoi(T, START, END, TEMP);

	getch();
	return 0;
}