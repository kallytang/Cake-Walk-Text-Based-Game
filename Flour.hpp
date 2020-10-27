/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Flour class speficiation file.
**					Child class inherits from Parent Class IventoryItem
*************************************************************************/
#include"InventoryItem.hpp"
#ifndef FLOUR_HPP
#define FLOUR_HPP

class Flour :public InventoryItem
{
private:
public:
	Flour();
	int getType() override;
	~Flour()override;
};

#endif // !
