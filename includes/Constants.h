#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <ctime> 



static bool rand_initialized = false ; 

void initialize_rand(){
	if(!rand_initialized)
		srand(time(NULL)); 
	rand_initialized = true ; 
}



//defines the symbol of an object
typedef enum _GAME_SYMBOLS_ENUM { 
	PLAYER = 0 ,
	CHEST = 1 , 
	ENEMY = 2 , 
	TILE_BLOCKED = 3 , 
	TILE_LAVA = 4 , 
	TILE_GATE = 5 , 
	TILE_CLEAR = -1 


} _GAME_SYMBOLS_ENUM; 



//Error check for various operations : adding to data structure , retrieving etc
typedef enum OPERATION_STATUS {
	OPERATION_OK = 0 , 
	OPERATION_KO = -1
}OPERATION_STATUS;



#endif
