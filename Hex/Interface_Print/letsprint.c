#include <stdio.h>

void gameboard(int size, char** table);

void letters(int size);
void polygons(int size, char** table);


void letters(int size){			/* Prints the letter on top or under the game's board */
	if (size == 4)				/* Base-case of the recursion	*/
		printf("      A   B   C   D   ");
	else {
		letters(size-1);		/* Call the function recursively */
		printf("%c   ",size - 1 + 'A');
	}
}

void polygons(int size, char** table){
	int i;

	printf("      ");
	for (i = 1; i <= size ; ++i)
		printf("-   ");	
	printf("\n");

	printf("     ");
	for (i = 1; i <= size; ++i){	
		printf("/ \\");
		if (i != size) 
			printf("_");
	}
	printf("\n");

	char black[6] = "BLACK";
	int count = 2;
	int flag = 666;
	int j,k;
	for (j = 1; j <= size; ++j){
		for (k = 2; k <= j; k++)
			printf("  ");
		if (flag == 666)
			printf(" %2d ",j);
		else {	
			printf("\b%c %2d ",black[flag++],j);
			if (flag == 5)
				flag = 666;
		}
		for (i = 0; i <= size; ++i)
			if (i != size)
				printf("| %c ",table[j-1][i] == 'n' ? ' ' : table[j-1][i]);
			else{
				printf("|   ");
			}
		printf("\b\b\b%2d\n",j);	
		count++;
		if (count == size - 1)
			flag = 0;

		printf("     ");
		for (k = 2; k <= j; k++)
				printf("  ");
		if (flag != 666)
			printf("\b\b\b\b\b%c    ",black[flag++]);
		if (flag == 5)
			flag = 666;

		for (i = 1; i <= size; ++i)
			printf("\\_/ ");
		if (j != size)
			printf("\\\n");
		else 
			printf("\n");

		count++;
		if (count == size - 1)
			flag = 0;
	}
	for (i=0; i <= 2*size + 2 - 5; ++i)
		printf(" ");
}

void gameboard(int size, char** table){  /* Prints the game's board */
	int i;
	printf("      ");
	for (i=1; i <= ((size - 1) * 3 + size - 9) / 2; ++i)
		printf(" ");
	printf("W H I T E\n");
	letters(size);			/* Print the letters on top of the board */
	printf("\n");
	polygons(size,table);	/* Print the hexagon grid */
	letters(size);			/* Print the letters under the board */
	printf("\n");
}
