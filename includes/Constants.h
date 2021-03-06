#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <array>
#include <ctime> 
#include <stack>
#include <algorithm>
#include <ncurses.h>
#include <assert.h>







static bool rand_initialized = false ; 

static void initialize_rand(){
	if(!rand_initialized)
		srand(time(NULL)); 
	rand_initialized = true ; 
}

static float get_rand(){
	
	return ((float)rand()/(RAND_MAX))  ; 

}



/*defines a position*/
struct VECT{
	int x ; 
	int y ; 


};


/*What type of gui : curses or rendered*/
typedef enum VIEW_MODE { VIEW_MODE_CURSES = 0 , VIEW_MODE_GUI  } VIEW_MODE; 

/*defines the symbol of an object , and how it will be represented on screen 
 * used as indexes in array , 
 * TILE_CHEST always 0 and TILE_CLEAR always last for array operations
 */ 
typedef enum  GAME_SYMBOLS_ENUM { 
	TILE_CHEST = 0 , 
	TILE_WALL  , 
	TILE_LAVA  , 
	TILE_GATE  ,
	TILE_SECRET_GATE , 
	TILE_GOLD_COIN , 
	TILE_SILVER_COIN , 
	TILE_COPPER_COIN , 
	TILE_1H_MACE ,
	TILE_2H_MACE ,
	TILE_FOOD ,
	TILE_HP_POTION , 
	TILE_MANA_POTION , 
	TILE_1H_SWORD , 
	TILE_2H_SWORD , 
	TILE_SPIKED_GLOVES , 
	TILE_PLAYER , 
	TILE_ENEMY ,
	TILE_CLEAR   
} GAME_SYMBOLS_ENUM; 




/*use that for status message*/
static const char* OBJECT_DESCRIPTION[] = {
	"Chest",
	"Wall",
	"Lava",
	"Gate",
	"Secret gate",
	"Gold coin",
	"Silver coin",
	"Copper coin",
	"One handed mace",
	"Two handed mace",
	"Food ration",
	"Life potion",
	"Mana potion",
	"One handed sword",
	"Two handed sword",
	"Spiked gloves",
	"Player",
	"Enemy",
	" " 

};


//Error check for various operations : adding to data structure , retrieving etc
typedef enum  OPERATION_STATUS {
	OPERATION_OK = 0 , 
	OPERATION_KO = -1
}OPERATION_STATUS;


static constexpr int MAX_GATE_COUNT = 2 ; // number of max gates in a room 
static constexpr int MAX_SECRET_GATE_COUNT = 1 ; //secret stuff behind 
static constexpr float WALL_SPAWN_PROBA = 0.1 ; 
static constexpr float GATE_SPAWN_PROBA = 0.01 ;  // probability of a gate spawning
static constexpr float SECRET_GATE_SPAWN_PROBA = 0.001 ; // probability that a secret gate appears
static constexpr float TRAP_SPAWN_PROBA = 0.01 ; //probability of a trap spawning on the map
static constexpr float LOOT_PROBA = 0.002 ; // probability some loot will appear 
static constexpr int   MAX_LOOT_ROOM = 7 ;//Max number of loots in a room 

/*Loot table*/
static constexpr unsigned int LOOT_TABLE_SIZE = 12 ;
static constexpr std::array<GAME_SYMBOLS_ENUM , LOOT_TABLE_SIZE> LOOT_TABLE = { 
							       TILE_CHEST , 
							       TILE_GOLD_COIN , 
							       TILE_SILVER_COIN , 
							       TILE_COPPER_COIN , 
							       TILE_1H_MACE , 
							       TILE_2H_MACE , 
							       TILE_FOOD , 
							       TILE_HP_POTION , 
							       TILE_MANA_POTION , 
							       TILE_1H_SWORD ,
							       TILE_2H_SWORD , 
							       TILE_SPIKED_GLOVES} ; 


/*maximum numbers of objects the player can carry at the beginning */
static unsigned int constexpr START_INV_CAPACITY = 10 ; 

















#endif
