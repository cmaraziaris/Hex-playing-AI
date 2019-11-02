
#include "letserrorhandle.h"

int isValidSize(int size){      /* Checks if the string given is an acceptable integer */
                                /* to be used as the game's board size.          */
  if (size < 4 || size > 26)      /* Is the given size outside the range */ 
    return 0;                     /* of acceptable values? [4-26]      */ 
  return 1;   
}

int isValidDiff(int diff){     /* Checks if the string given is an acceptable integer */
                                /* to be used as the game's difficulty.          */
  if (diff > 800 || diff < 1)   /* Is the given difficulty outside the range */       
    return 0;         /* of acceptable values? [1-14]        */
  return 1;
}
