
char **createBoard(int size);
void initBoard(char** table, int size);
void freeBoard(char **table, int size);
int **createInitDijkstra(int size);
void freeDijkstra(int **array, int size);
coordinates *createMoveArray(int size);
void freeMoveArray(coordinates *array);
void initVariables(int *win, int *didSwap, char *currentplayer, int *size, int *difficulty, int *swap, char *user, char *pc);
