#ifndef GRID_H
#define GRID_H
#include "Constants.h" 
#include "GameObjects.h" 
#include "ObjectDistribution.h"

static constexpr int GRID_WIDTH = 20 ; 
static constexpr int GRID_HEIGHT = 20 ;

/*tile type*/
class Tile{
public:
	Tile() ; 
	Tile(Object &object) ; 
	Tile(const Tile &tile) ; 
	virtual ~Tile() ; 

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
	void describe() ; 
	
	std::vector<std::vector<Tile>> getTiles(){return _tiles;} ; 
private:
	std::vector<std::vector<Tile>> _tiles;
};




/****************************************************************************************************/
/*defines the map of the game */

class Grid {
public:
	Grid();
	virtual ~Grid() ; 
	
	std::stack<Room> getGrid() const {return _grid;} ;
	void addRoom(Room room) {_grid.push(room); } ; 
	Room getRoom(){return _grid.top();};
	void createRoom() ; 

private:
	std::stack<Room> _grid ; //this will behave as a stack : randomly generated rooms will be stored 	


};

















#endif
