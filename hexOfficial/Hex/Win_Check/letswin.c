#include <stdio.h>

#include "./List_functions/lists.h"
#include "letswin.h"

int won(char color,char** table,int size,int num, int let,int danger, int special){		/* Finds if the 'color' player has won the game, starting from a specific hex */
	int sum = 0;																		/* Returns 0 if there's no winner, 1 if White has won, 2 if Black has won	  */
	if (color == 'w'){											
		if (num >=0 && num <size && let >=0 && let < size){			/* Are the coordinates valid? */
			if (table[num][let] == 'w'){							
				if (num == size - 1)	{							/* Check if we reached the last row, meaning white has won */			
					return 1;			
				}
				sum = won(color,table,size,num + 1,let,0,special);					/* Check if the lower-right hex leads to a win */
				if (sum && special) list = ins_at_start(list,let,num + 1);			/* If a winner is found & we want to print the path, save the current hex */
				if (!sum){															/* If no winning path is found */
					sum  = won(color,table,size,num + 1,let-1,0,special);	 		/* Check if the lower-left hex leads to a win */
					if (sum && special) list = ins_at_start(list,let - 1,num + 1);	
				}
				if (num != 0){								     /* Ignore left and right hexes of a 1st row hex, since they're checked from the calling function */
					if (!sum && danger != 1) {										/* If no winning path is found and the previous hex we checked wasn't the left one */
						sum = won(color,table,size,num,let-1,-1,special);			/* Check if the left hex leads to a win */
						if (sum && special) list = ins_at_start(list,let-1,num);	
					}
					if (!sum && danger != -1){										/* If no winning path is found and the previous hex we checked wasn't the right one */
						sum = won(color,table,size,num,let+1,1,special);			/* Check if the right hex leads to a win */
						if (sum && special) list = ins_at_start(list,let + 1,num);	
					}
				}
			}
		}
		return sum;
	}
	else{
		if (num >=0 && num <size && let >=0 && let < size){
			if (table[num][let] == 'b'){
				if (let == size - 1){								/* Check if we reached the last column, meaning black has won */	
					return 2;		
				}
				sum = won(color,table,size,num,let + 1,0,special);
				if (sum && special) list = ins_at_start(list,let + 1,num); 			 /* Check if the right hex leads to a win */
				if (!sum){
					sum = won(color,table,size,num - 1,let + 1,0,special);
					if (sum && special) list = ins_at_start(list,let + 1,num - 1); 	 /* Check if the upper-right hex leads to a win */
				}
				if (let != 0){								   /* Ignore lower and upper hexes of a 1st column hex, since they're checked from the calling function */
					if (!sum && danger != -1){										 /* If no winning path is found and the previous hex we checked wasn't the upper one */
						sum = won(color,table,size,num - 1,let,1,special);			 /* Check if the upper hex leads to a win */
						if (sum && special) list = ins_at_start(list,let,num - 1); 	 
					}
					if (!sum && danger != 1){										 /* If no winning path is found and the previous hex we checked wasn't the lower one */
						sum = won(color,table,size,num + 1,let,-1,special);			 /* Check if the lower hex leads to a win */
						if (sum && special) list = ins_at_start(list,let,num + 1); 	
					}
				}

			}
		}
		return sum;
	}
}



int winner(char** table,int size,char color,int special){		/* Finds if 'color' player has won the game 							  */
	int i,j;													/* Returns 0 if there's no winner, 1 if White has won, 2 if Black has won */
	int win = 0;
	if (special) list = NULL;
	
	if (color == 'w'){											
		for (i = 0; i < size; ++i)	
			if (table[size - 1][i] == 'w'){								/* Check if there's a White hex in the last row (used to speed up the check). If there is, perform the full check */
				for (j = 0; j < size && win == 0; ++j)					/* We only need to check paths that begin with 1st row hexes */
					win = won(color,table,size,0,j,0,special);			/* We give those hexes as a seed to the 'won' function */
				if (win && special) list = ins_at_start(list,j-1,0);	/* If a winner is found & we want to print the path, save the current hex */
				break;
			}
	}
	else {
		for (i = 0; i < size; ++i)
			if (table[i][size - 1] == 'b'){								/* Check if there's a Black hex in the last column (used to speed up the check). If there is, perform the full check */
				for (j=0; j < size && win == 0; ++j)					/* We only need to check paths that begin with 1st column hexes */
					win = won(color,table,size,j,0,0,special);		
				if (win && special) list = ins_at_start(list,0,j-1);
				break;
			}
	}
	return win;
}

void print_winner(int win, int player){					/* Prints the winner and the winning path */
	if (win == 1)								
		printf("White player (%s) wins with path: ",player == 10 ? "Human" : "Computer");		/* 'player' can only take 2 values when called from main(): 		*/
	else if (win == 2)																			/* 10 meaning that the Human/user won, or 0 meaning that the PC won */
		printf("Black player (%s) wins with path: ",player == 10 ? "Human" : "Computer");
	
	list_print(list);									/* Prints the list containing the winning path */			
	printf("\n");				
	list_free();										/* Used to empty the list for future use */
}




