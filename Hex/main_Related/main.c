#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "main_Header.h"


int main(int argc, char** argv){
  int size, difficulty, swap, win, didSwap;
  char user, pc, currentplayer;
  char command[25];

  initVariables(&win,&didSwap,&currentplayer,&size,&difficulty,&swap,&user,&pc);
    
  commandLine(argv,argc,&size,&difficulty,&swap,&user,&pc); 

  char** table = createBoard(size);
  initBoard(table,size);
  
  int** EdsgerMoveArray = createInitDijkstra(size); /* Array for the Djikstra algorithm */

  coordinates *move_arr = createMoveArray(size);    /* Array to store moves for UNDO    */

  letsDecide = decider(size);                     /* Decides the # of moves needed for this size of board              */
                                                  /* in order to swap the active heuristic in the evaluation function  */
  do{
    dynamicDifficulty(&difficulty,size);          /* Changes the difficulty according to the # of moves played         */
    interface();
    scanf("%s",command);  

//COMMAND: NEWGAME
    if (!strncmp(command,"newgame",7)){     /* A new game session is created */

      int oldsize = size; 
      initVariables(&win,&didSwap,&currentplayer,&size,&difficulty,&swap,&user,&pc);  
      
      newgameArg(&user,&pc,&swap,&size);

      freeBoard(table, oldsize);
      freeDijkstra(EdsgerMoveArray, oldsize);
      freeMoveArray(move_arr);

      table = createBoard(size);
      initBoard(table,size);
      EdsgerMoveArray = createInitDijkstra(size);
      move_arr = createMoveArray(size);

      letsDecide = decider(size);   
    } 

//COMMAND: PLAY
    else if (!strncmp(command,"play",4)){      /* User plays a move */
      if (isTurn(win,user,user,currentplayer)){                   /* Is it really the user's turn to play? */
        coordinates move = getMove();           /* Read user's move */
    
        if (isValidUsersMove(table,size,move)){
          updateBoardUser(table,user,move);         /* Update the array that keeps track of the played EdsgerMoveArray */
          updateMoveArrayUser(move_arr,move); 
          updateLastEnemyMove(size,move);

          gameboard(size,table);                      /* Print the current state of the game */
          movePlayedUser(move);

          win = didWeWin(table,size,user,user);                /* Check if the User won by making this move */
          if (!win){
            printNextPlayer(&currentplayer,user);
          }
        }
      }
    }

//COMMAND: CONT
    else if (strncmp(command,"cont",4) == 0 ){      /* PC plays a move */
      if (isTurn(win,user,pc,currentplayer)){          /* Is it really the PC's turn to play? */
        int swapped = 0;                /* 'swapped' is 1 if the PC chose to SWAP, else 0   */

        if (canSwap(swap,pc)){          /* Consider making the SWAP move */
          swapped = doSwap(table,size,move_arr,&didSwap);
        }
        if (!swapped){
          int num,let;

          doYourBest(table,pc,size,swap,difficulty,EdsgerMoveArray,&let,&num);

          if (!isValidPCMove(table,size,let,num)){
            randomMove(table,size,&let,&num);
          }

          updateBoardPC(table,pc,let,num);
          updateMoveArrayPC(move_arr,let,num);

          gameboard(size,table);              /* Print the current state of the game */
          movePlayedPC(let,num);   
        }

        win = didWeWin(table,size,user,pc);          /* Check if the PC won by making this move */
        if (!win){                    
          printNextPlayer(&currentplayer,user);
        }
      }
    }

//COMMAND: LEVEL
    else if (!strncmp(command,"level",5)){      /* Prints or Changes the current difficulty level */
      level(&difficulty);  
    }

//COMMAND: SWAP 
    else if (!strncmp(command,"swap",4)){       /* Plays the swap move */
      if (isSwapLegal(user,swap,didSwap)){     /* Is swap legal? */

        performSwap(table,size,move_arr,&currentplayer,&didSwap);
        gameboard(size,table);                /* Print the current state of the game */

        printf("White player (%s) plays now.\n",user == 'w' ? "Human" : "Computer");
      }
    }

//COMMAND: SAVE <STATEFILE>
    else if (!strncmp(command,"save",4)){   /* Saves the current state of the game to a .hex file */
      saveHex(table,&size,currentplayer);
    }

//COMMAND: LOAD <STATEFILE>
    else if (!strncmp(command,"load",4)){   /* Loads a .hex file */
      loadHex(&table, &EdsgerMoveArray, &move_arr, &size, &currentplayer, &didSwap, user);
    }

//COMMAND: SHOWSTATE
    else if (!strncmp(command,"showstate",9)){ /* Prints the current state of the game */
      gameboard(size,table);
    }

//COMMAND: QUIT
    else if (strncmp(command,"quit",4) == 0){   /* Quits the game */
      printf("Quitting...\n");
      quitHex(table,EdsgerMoveArray,move_arr,size);
      break;          
    }

    else {
      printf("Invalid command given. Please, try again.\n");
    }

    fflush(stdout);

  } while (1);

return EXIT_SUCCESS;
}