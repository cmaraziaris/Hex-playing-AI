#include <limits.h>

#include "../../Win_Check/letswin.h"
#include "./Evaluation_Function/letseval.h"

int ab_pruning(char** gameboard,char player, int size, int depth, int ismax,int alpha, int beta, int **moves);
int max(int, int);
int min(int, int);

int max(int x, int y){          // returns maximum number
  if (x >= y) return x;
  return y;
}

int min(int x, int y){          // returns minimum number
  if (x <= y) return x;
  return y;
}

int ab_pruning(char** gameboard,char player, int size, int depth, int ismax,int alpha, int beta, int **moves){ //TThe improved minimax algorithm
  int i,j,win,value;
  char opponent;
  win = 0;
  opponent = ('w' - player) + 'b';                  // If player is white then opponent is black and vice versa. The order of operations is important
                                                    // in order to not overflow

  win = winner(gameboard,size,'w',0); // returns 1 if there is a winner and 0 otherwise
  if (!win) win = winner(gameboard,size,'b',0);


  if (depth == 0 || win){                       //If we reached the final depth or there is a winner the evaluate the current gameboard
    int score;                                 // Evaluate the gameboard
    if (win == 1) score = INT_MAX;
    else if (win == 2) score = INT_MIN + 1;
    else score = evaluation(gameboard, size, moves);
       
    if (player == 'w'){                       // If the current player is the white player
      if (ismax)                          // If he is the max player  
        return score;                       // Return the score as it is
      else
        return -1 * score;                    // Otherwise change the sign and then return it
    }
    else {                              //The current player is the black player
      if (ismax) 
        return -1 * score;
      else
        return score;
    } 
  }
    // We have not reached the final depth and there is no winner so continue with the recursive part of the ab_pruning algorithm 

  else if (ismax){                          //The current player is the maximum player so find the maximum score
    int max_value = INT_MIN + 1;                  //Set the value to the lowest possible integer 
                                                  //In the evaluation function the lowest number is INT_MIN+1( so that the sign can change) so make it the same here
    for (i=0; i < size; ++i)
      for (j=0; j < size; ++j)
        if (gameboard[i][j] == 'n'){              // Search the gameboard for a possible move  
          gameboard[i][j] = player;               // The player plays that possible move
          value = ab_pruning(gameboard,opponent,size,depth-1,!ismax, alpha, beta, moves); 

                /*find the value of the gameboard with that move using the recursive ab_pruning function. The !ismax means that min player
                and max player alternate. Also reduce the depth by 1 till we reach the final depth and the current player becomes the 
                the opponent      */

          max_value = max( max_value, value);         // If value is bigger then we found anew biggest value
          alpha = max(alpha, value);              // same with alpha
          gameboard[i][j] = 'n';                // Undo the move and then search for another possible move
          if ( beta <= alpha) break;              //There is no point in continuing so break out of the loop
          }
    return max_value;                         // return the maximum value found
  }
  else {                                // The current player is the minimum player
    int min_value = INT_MAX;                    //Set the minimum value to the highest possible integer 
    for (i=0; i < size; ++i)
      for (j=0; j < size; ++j)
        if (gameboard[i][j] == 'n'){                // Check possible moves
          gameboard[i][j] = player;               // play that possible move
          value = ab_pruning(gameboard,opponent,size,depth-1,!ismax, alpha, beta, moves); // Find the value for that possible move
          min_value = min( min_value, value);         // Update min value
          beta = min(beta, value);              // Update beta
          gameboard[i][j] = 'n';                //Undo the move
          if ( beta <= alpha) break;              //No point to continue
          }
    return min_value;                       //Return the min_value
  }
}
