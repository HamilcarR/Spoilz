#ifndef GRID_H
#define GRID_H
#include "Constants.h" 
#include "GameObjects.h" 

static constexpr int GRID_WIDTH = 10 ; 
static constexpr int GRID_HEIGHT = 10 ;



/*tile type*/
class Tile{
public:
	Tile(Object &object) ; 	
	virtual ~Tile() ; 
	Tile(const Tile& tile){_symbol = tile._symbol ; } ;  
	
	virtual bool changeType(Object &new_symbol) ; 

	Object _symbol ; 

};











/*defines the map of the game */
class GRID {
	


};

















#endif
