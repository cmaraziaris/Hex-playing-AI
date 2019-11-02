#include <stdio.h>

#include "../../Basic_Headers/types.h"
#include "../../Basic_Headers/globals.h"
#include "../../Win_Check/letswin.h"

coordinates getMove(void){
  coordinates move;
  getchar();
  scanf("%c%d",&(move.letter),&(move.number));
  return move;
}

int isValidUsersMove(char **table, int size, coordinates move){
  if (move.letter >= size + 'A' || move.letter < 'A' || move.number >= size + 1 || move.number < 1){
    printf("Invalid move to play. No such hex.\n");
    return 0;
  } 
  if (table[move.number - 1][move.letter - 'A'] != 'n'){      /* Check if it's a valid move */
    printf("Invalid move to play. Hex %c%d already played.\n",move.letter,move.number);
    return 0;
  }
  return 1;
}

void updateBoardUser(char **table, char user, coordinates move){
  table[move.number - 1][move.letter - 'A'] = user;
}

void updateMoveArrayUser(coordinates *move_arr, coordinates move){
  move_arr[movecount].letter = move.letter;
  move_arr[movecount].number = move.number; 
  ++movecount;  
}

void updateLastEnemyMove(int size, coordinates move){
  lastenemyMove = size * (move.number - 1) + move.letter - 'A';
}

void movePlayedUser(coordinates move){
  printf("Move played: %c%d\n",move.letter,move.number);
}
