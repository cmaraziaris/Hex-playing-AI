#include <stdlib.h>

#include "../../Basic_Headers/types.h"
#include "../../Basic_Headers/globals.h"
#include "createInitFree.h"

void initBoard(char **table, int size){
  int i,j;
  for(i=0; i<size; ++i)       /* Fill the board with empty hexes */
    for(j=0; j<size; ++j)
      table[i][j] = 'n';      /* 'w' means white hex, 'b' means black hex, 'n' means empty hex */
}

char **createBoard(int size){
  int i,j;
  char** table;               /* Allocate memory for the array used to represent the game's board */
  if ((table = malloc(size * sizeof(int*))) == NULL)  exit(EXIT_FAILURE); 
  for(i=0; i<size; ++i)
    if ((table[i] = malloc(size * sizeof(int))) == NULL)  exit(EXIT_FAILURE);
  return table;
}

void freeBoard(char **table, int size){
  int i;
  for (i=0; i < size; ++i) 
    free(table[i]);           /* Deallocate memory used for the 'old' array */
  free(table);
}

int **createInitDijkstra(int size){
  int j;
  int** array;
  if ((array = malloc((size+1) * sizeof(int *))) == NULL) exit(EXIT_FAILURE);
  for(j=0; j < size; ++j){
    if ((array[j] = malloc(size * sizeof(int))) == NULL) exit(EXIT_FAILURE);
  }
  if ((array[size] = malloc(2 * sizeof(int))) == NULL) exit(EXIT_FAILURE);
  return array;
}

void freeDijkstra(int **array, int size){
  int j;
  for (j=0; j <= size; ++j)
    free(array[j]);
  free(array);
}

coordinates *createMoveArray(int size){
  coordinates* array;
  if ((array = malloc((size * size) * sizeof(coordinates))) == NULL) exit(EXIT_FAILURE);
  return array;
}

void freeMoveArray(coordinates* array){
  free(array);
}

void initVariables(int *win, int *didSwap, char *currentplayer, int *size, int *difficulty, int *swap, char *user, char *pc){
  *win = *didSwap = *swap = 0;
  *currentplayer = *user = 'w';
  *pc = 'b';
  *size = 11;
  *difficulty = 1;
  movecount = 0;        
  lastenemyMove = -1;
}