// File *Dijkstra.c*
// This algorithm is used as the evaluation function in the ab_pruning algorithm
#include <stdio.h>
#include <limits.h>

#include "list_operations.h"
#include "dijkstra.h"

int Dijkstra(char** gameboard,int size, int** moves){ //It will calculate how many moves ahead the player is in order to win
	struct tile_coordinates tile;
	Tile_Pointer Q;
	Q = NULL;
	int i,j,white_moves,black_moves;
	for (i = size - 1 ; i >=0 ; i--)
	    for ( j = size - 1 ; j >=0 ; j--){	
	        insert_at_start(&Q,i,j, INF, moves);
	}
	insert_at_start(&Q,size,0, 0, moves);
	while (1){
		tile = extract(&Q);
		if (tile.x == size - 1) break;
		if (moves[tile.x][tile.y] == INF) break;
		adjacent_tiles(gameboard, moves, Q ,size, tile.x ,tile.y , 'w');
		moves[tile.x][tile.y] = -1;
	}
	if (moves[tile.x][tile.y] == INF) return INT_MIN + 1;
	else if (moves[tile.x][tile.y] == 0) return INT_MAX;
	white_moves = moves[tile.x][tile.y];
	empty_the_list(&Q);
	moves[size][1] = 0;
	 for (i = size -1 ; i >= 0 ;  i--)
	    for ( j = size - 1 ; j >=0 ; j--){	    	
	        insert_at_start(&Q,j,i, INF, moves);
	    }
	insert_at_start(&Q,size,1 , 0 , moves);
	while (1){
		tile = extract(&Q);
		if (tile.y == size - 1) break;
		adjacent_tiles(gameboard, moves ,Q ,size, tile.x ,tile.y , 'b');
		moves[tile.x][tile.y] = -1;
	}
	black_moves = moves[tile.x][tile.y];
	empty_the_list(&Q);
	return black_moves - white_moves;
}
