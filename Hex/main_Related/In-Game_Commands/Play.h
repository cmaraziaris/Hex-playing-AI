
coordinates getMove(void);

int isValidUsersMove(char **table, int size, coordinates move);

void updateBoardUser(char **table, char user, coordinates move);
void updateMoveArrayUser(coordinates *array, coordinates move);
void updateLastEnemyMove(int size, coordinates move);
void movePlayedUser(coordinates move);