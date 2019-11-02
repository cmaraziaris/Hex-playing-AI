#include <limits.h>

#include "bestMove.h"

#include "./AB_pruning/abPruning.h"
#include "./Forced_Moves/openingMoves.h"
#include "./Forced_Moves/forceMoves.h"


int bestmove(char** gameboard,char player, int size, int depth, int ismax, int alpha, int beta, int **moves){
  char opponent;
  int i,j,value,max_value,bestMove;

  opponent = ('w' - player) + 'b';
  /*  Forced moves, AB is not called at all if one of them returns a value >= 0 */
{   
  int opening = openingMoves(gameboard,size,player);         /* Returns a pre-set opening move                                           */
  if (opening != -1) return opening;
  
  int force = advancedFM(gameboard,size,opponent);           /* Returns a move if it is 1 move away from winning/losing the game         */
  if (force != -1) return force;

  int fBridge = forceBridge(gameboard,size,player);          /* Returns a move when the opponent is 1 move away from breaking a 2-Bridge */
  if (fBridge != -1) return fBridge;

  int fWannabeBridge = forceWannabeBridge(gameboard,size,player);
  if (fWannabeBridge != -1) return fWannabeBridge;           /* Secures a connections with the beginning/ending side of the board         */
}
  /* If there's no need to force a move, call AB pruning    */

  bestMove = -1;                                            // Make it -1 to denote that no bestMove is selected yet
  max_value = INT_MIN + 1; 
    for (i = 0 ; i < size ; ++i)
         for (j = 0 ; j < size ; ++j){
          if (gameboard[i][j] == 'n'){                      //Found a possible move
            gameboard[i][j] = player;                       // Play the possible move
            value = ab_pruning(gameboard, opponent, size, depth - 1 , !ismax, alpha, beta, moves); //Calculate the value of that move 
            max_value = (max_value >= value ? max_value : value);      // Update the max_value
          if (alpha < max_value){                           // If alpha is smaller than max_value then a new best move was found
              alpha = max_value;                            // Make the value of alpha the new max_value
              bestMove = size * i + j;                      // Represantation of best move as x coordinate = temp/size and y coordinate = temp%size
          }
          
          gameboard[i][j] = 'n';                            // Undo move
         }
       }

    if (bestMove != -1) return bestMove;                    // A best move was determined by ab_pruning 
    else {                                                  // No best move was determined (that happens because the minnimum player  
      for ( i = 0 ; i < size ; i++){                        // has a winning strategy for moves less than or equal to the difficulty)
        for (j = 0 ; j < size ; j++){
          if ( gameboard[i][j] == 'n') return size*i + j;   // Return the coded coordinates of the first empty gametile
        }
      }
    }
}