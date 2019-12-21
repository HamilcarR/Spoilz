#include "../includes/Grid.h"

Tile::Tile(Object &sym){
	_symbol = sym ; 


}

Tile::~Tile(){


}





/****************************************************************************************************/



Room::Room(){
	for(int i = 0 ; i < GRID_WIDTH ; i++)
		_tiles[i].reserve(GRID_HEIGHT*sizeof(Tile));

}


Room::~Room(){


}


void Room::generateRoom(){
	


}
