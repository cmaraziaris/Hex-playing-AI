/* Note that this heuristic function works as intented only if the difficulty level is set to 1       */
/* thus forseeing only 1 enemy move ahead. That pushed us towards implementing a dynamic difficulty   */
/* generator that works like a switch. For the first N moves, Hexie will mainly aim to build bridges. */
/* After the Nth move, Hexie will choose a move based on the shortest winning path this move leads to.*/


#include "bridges.h"

int maxBridge(char **table, int size, char color){  /* Counts the # of bridges for player 'color'   */
  int i,j;
  int count = 0;
  int br;
    for (j=0; j < size; ++j)
      for(i=0; i < size; ++i){
        br = isBridge(table,size,i,j,color);
        count += br; 
      }
  return count;
}


int isBridge(char **table, int size, int i, int j, char color){   /* Evaluates the significance of every Bridge found     */
  float count = 0;
  float signW, signB, nonsignW, nonsignB;                         /* sign == SIGNIFICANT, nonsign == NONSIGNIFICANT       */
                                                                  /* the weights that define 'sign' and 'nonsign' bridges */
  signW = signB = nonsignW = nonsignB = 0;                        /* were manually set                                    */
  if (color == 'w') {
    signW = 3;
    nonsignW = 1.5;
  }
  if (color == 'b') {
    signB = 3;
    nonsignB = 1.5;
  }

  if (i + 1 < size){
    if (j-2 >= 0)
      if (table[i+1][j-2] == color && table[i+1][j-1] == 'n' && table[i][j-1] == 'n')
        count += signB + nonsignW; 
    if (j+1 < size)
      if (table[i+1][j+1] == color && table[i][j+1] == 'n' && table[i+1][j] == 'n')
        count += nonsignW + nonsignB;
  }

  if (i + 2 < size && j - 1 >= 0)
    if (table[i+2][j-1] == color && table[i+1][j] == 'n' && table[i+1][j-1] == 'n')
      count += signW + nonsignB; 

  return (int)count;
}
