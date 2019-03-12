#include <string.h>
#include <stdio.h>

#include "../Error_Handling/letserrorhandle.h"
#include "NewGame.h"

void newgameArg(char *user, char *pc, int *swap, int *size){
  char ch;
  if ((ch = getchar()) != '\n'){          /* getchar() used to eat the whitespace following the command 'newgame' */
    char parameter[2][10];            /* and check if there are parameters given */
    scanf("%s",parameter[0]);         /* Read the 1st parameter, that defines the user's color */
                          
    if (!strcmp(parameter[0],"white") || !strcmp(parameter[0],"black")){    /* Is it legal? */
      *user = parameter[0][0];                       
      if (*user == 'b')
        *pc = 'w';
      else 
        *pc = 'b';
    
      if ((ch = getchar()) != '\n') {
        scanf("%s",parameter[1]);         /* Read the 2nd parameter, that enables/disables the swap rule */
        if (!strcmp(parameter[1],"swapon") || !strcmp(parameter[1],"swapoff")){     /* Is it legal? */
          if (!strcmp(parameter[1],"swapon"))
            *swap = 1;
          else 
            *swap = 0;

          if ((ch = getchar()) != '\n') {
            scanf("%d",size);        /* Read the 3rd parameter, that defines the size of the board */
            if (!isValidSize(*size))   /* Is the size given valid? */
              printf("Please give an integer from 4 to 26 as the size of the board.\n");
          }
        }
        else printf("Syntax: newgame [white|black [swapoff|swapon [<size>]]]\n");
      }
    }
    else printf("Syntax: newgame [white|black [swapoff|swapon [<size>]]]\n");
  }
}