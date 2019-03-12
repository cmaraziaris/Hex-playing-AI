
#include "letsswap.h"

void swapme(char** table, char* plet, int* pnum, int rev){	/* Performs the SWAP move */
	char templet = *plet;						
	int tempnum = *pnum;						/* Keep the coordinates of the 1st move */
	char color = 'b';

	if (rev) color = 'w';						/* 'rev' is 1 when we need to undo a swap move */			

	table[*plet - 'A'][*pnum - 1] = color;		/* Make the swap move */
	if ((*plet - 'A') != (*pnum - 1))			/* If the swapped move is different from the 1st move */
		table[*pnum - 1][*plet - 'A'] = 'n';	/* empty the 1st move's hex */
	
	*plet = tempnum + 'A' - 1;					/* Update the move array with the reversed move */
	*pnum = templet - 'A' + 1;
}

int swap_choice(int row, int col, int size){
	if ( ( row == 0 && col == 0) || ( row == (size-1) && col == (size-1) )) return 0; //Do not swap
	else if (( row == 1 && col == 0) || (row == (size - 1) && col == (size - 2) )) return 0; //Do not swap
	else if ( (row == 0 && col == 1) || (row == (size - 2) && col == (size - 1) )) return 0; //Do not swap
	else return 1; // Swap
}
