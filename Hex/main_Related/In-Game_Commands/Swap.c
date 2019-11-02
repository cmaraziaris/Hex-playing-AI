#include <stdio.h>

#include "../../Basic_Headers/types.h"
#include "../../Basic_Headers/globals.h"
#include "../../Swap_Move/letsswap.h"
#include "Swap.h"

int isSwapLegal(char user, char swap, char didSwap){
  if (user == 'b' && movecount == 1 && swap == 1 && !didSwap)
    return 1;
  else
    printf("Can't use the swap move.\n");
  return 0;
}

void performSwap(char **table, int size, coordinates *move_arr, char *currentplayer, int *didSwap){
  *currentplayer = 'w';
  swapme(table, &move_arr[0].letter, &move_arr[0].number,0);
  *didSwap = 1;
  ++movecount;
  printf("Move played: swap\n");

}