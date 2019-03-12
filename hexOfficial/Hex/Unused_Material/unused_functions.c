

int justFit(char **table, int size, char player){
  int i,j;
  i = lastenemyMove / size;
  j = lastenemyMove % size;
  char enemy = 'w' - player + 'b';
  if (i+1 <= size && j-2 >=0){
    if (table[i+1][j-2] == enemy){
     if (table[i][j-1] == 'n' && table[i+1][j-1] == player){
       return size * (i) + j - 1;
      }
    }
  }
  if (j - 1 >= 0 && i + 1 < size){
    if (table[i][j-1] == player && table[i+1][j-1] == 'n'){
      return size * (i+1) + j - 1;
    }
  }

if (i + 1 < size && j + 2 < size){
  if (table[i+1][j+2] == enemy)
    if (table[i][j+1] == player && table[i+1][j] == 'n')
      return size * (i+1) + j;
  }
  if (j + 1 < size && i + 1 < size){
    if (table[i][j+1] == 'n' && table[i+1][j] == player)
      return size * (i) + j + 1;
  }
  if (j-1 >= 0 && i + 2 < size){
    if (table[i+2][j-1] == enemy)
      if (table[i+1][j-1] == player && table[i+1][j] == 'n')
        return size * (i+1) + j;
    }
    if (j-1 >= 0 && i + 1 < size){
      if (table[i+1][j-1] == 'n' && table[i+1][j] == player)
        return size * (i+1) + j - 1;
    }
  }

int maximumpath(char** table,int size, char color){   /* Finds the maximum among all paths player 'color' has formed */
  int aPath;                      
  int i,j,k;
  int maximum = INT_MIN;

  for (i=0; i < size; ++i)          /* For every hex in the board */
    for (j=0; j < size; ++j){         
      aPath = 0;
      int* mark;              /* Create an array that stores 'marked' hexes */
      if ((mark = malloc(size*size*sizeof(int))) == NULL)
        exit(EXIT_FAILURE);

      for (k=0; k < size*size; ++k)     /* Initialise 'mark' with 0, meaning that no hexes are being used */
        mark[k] = 0;
      path(color,table,size,mark,i,j);  /* Find the path that starts with the current hex (row = i, col = j) */

      for (k=0; k < size*size; ++k) 
        if (mark[k])          /* Count how many hexes this path includes */
          aPath++;
      if (maximum < aPath)        /* Compare the length of this path with the maximum found yet */
        maximum = aPath;  
      free(mark);             
    }
  return maximum;               
}  

void path(char color,char** table,int size,int* mark,int num, int let){   /* Finds a path for the 'color' player  */

  if (num >=0 && num < size && let >= 0 && let < size){       /* Are the coordinates valid? */
    if (table[num][let] != color || mark[num*size + let] == 1)    /* If the hex isn't occupied by the wanted color */
      return;                           /* or if the hex is already marked */
    else{
      mark[num*size + let] = 1;             /* Mark the current hex                    */
      path(color,table,size,mark,num + 1, let);     /* Check if the lower-right  hex can be a part of the path */
      path(color,table,size,mark,num + 1, let-1);     /* Check if the lower-left   hex can be a part of the path */
      path(color,table,size,mark,num, let-1);       /* Check if the left         hex can be a part of the path */
      path(color,table,size,mark,num, let+1);       /* Check if the right        hex can be a part of the path */   
      path(color,table,size,mark,num-1, let);       /* Check if the upper-left   hex can be a part of the path */         
      path(color,table,size,mark,num-1, let+1);     /* Check if the upper-right  hex can be a part of the path */ 
      return;
    }
  }
  return;
}

  int isBridge(char **table, int size, int i, int j, char color){
  float count = 0;
    if (color == 'w'){
      if (j - 1 >= 0 && i + 2 < size)
        if (table[i+2][j-1] == 'w' && table[i+1][j-1] == 'n' && table[i+1][j] == 'n' )
          count += 2.5;
      if (j +1 < size && i + 1 < size)
        if (table[i+1][j+1] == 'w' && table[i+1][j] == 'n' && table[i][j+1] == 'n')
          count += 1;
      return (int)count;
    }
    else {
      if (i-1 >= 0 && j + 2 < size)
        if (table[i-1][j+2] == 'b' && table[i-1][j+1] == 'n' && table[i][j+1] == 'n' )
          count += 2.5;
      if (j +1 < size && i + 1 < size)
        if (table[i+1][j+1] == 'b' && table[i+1][j] == 'n' && table[i][j+1] == 'n')
          count += 1;
      return (int)count;
    }
    return 0;
  }


  #if 0  
{ /* kwdikas pou afaire8ike apo tin isBridge2 */
  if (i-1 >= 0){
    if (j-1 >=0)
      if (table[i-1][j-1] == color && table[i-1][j] == 'n' && table[i][j-1] == 'n')
        count += nonsign;
    
    if (j+2 < size)
      if (table[i-1][j+2] == color && table[i][j+1] == 'n' && table[i-1][j+1] == 'n')
        count += nonsign;
    
  }

  if (i-2 >= 0 && j+1 < size)
    if (table[i-2][j+1] == color && table[i-1][j] == 'n' && table[i-1][j+1] == 'n')
      count += sign;
}
#endif