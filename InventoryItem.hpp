#include<string>

#ifndef INVENTORYITEM_HPP
#define INVENTORYITEM_HPP

class InventoryItem
{
protected:
	std::string itemName; 
	int type; 
	

public: 
	InventoryItem(); 
	virtual std::string getName();
	virtual int getType()=0; 
	virtual ~InventoryItem(); 


};



#endif 
