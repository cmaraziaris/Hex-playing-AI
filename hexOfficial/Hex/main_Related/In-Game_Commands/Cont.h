
int canSwap(int swap, char pc);
int doSwap(char **table, int size, coordinates *move_arr, int *didSwap);
int isValidPCMove(char **table, int size, int j, int i);

void playCenter(int *let, int *num, int size);
void doYourBest(char **table, char pc, int size, int swap, int difficulty, int **Edsger, int *let, int *num);
void randomMove(char **table, int size, int *let, int *num);
void updateBoardPC(char **table, char pc, int let, int num);
void updateMoveArrayPC(coordinates *array, int let, int num);
void movePlayedPC(int let, int num);