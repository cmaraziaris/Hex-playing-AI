
#include "../../Basic_Headers/globals.h"
#include "../../Win_Check/letswin.h"

#include "forceMoves.h"

int advancedFM(char **gameboard, int size, char opponent){    /* Returns a move if it is 1 move away from winning/losing the game         */
    /*              Force move            */
  if (movecount < 2 * size - 4) return -1;
  
  int i,j;
  if (opponent == 'w'){
    for (j=0; j < size; ++j)
      for (i = 0; i < size; ++i){
        if (gameboard[j][i] == 'n'){

          gameboard[j][i] = 'b';
          if (winner(gameboard,size,'b',0) == 2){
            gameboard[j][i]= 'n';
            return size*(j) + i;
          }

          gameboard[j][i] = 'w';
          if (winner(gameboard,size,'w',0) == 1){
            gameboard[j][i]= 'n';
            return size*(j) + i;
          }
          gameboard[j][i] = 'n';
        }
      }
  }
  else if (opponent == 'b'){
    for (j=0; j < size; ++j)
      for (i = 0; i < size; ++i){
        if (gameboard[i][j] == 'n'){

          gameboard[i][j] = 'w';
          if (winner(gameboard,size,'w',0) == 1){
            gameboard[i][j]= 'n';
            return size*(i) + j;
          }

          gameboard[i][j] = 'b';
          if (winner(gameboard,size,'b',0) == 2){
            gameboard[i][j] = 'n';
            return size*i + j;
          }
          gameboard[i][j] = 'n';
        }
      }
  }
  return -1;
}


int forceBridge(char **table, int size, char color){    /* Returns a move when the opponent is 1 move away from breaking a 2-Bridge */
  int i,j;
  i = lastenemyMove / size;
  j = lastenemyMove % size;
  if (i - 1 >= 0 && i + 1 < size && j - 1 >= 0)
    if (table[i-1][j] == color && table[i+1][j-1] == color && table[i][j-1] == 'n')
      return size * i + j - 1;
  if (i - 1 >= 0 && j + 1 < size)
    if (table[i-1][j] == color && table[i][j+1] == color && table[i-1][j+1] == 'n')
      return size * (i-1) + j + 1;
  if (i - 1 >= 0 && j + 1 < size && j - 1 >= 0)
    if (table[i-1][j+1] == color && table[i][j-1] == color && table[i-1][j] == 'n')
      return size * (i-1) + j;
  if (i - 1 >= 0 && j + 1 < size && i + 1 < size)
    if (table[i-1][j+1] == color && table[i+1][j] == color && table[i][j+1] == 'n')
      return size * i + j + 1;
  if (j - 1 >= 0 && j + 1 < size && i + 1 < size)
    if (table[i][j+1] == color && table[i+1][j-1] == color && table[i+1][j] == 'n')
      return size * (i+1) + j;
  if (j - 1 >= 0 && i + 1 < size)
    if (table[i+1][j] == color && table[i][j-1] == color && table[i+1][j-1] == 'n')
      return size * (i+1) + j-1;
  return -1;
}


int forceWannabeBridge(char **table, int size, char player) {     /* Secures a connections with the beginning/ending side of the board         */
  
  int i,j;
  i = lastenemyMove / size;
  j = lastenemyMove % size;

  if (player == 'w'){
    if (i != size - 1 && i != 0) return -1;
    if (i == size - 1){
      if (j == size - 1)
        if (table[size - 2][size - 1] == 'w' && table[size-1][size-2] == 'n')
          return size * (size-1) + size - 2;
      else if (table[size-2][j+1] == 'w' && table[size-1][j+1] == 'n')
        return size * (size - 1) + j + 1;
      else if ( !j )
        if (table[size-2][j] == 'w' && table[size-1][j-1] == 'n') 
          return size * (size - 1) + j - 1;
    }
    else if ( !i ){
      if (!j){
        if (table[1][j] == 'w' && table[0][1] == 'n')
          return size * 0 + 1;
      }
      else if (j == size - 1){
        if (table[1][j] == 'w' && table[0][j-1] == 'n')
          return size * 0 + j - 1;
      }
      else if (j){
        if (table[1][j] == 'w' && table[0][j+1] == 'n') return size * 0 + j + 1;
        if (table[1][j-1] == 'w' && table[0][j-1] == 'n') return size * 0 + j - 1;
      }
    }
  }
  else if (player == 'b'){
    if (j != size - 1 && j != 0) return -1;
    if ( !j ){
      if ( !i ) {
        if (table[i][j+1] == 'b' && table[i+1][j] == 'n')
          return size * (i + 1) + j;
      }
      else if (i != size - 1){
        if (table[i][j+1] == 'b' && table[i+1][j] == 'n')
          return size * (i+1) + j;
        if (table[i-1][j+1] == 'b' && table[i-1][j] == 'n')
          return size * (i-1) + j;
      }
    }
    else if (j == size - 1){
      if ( !i ) return -1;
      if ( i == size - 1){
        if (table[i][j-1] == 'b' && table[i-1][j] == 'n')
          return size * (i-1) + j;
      }
      else if (table[i][j-1] == 'b' && table[i-1][j] == 'n')
        return size * (i-1) + j;
      else if (table[i+1][j-1] == 'b' && table[i+1][j] == 'n')
        return size * (i+1) + j;
    }
  }
  return -1;    
}