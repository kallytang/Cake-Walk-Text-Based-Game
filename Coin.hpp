/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Corn class speficiation file.
**					Child class inherits from Parent Class IventoryItem
*************************************************************************/
#include"InventoryItem.hpp"
#ifndef COIN_HPP
#define COIN_HPP

class Coin :public InventoryItem
{
private:

public: 
	Coin(); 
	int getType() override;
	~Coin()override; 
};

#endif 
