#ifndef INVENTORY_H
#define INVENTORY_H
#include "Constants.h" 
#include "GameObjects.h" 

class Stockable ; 
class Inventory{
public:
	Inventory();	
	virtual ~Inventory(); 
	

	/*inventory management : returns -1 if can't operate*/
	
	virtual OPERATION_STATUS add(Stockable &s); 
	//retrieves an item , deletes it from the structure
	virtual Stockable retrieve(Stockable s);
	//retrieves the nth element , deletes it from the structure
	virtual OPERATION_STATUS retrieve(int n); 
	

private:
	std::vector<Stockable> inventory ;  


};

















#endif
