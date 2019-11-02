/*                Difficulty modifier is a key function of                     */
/* the competitive-level version of Hexie. It enables Hexie to utilise         */
/* effectively the Bridge-Building heuristic early in the game, and it enables */
/* her to set the highest depth possible on AB pruning, in order to maximize   */
/* the use of Dijkstra's algorithm.                                            */
/* Dyn.Difficulty should be removed for the standard version of Hexie because  */
/* it's misleading regarding the actual difficulty in which the AI performs    */



#include "../Basic_Headers/globals.h"

#include "dynDiff.h"

void dynamicDifficulty(int *difficulty, int size){
  
  if (size == 5){    /* SOS */                  /* SOS tags mark the size every opponent of ours */
    if (movecount <= 7) *difficulty = 1;        /* had chosen to play at the Hex competition.    */
    else *difficulty = 7;
    return;
  }

  if (size == 6){    /* SOS */
    if (movecount <= 7) *difficulty = 1;
    else *difficulty = 5;  
    return;
  }

  if (size == 11){
    if (movecount <= 13) *difficulty = 1;
    else *difficulty = 3;
    return;
  }

  if (size == 12){     /* SOS */
    if (movecount <= 14) *difficulty = 1;
    //else if (movecount <= 23) *difficulty = 4;
    else *difficulty = 3;
    return;
  }

  if (size == 21){     /* SOS */
    if (movecount <= 30) *difficulty = 1;
    
    else *difficulty = 1;
    return;
  }

/* The followings sizes were not taken deeply into   */
/* consideration thus long waiting times may occur.  */
/*****************************************************/


  if (size == 4)
    if (movecount <= 3) *difficulty = 1;
    else *difficulty = 10;


  if (size == 7)
    if (movecount <= 9) *difficulty = 1;
    else *difficulty = 5;

  if (size == 8)
    if (movecount <= 9) *difficulty = 1;
    else *difficulty = 4;
    //
  if (size == 9)
    if (movecount <= 9) *difficulty = 1;
    else if (movecount <= 30) *difficulty = 4;
    else *difficulty = 3;

  if (size == 10)
    if (movecount <= 11) *difficulty = 1;
    else if (movecount <= 18) *difficulty = 4;
    else *difficulty = 3;    





  if (size == 13)
    if (movecount <= 16) *difficulty = 1;
    else *difficulty = 2;

  if (size == 14)
    if (movecount <= 16) *difficulty = 1;
    else *difficulty = 2;

  if (size == 15)
    if (movecount <= 19) *difficulty = 1;
    else *difficulty = 2;

  if (size == 16)
    if (movecount <= 19) *difficulty = 1;
    else *difficulty = 2;

  if (size == 17)
    if (movecount <= 22) *difficulty = 1;
    else *difficulty = 2;

  if (size == 18)
    if (movecount <= 22) *difficulty = 1;
    else *difficulty = 2;

  if (size == 19)
    if (movecount <= 25) *difficulty = 1;
    else *difficulty = 2;

  if (size == 20)
    if (movecount <= 30) *difficulty = 1;
    else *difficulty = 2;

  if (size == 22)
    if (movecount <= 30) *difficulty = 1;
    else if (movecount <= 40) *difficulty = 2;
    else *difficulty = 1;
  if (size == 23)
    if (movecount <= 30) *difficulty = 1;
    else *difficulty = 2;
  if (size == 24)
    if (movecount <= 30) *difficulty = 1;
    else if (movecount <= 40) *difficulty = 2;
    else *difficulty = 1;
  if (size == 25)
    if (movecount <= 30) *difficulty = 1;
    else if (movecount <= 40) *difficulty = 2;
    else *difficulty = 1;   
  if (size == 26)
    if (movecount <= 30) *difficulty = 1;
    else if (movecount <= 40) *difficulty = 2;
    else *difficulty = 1;


  return;
}

int decider(int size){      /*  Decides the max # of moves before          */
  switch(size){             /*  Dijkstra's replaces the Bridge heuristic   */
    case 4:  return 3;
    case 5:  return 7; 
    case 6:  return 7; 
    case 7:  return 9; 
    case 8:  return 9; 
    case 9:  return 9;
    case 10:  return 11; 
    case 11:  return 13; 
    case 12:  return 13; 
    case 13:  return 16; 
    case 14:  return 16; 
    case 15:  return 19; 
    case 16:  return 19; 
    case 17:  return 22; 
    case 18:  return 22; 
    case 19:  return 25; 
    case 20:  return 30; 
    case 21:  return 30; 
    case 22:  return 30; 
    case 23:  return 30; 
    case 24:  return 30;  
    case 25:  return 30;  
    case 26:  return 30; 
  }
}