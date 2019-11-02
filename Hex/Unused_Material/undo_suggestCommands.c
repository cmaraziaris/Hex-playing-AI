/*    Extracted exactly as they were in the original main.c     */
/*    Will be implemented to the current version (someday) :]   */

#if 0
//COMMAND: UNDO                               /* Resets the last move,    if the last move was made by the user. */
    else if (strncmp(command,"undo",4) == 0 && movecount != 0){     /* Resets the last 2 EdsgerMoveArray, if the last move was made by the PC */
      if (swap && didSwap && movecount == 2 && user == 'b') {
        swapme(table, &move_arr[0].letter, &move_arr[0].number,1);  /* If the user played SWAP, reset it and restore PC's 1st move */
      }
      else {
        if (currentplayer != user){                   /* If the last move was made by the user */
          table[move_arr[movecount-1].number - 1][move_arr[movecount-1].letter - 'A'] = 'n';    /* Reset the last hex played */
          --movecount;      
          currentplayer = user;
        }
        else if (movecount != 1){                   /* Check if the user is to play and at least 2 EdsgerMoveArray have been played */
          table[move_arr[movecount-1].number - 1][move_arr[movecount-1].letter - 'A'] = 'n';    /* Reset the last 2 hexes played on the board */
          table[move_arr[movecount-2].number - 1][move_arr[movecount-2].letter - 'A'] = 'n';    /* Both the user's & the pc's EdsgerMoveArray are reset */
          movecount -= 2;
        }
        else {                                /* Check if the user is to play and there's only 1 move played so far*/ 
          table[move_arr[movecount-1].number - 1][move_arr[movecount-1].letter - 'A'] = 'n';
          movecount = 0;
        }
      }
      printf("%s player (Human) plays now.\n",user == 'w' ? "White" : "Black"); /* If UNDO is given then it's always the user's turn to play */
      currentplayer = user; 
    }
#endif

#if 0
//COMMAND:SUGGEST
    else if (strncmp(command,"suggest",7) == 0){      /* PC suggests a move to its opponent */
      if (currentplayer != user)                /* Check if the command is valid */
        printf("Invalid command: PC's turn to play.\n");
      else {  
        int swapped = 0;            
        if (swap && movecount == 1 && user == 'b')      /* Consider the SWAP move */
          if (swap_choice(move_arr[0].number - 1, move_arr[0].letter - 'A',size)){
            swapped = 1;
            printf("You may play: SWAP\n");
          }
        if (!swapped) {             
          int num,let;                    /* Use AB Pruning to get the best move for the opponent */
          int letsplay = bestmove(table, user, size, difficulty, 1 , INT_MIN + 1 , INT_MAX, EdsgerMoveArray);      
          num = letsplay / size;
          let = letsplay % size;
          printf("You may play at: %c%d\n",let + 'A',num + 1);
        }
      }
    }
#endif