/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Cornclass speficiation file.
**					Child class inherits from Parent Class IventoryItem
*************************************************************************/
#include"InventoryItem.hpp"
#ifndef CORN_HPP
#define CORN_HPP

class Corn :public InventoryItem
{
private:

public:
	Corn();
	int getType() override;
	~Corn()override;
};

#endif 

