#include <string.h>
#include <stdio.h>
#include <stdlib.h> //exit  

#include "../Error_Handling/letserrorhandle.h"
#include "commandLine.h"

void commandLine(char **argv, int argc, int *size, int *difficulty, int *swap, char *user, char *pc){  
  int i;
  for (i=1; i < argc; ++i) {            
    if (strcmp(argv[i],"-n") == 0){ 
      int newSize = atoi(argv[++i]);  
      if (isValidSize(newSize))   /* Check if the size given is valid */
        *size = newSize;
      else {
        printf("Invalid size given.\n");
        exit(-3);
      }
    }
    else if (strcmp(argv[i],"-d") == 0){
      int newDiff = atoi(argv[++i]);
      if (isValidDiff(newDiff))   /* Check if the difficulty given is valid */
        *difficulty = newDiff;
      else {
        printf("Invalid difficulty given\n");
        exit(-3);
      }
    }
    else if (strcmp(argv[i],"-s") == 0)   /* -s means the swap rule is enabled */
      *swap = 1;
    else if (strcmp(argv[i],"-b") == 0){  /* -b means that the User is the black player */
      *user = 'b';
      *pc = 'w';
    }
    else {                  /* If none of the above is given */
      printf("Invalid command given in the command line: %s\n",argv[i]);
      exit(-3);
    }
  }
}