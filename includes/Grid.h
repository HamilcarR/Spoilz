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

	Object _symbol ; //what it is (chest , wall , lava etc) and how it will be represented  

};




/****************************************************************************************************/
/*the game's grid is made of rooms
 * rooms can be regular rooms or corridors between rooms */

class Room{
public:
	Room();
	virtual ~Room();
	void generateRoom() ; 


private:
	std::vector<std::vector<Tile>> _tiles;
	std::vector<Gate> _gates ; 
};




/****************************************************************************************************/
/*defines the map of the game */

class Grid {
public:
	Grid();
	virtual ~Grid() ; 
	
	std::vector& getGrid() const {return _grid;} ;
	OPERATION_STATUS addRoom(Room &room) {_grid.push_back(room); } ; 


private:
	std::stack<Room> _grid ; //this will behave as a stack : randomly generated rooms will be stored 	


};

















#endif
