#include"InventoryItem.hpp"
#include"Character.hpp"
#include<vector>
#include<sstream>
#include<string>
#include<iostream>
#include"BlackCat.hpp"
#include"Coin.hpp"
#include"Corn.hpp"
#include"Eggs.hpp"
#include"BakingSoda.hpp"
#include "Flour.hpp"
#include "Key.hpp"
#include"RivalCat.hpp"

#ifndef SPACE_HPP
#define SPACE_HPP
class Space
{	
		
protected: 
	std::vector<InventoryItem*> droppedItems; 
	std::string name; 
	std::string label; 

	//space pointers 
	Space* top;
	Space* right;
	Space* left;
	Space* bottom;
	Character* character;

public:
	Space(); 
	void setTopSpace(Space*);
	void setBottomSpace(Space*);
	void setRightSpace(Space*);
	void setLeftSpace (Space*);
	Space* getTopSpace(); 
	Space* getBottomSpace(); 
	Space* getLeftSpace();
	Space* getRightSpace(); 
	void setCharacter(Character*);
	Character* getCharacter(); 

	virtual void printDescription() = 0;
	virtual void actionMenu()=0; 
	virtual int moveMenu() = 0; 
	std::string getSpaceName(); 
	std::string getLabel(); 
	virtual bool canLeave()=0; 
	void storeDroppedItems(InventoryItem*); 
	void displayDroppedItems(); 
	void checkBag(); 
	InventoryItem* pickUpDroppedItem(int);
	virtual void printWholeRoom()=0;
	int validateInput(int, int); 
	

	virtual ~Space(); 

};

#endif 
