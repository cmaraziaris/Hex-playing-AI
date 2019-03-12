
#define INF 10000

typedef struct tile_coordinates* Tile_Pointer;
struct tile_coordinates{
	int x;
	int y;
	Tile_Pointer next;
};

int length(int gametile, char player);
void empty_the_list(Tile_Pointer *Q);
void insert(Tile_Pointer* Q,int i, int j, int length, int** moves);
void insert_at_start(Tile_Pointer* Q,int i, int j, int length, int** moves);
void erase(Tile_Pointer* Q, int i, int j);
void decrease_priority(Tile_Pointer* Q,int ** moves, int size, int i, int j, int distance);
void adjacent_tiles(char** gameboard , int** moves,Tile_Pointer Q ,int size, int i, int j ,char player);
struct tile_coordinates extract(Tile_Pointer *Q);
