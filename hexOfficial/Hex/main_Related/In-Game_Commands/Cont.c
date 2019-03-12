#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../Basic_Headers/globals.h"
#include "../../Basic_Headers/types.h"

#include "../../Interface_Print/letsprint.h"
#include "../../AI/bestMove.h"
#include "../../Swap_Move/letsswap.h"

#include "Cont.h"

int canSwap(int swap, char pc){
  return (swap && movecount == 1 && pc == 'b');
}

int doSwap(char **table, int size, coordinates *move_arr, int *didSwap){
  int swapped = 0;

  if (swap_choice(move_arr[0].number - 1, move_arr[0].letter - 'A',size)){
    
    swapme(table, &move_arr[0].letter, &move_arr[0].number,0);

    swapped = 1;
    *didSwap = 1;
    ++movecount;

    gameboard(size,table);
    printf("Move played: swap\n");            
  }
  return swapped;
}

void playCenter(int *let, int *num, int size){
  *let = (size + 1) / 2 - 1;
  *num = (size + 1) / 2 - 1;
}

void doYourBest(char **table, char pc, int size, int swap, int difficulty, int **Edsger, int *let, int *num){
  
  if (canSwap(swap,pc)){   /* If PC doesn't swap, it plays in the center   */
    playCenter(let,num,size);
    return;
  }

  int letsplay;

  letsplay = bestmove(table, pc, size, difficulty, 1 , INT_MIN+1 , INT_MAX, Edsger);   

  *num = letsplay / size;              /* Use AB Pruning to get the best move */
  *let = letsplay % size;

}

int isValidPCMove(char **table, int size, int j, int i){
  if (i < 0 || i > size - 1 || j < 0 || j > size - 1 ) 
    return 0;
  if (table[i][j] != 'n')
    return 0;
  return 1;
}

void randomMove(char **table, int size, int *let, int *num){
  int i,j;
  srand(time(NULL));

  do {
    i = rand() % size;
    j = rand() % size;
  } while (table[i][j] != 'n');
  
  *num = i;
  *let = j;
}

void updateBoardPC(char **table, char pc, int let, int num){
  table[num][let] = pc;
}

void updateMoveArrayPC(coordinates *move_arr, int let, int num){
  move_arr[movecount].letter = let+'A';     /* Update the array that keeps track of the played EdsgerMoveArray */
  move_arr[movecount].number = num + 1;  
  ++movecount;
}

void movePlayedPC(int let, int num){
  printf("Move played: %c%d\n",let + 'A',num + 1);
}