
void saveHex(char **table, int *size, char currentplayer);
void loadHex(char ***table, int ***dArray, coordinates **mvArray, int *size, char *currentplayer, int *didSwap, char user);
void isSwapAllowed(char **table, int size, int *didSwap);
void printCurrentPlayer(char currentplayer, char user);
void getBoard(char **table, FILE *fp, int size);
void quitHex(char **table, int **dArray, coordinates *mvArray, int size);