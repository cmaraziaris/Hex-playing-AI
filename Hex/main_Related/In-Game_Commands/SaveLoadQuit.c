#include <stdio.h>
#include <stdlib.h>

#include "../../Basic_Headers/globals.h"
#include "../../Basic_Headers/types.h"

#include "../../Interface_Print/letsprint.h"
#include "createInitFree.h"
#include "SaveLoadQuit.h"

void saveHex(char **table, int *size, char currentplayer) {   /* Saves the current state of the game to a .hex file */
  char name[50];
  int i,j;

  getchar();                    /* Eat the whitespace following the command 'save' */
  scanf("%s",name);  

  FILE *fp;
  if ((fp = fopen(name,"w")) == NULL) exit(EXIT_FAILURE); /* Open or Create a file to write */
  fwrite(size,1,1,fp);           
  fprintf(fp,"%c",currentplayer);
  for(i=0; i < *size; ++i)
    for(j=0; j < *size; ++j)
  fprintf(fp,"%c",table[i][j]);     /* Write every hex's color to the file */

  if (fclose(fp)) exit(EXIT_FAILURE);

  printf("Game saved successfully!\n");
}

void loadHex(char ***table, int ***dArray, coordinates **mvArray, int *size, char *currentplayer, int *didSwap, char user){   /* Loads a .hex file */
  char name[50];
  
  getchar();
  scanf("%s",name);

  freeBoard(*table, *size); 
  freeDijkstra(*dArray, *size);
  freeMoveArray(*mvArray);

  FILE *fp; 
  if ((fp = fopen(name,"r")) == NULL) exit(EXIT_FAILURE);  /* Open the file in read-only mode */
  *size = (int) getc(fp);  
  *currentplayer = getc(fp);

  /* Allocate memory for the updated game board based on the file's data */
  *table = createBoard(*size);
  getBoard(*table,fp,*size);

  if (fclose(fp)) exit(EXIT_FAILURE);

  *dArray = createInitDijkstra(*size);
  *mvArray = createMoveArray(*size);

  lastenemyMove = -1;

  isSwapAllowed(*table,*size,didSwap);

  printf("Game loaded successfully!\n");
  gameboard(*size,*table);            /* Print the current state of the board   */

  printCurrentPlayer(*currentplayer,user);
}

void isSwapAllowed(char **table, int size, int *didSwap){
  int isBlack = 0;
  int i,j;
  movecount = 0;

  for(i=0; i < size; ++i)
    for(j=0; j < size; ++j)
      if (table[i][j] != 'n'){
        ++movecount;
        if (table[i][j] == 'b') isBlack = 1;
      }

  if (movecount == 1)
    if (isBlack)
      *didSwap = 1;
    else
      *didSwap = 0;
}

void printCurrentPlayer(char currentplayer, char user){
  if (currentplayer == 'w')
    printf("White player (%s) plays now.\n",user == 'w' ? "Human" : "Computer");
  else
    printf("Black player (%s) plays now.\n",user == 'b' ? "Human" : "Computer");
}

void getBoard(char **table, FILE *fp, int size){
  int i,j;
  for (i=0; i < size; ++i)              /* 'isWhite' shows that the white player has made at least 1 move */
    for (j=0; j < size; ++j)           /* Both used to determine if the SWAP move can be played after loading the new board */
      table[i][j] = getc(fp);           /* Fill in the board */
}

void quitHex(char **table, int **dArray, coordinates* mvArray, int size){

  freeDijkstra(dArray, size);
  freeMoveArray(mvArray);
  freeBoard(table, size);
}