#ifndef INVENTORY_H
#define INVENTORY_H
#include "Constants.h" 
#include "GameObjects.h" 




class Inventory{
public:
	Inventory();	
	virtual ~Inventory(); 

	/*inventory management : returns -1 if can't operate*/	
	virtual OPERATION_STATUS add(GAME_SYMBOLS_ENUM object); 
	//retrieves an item , deletes it from the structure
	virtual Stockable retrieve(GAME_SYMBOLS_ENUM object);
	//retrieves the nth element , deletes it from the structure
	virtual OPERATION_STATUS retrieve(int n); 
	

protected:
	unsigned int _maximum_capacity ; 
	std::vector<GAME_SYMBOLS_ENUM> _inventory ;  


};

















#endif
