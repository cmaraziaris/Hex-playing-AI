#include <stdio.h>

#include "../../Win_Check/letswin.h"

void printNextPlayer(char *currentplayer, char user){
  if (*currentplayer == 'w'){
    *currentplayer = 'b';                  /* Print the player to play next */
    printf("Black player (%s) plays now.\n",user == 'b' ? "Human" : "Computer");
  }
  else if (*currentplayer == 'b') {
    *currentplayer = 'w';  
    printf("White player (%s) plays now.\n",user == 'w' ? "Human" : "Computer");
  }
}


int isTurn(int win, char user, char color, char currentplayer){
  if (win) {
    printf("Invalid command: The game has ended.\n");
    return 0;
  }
  if (currentplayer != color) {
    printf("Invalid command: %s's turn to play.\n", color == user ? "PC" : "User");
    return 0;
  }
  return 1;
}

int didWeWin(char **table, int size, char user, char color){
  int variable;
  int whoWon = 0;

  if (color == user)
    variable = 10;
  else
    variable = 0;

  if (whoWon = winner(table,size,color,1)){
    print_winner(whoWon,variable); 
  }
  return whoWon;
}

void interface(void){
  printf(">");
  fflush(stdout);
}