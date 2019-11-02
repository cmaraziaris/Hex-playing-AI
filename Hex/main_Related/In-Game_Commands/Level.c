#include <stdio.h>

#include "../Error_Handling/letserrorhandle.h"

void level(int *difficulty){
  char ch;
  ch = getchar(); 
  if (ch == '\n')                 
    printf("Difficulty level is set to: %d\n",*difficulty);    /* If just 'level' is given */
  else {
    int newDiff;
    scanf("%d",&newDiff);
    if (isValidDiff(newDiff))            /* Check if the string is valid */
      *difficulty = newDiff;         /* Update difficulty */
    else
      printf("Invalid difficulty given: %d\n",newDiff);
  }
}