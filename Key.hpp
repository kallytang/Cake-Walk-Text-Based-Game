/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Key class speficiation file.
**					Child class inherits from Parent Class IventoryItem
*************************************************************************/
#include"InventoryItem.hpp"
#ifndef KEY_HPP
#define KEY_HPP

class Key:public InventoryItem
{
private:
public: 
	Key();
	int getType() override;
	~Key();
};
#endif // !
