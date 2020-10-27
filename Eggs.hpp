/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Eggs class speficiation file.
**					Child class inherits from Parent Class IventoryItem
*************************************************************************/
#include"InventoryItem.hpp"
#ifndef EGGS_HPP
#define EGGS_HPP

class Eggs:public InventoryItem
{
private:

public:
	Eggs();
	int getType() override;
	~Eggs();
};

#endif // !
