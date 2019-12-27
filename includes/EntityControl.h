#ifndef ENTITYCONTROL_H
#define ENTITYCONTROL_H
#include "GameObjects.h"
#include "Inventory.h"
#include "Constants.h"
#include "Grid.h" 
#include "EntityAI.h" 



typedef std::vector<std::vector<GAME_SYMBOLS_ENUM>> SYMBOLS_MAP ; 


/*abstract class for the player , and the ennemy */
class EntityControl : public Object{
public :
	  EntityControl(int x , int y , int life , GAME_SYMBOLS_ENUM symbol); 
	  virtual std::string processInput(int input , SYMBOLS_MAP &tiles) = 0 ; 
	  virtual void moveup(SYMBOLS_MAP &tiles);
	  virtual void movedown(SYMBOLS_MAP &tiles);
	  virtual void moveleft(SYMBOLS_MAP &tiles);
	  virtual void moveright(SYMBOLS_MAP &tiles);	
	  virtual bool hasChangedRoom() const {return _switched_room;}; 
	  virtual void newRoom() {_switched_room = false ; } ; 
	  virtual void processObject() = 0 ; 
	  virtual void setGrid(Grid *grid){_grid = grid ; } ;

protected :
	 
	 Inventory _inventory ; 	
	 GAME_SYMBOLS_ENUM _object_on_foot ; //What object is the entity standing uppon?
  	 bool _switched_room ; //true if the entity went to another room
	 Grid *_grid ; //only a pointer on the grid data structure , no initialization or destruction required here 


};

#endif
