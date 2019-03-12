
#include <stdlib.h>

#include "list_operations.h"

int length(int gametile, char player){ // This function determines whether we need one move, no moves or if we can't fill(Infinite) the gametile
	if (gametile == 'n') return 1; //The tile in the board is empty thus it requires 1 move to fill it
	else if (gametile == player) return 0; //The tile in the board is the color of the player's color thus it requires 0 moves to fill it
	else return INF; // The color of the tile is the opponent's color thus it can't be filled so INF(infinity) 
}

void empty_the_list(Tile_Pointer *Q){
	Tile_Pointer temp_p;
	while ( *Q != NULL){
		temp_p = *Q;
		*Q = (*Q)->next;
		free(temp_p);
	}
	return;
}
void insert_at_start(Tile_Pointer* Q,int i, int j, int length, int** moves){ // Fill the list Q  with the gametiles of the board ( i,j coordinates of the tile)
	Tile_Pointer templist; 
	templist = *Q;
	*Q = malloc(sizeof(struct tile_coordinates));
	if (*Q == NULL) exit(-3);
	(*Q)->x = i;
	(*Q)->y = j;
	moves[i][j] = length;
	(*Q)->next = templist;
}

void insert(Tile_Pointer* Q,int i, int j, int length, int** moves){
	int temp_x, temp_y;
	Tile_Pointer temp_p;
	temp_x = (*Q)->x;
	temp_y = (*Q)->y;
	temp_p = (*Q)->next;
	(*Q)->x = i;
	(*Q)->y = j;
	(*Q)->next = malloc(sizeof(struct tile_coordinates));
	((*Q)->next)->next = temp_p;
	((*Q)->next)->x = temp_x;
	((*Q)->next)->y = temp_y;
	moves[i][j] = length;
	
	
}

void erase(Tile_Pointer* Q, int i, int j){
	while ( *Q != NULL){
		if ((*Q)->x == i && (*Q)->y == j){
			Tile_Pointer temp_p;
			temp_p = *Q;
			*Q = (*Q)->next;
			free(temp_p);
			return;
		}
		Q = &((*Q)->next);
	}
}

struct tile_coordinates extract(Tile_Pointer *Q){	
	struct tile_coordinates minimum;
	Tile_Pointer temp_p = *Q;
	minimum.x = (*Q)->x;
	minimum.y = (*Q)->y;
	*Q = (*Q)->next;
	free(temp_p);
	return minimum;
}

void decrease_priority(Tile_Pointer* Q,int ** moves, int size, int i, int j, int distance){
  if (moves[i][j] == -1) return;
	if ( moves[i][j] <= distance) return;
	while ( *Q != NULL){
		if ((*Q)->x == i && (*Q)->y == j){
				moves[i][j] = distance;
			return;
		    }	
		if (moves[(*Q)->x][(*Q)->y] > distance){
			erase(Q,i,j);
			insert(Q,i,j,distance, moves);
			return;
		}
		if (moves[(*Q)->x][(*Q)->y] == INF) break;
		Q = &((*Q)->next);
	}
}

void adjacent_tiles(char** gameboard , int** moves,Tile_Pointer Q ,int size, int i, int j ,char player){
	int x;
	if ( i == size && j == 1){
		for (x = 0 ; x < size ; x++){
		if (length(gameboard[x][0],player) != INF)
		decrease_priority(&Q, moves, size, x, 0,moves[i][j] + length(gameboard[x][0],player));
	    }
	}
	else if ( i == size && j == 0){
		for (x = 0 ; x < size ; x++){
		if (length(gameboard[0][x],player) != INF)
		decrease_priority(&Q, moves, size, 0, x, moves[i][j] + length(gameboard[0][x],player));
	    }
	}
	else{
		if (i+1 < size)
		if (length(gameboard[i+1][j],player) != INF)
		decrease_priority(&Q, moves, size, i+1, j, moves[i][j] + length(gameboard[i+1][j],player));
		if (i-1 >=0)
		if (length(gameboard[i-1][j],player) != INF)
		decrease_priority(&Q, moves, size, i-1, j, moves[i][j] + length(gameboard[i-1][j],player));
		if (j+1 < size)
		if (length(gameboard[i][j+1],player) != INF)
		decrease_priority(&Q, moves, size, i, j+1, moves[i][j] + length(gameboard[i][j+1],player));
		if (j-1 >= 0)
		if (length(gameboard[i][j-1],player) != INF)
		decrease_priority(&Q, moves, size, i, j-1, moves[i][j] + length(gameboard[i][j-1],player));
		if (i+1 < size && j-1 >= 0)
		if (length(gameboard[i+1][j-1],player) != INF)
		decrease_priority(&Q, moves, size, i+1, j-1, moves[i][j] + length(gameboard[i+1][j-1],player));
		if (i-1 >= 0 && j+1 < size)
		if (length(gameboard[i-1][j+1],player) != INF)
		decrease_priority(&Q, moves, size, i-1, j+1, moves[i][j] + length(gameboard[i-1][j+1],player));
	}
}
