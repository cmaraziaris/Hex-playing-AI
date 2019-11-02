
/*    Changed the openingMoves.c used to the 09.03.2019 competition   */
/*    in which line 22 was: if (size == 5)                            */
/*    Original version can be found in hexCupv1.zip                   */

#include "openingMoves.h"

#include "../../Basic_Headers/globals.h"

int openingMoves(char **table, int size, char player){      /* Some pre-defined opening moves         */

  if (movecount >=3) return -1;                             /* Based on Kostas' ability to play Hex   */

  if (!movecount && size != 11){
    if (size % 2) return size*(size/2)+ size/2;
    else return size*(size/2) + size/2 -1;
  }

  int i,j;
  i = lastenemyMove / size;
  j = lastenemyMove % size;

  if (size == 5) {
    if (movecount == 2) {
      if (i == 1 && j == 2)
        return size * 1 + 3;
      if (i == 1 && j == 3)
        return size * 1 + 2;
      if (i == 3 && j == 1)
        return size * 3 + 2;
      if (i == 3 && j == 2)
        return size * 3 + 1;
      if (i == 4 && (j == 0 || j == 1))
        return size * 3 + 3;
      if (i == 4 && j == 2)
        return size * 4 + 1;
      if (i == 0 && (j == 3 || j == 4))
        return size * 1 + 1;
      if (i == 0 && (j == 2 || j == 1))
        return size * 0 + 3;
      //difficulty 6 
      return size * 1 + 1;
    }
  }  
  else if (size == 11){
    if (!movecount) return size*(size/2+2) + size/2 + 2;
  }
  else{
    if (movecount == 1){

      if ( i >= size/2){
        if ( j <= size - 4) return size*(i-2) + j+1;
        else return size*(i-2) + j-1;
      }
      else{
        if (j >= 3) return size*(i+2) + j-1;
        else return size*(i+2) + j + 1; 
      }
    }
  }
}
