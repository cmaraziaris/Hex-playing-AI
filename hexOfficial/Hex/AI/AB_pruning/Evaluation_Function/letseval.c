
#include "../../../Basic_Headers/globals.h"

#include "./Bridges_Functions/bridges.h"
#include "./Dijkstra_Shortest_Path/dijkstra.h"


int evaluation(char** table,int size, int **moves);

int evaluation(char** table,int size, int **moves){     /* Evaluates a state of the game's board */
  int value;
  int maxWhite, maxBlack;

  if (movecount <= letsDecide){                 /* If we're behind a custom-set number of moves                       */
    maxWhite = maxBridge(table,size,'w');       /* Evaluate a position based on the number of 2-Bridges on the board  */
    maxBlack = maxBridge(table,size,'b');       
    value = maxWhite - maxBlack;                
  }
  else {
    value = Dijkstra(table,size,moves);         /* If we surpassed the limit of moves                                 */
  }                                             /* Evaluate a position based on Dijkstra's shortest path algorithm    */

return value;
}