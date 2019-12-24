#include "../includes/Grid.h"

Tile::Tile(){
	_symbol = Object(0 , 0 , TILE_CLEAR) ; 

}

Tile::Tile(Object &sym){
	_symbol = sym ; 


}


Tile::Tile(const Tile& tile){
	_symbol = tile._symbol ; 


}



Tile::~Tile(){


}

bool Tile::changeType(Object &new_symbol){
	_symbol = new_symbol ; 
	return true ; 

}



/****************************************************************************************************/



Room::Room(){

	_tiles = std::vector<std::vector<Tile>>() ; 
	for(int i = 0 ; i < GRID_HEIGHT ; i++){
		_tiles.push_back( std::vector<Tile>()) ; 
		for(int j = 0 ; j < GRID_WIDTH ; j++){
			Object object(j , i , TILE_CLEAR) ; 
			_tiles[i].push_back(object) ; 
		}


	}
	generateRoom();
}


Room::~Room(){


}

/*places a wall around the room*/
static void put_walls(std::vector<std::vector<Tile>> &tiles) {
	for(int i = 0 ; i < GRID_WIDTH ; i++){
		Object object = Object(0 , i , TILE_WALL); 
		tiles[0][i].changeType(object) ; 
		tiles[GRID_HEIGHT-1][i].changeType(object); 

	}
	for(int i = 0 ; i < GRID_HEIGHT ; i++){
		Object object = Object(i , 0 , TILE_WALL); 
		tiles[i][0].changeType(object) ; 
		tiles[i][GRID_WIDTH-1].changeType(object); 

	}


}

/*randomly spawn 2 gates max and maybe one secret gate*/
static void put_gates(std::vector<std::vector<Tile>> &tiles) {
	bool gate_spawned = false ; 
	int max_gates = 0 ; 
	int max_secret = 0 ; 
	for(int i = 0 ; i < GRID_HEIGHT ; i++)
		for(int j = 0 ; j < GRID_WIDTH ; j++){
			float gate_proba = get_rand() ;
			float secret_proba = get_rand() ;
			if(gate_proba < GATE_SPAWN_PROBA && max_gates < MAX_GATE_COUNT ){ //creates gates
				gate_spawned = true ; 
				Object gate(j , i , TILE_GATE) ; 
				tiles[i][j] = gate ; 
				max_gates ++ ; 
			}
			if(secret_proba < SECRET_GATE_SPAWN_PROBA && max_secret < MAX_SECRET_GATE_COUNT ){//creates secret gates
				Object secret_gate(j , i , TILE_SECRET_GATE) ; 
				tiles[i][j] = secret_gate ; 
				max_secret ++ ; 

			}
		}
	if(!gate_spawned){
	Object gate((int)(GRID_WIDTH/2) , 0 , TILE_GATE);
	tiles[0][(int) (GRID_WIDTH/2) ].changeType(gate) ; 
	}
}


/*randomly spawn maximum MAX_LOOT_ROOM loots , only on free tiles */
static void put_loot(std::vector<std::vector<Tile>> &tiles) {
	int max_loot = 0 ; 
	for(int i = 0 ; i < GRID_HEIGHT ; i++)
		for(int j = 0 ; j < GRID_WIDTH ; j++){

			if(tiles[j][i]._symbol.getType() == TILE_CLEAR){
			
				int loot_type = rand()%LOOT_TABLE.size()-1 ;
				if(get_rand() < LOOT_PROBA && max_loot < MAX_LOOT_ROOM  ){
					Object loot = Object(j , i , LOOT_TABLE[loot_type]) ; 
					tiles[i][j].changeType(loot);
					max_loot++ ; 
				}
			}
				

		}

}



void Room::generateRoom(){
	put_walls(_tiles); 
	put_gates(_tiles); 
	put_loot(_tiles) ; 

}




void Room::describe(){

	for(auto A : _tiles){
		std::cout << "\n" ; 
		for(auto B : A){
		std::cout << SYMBOLS_CHAR[B._symbol.getType()] <<" " ;  
		}
	}

}


/****************************************************************************************************/




Grid::Grid(){

	initialize_rand();
	createRoom();

}

Grid::~Grid(){


}

void Grid::createRoom(){
	Room room = Room() ; 
	addRoom(room) ;
}












