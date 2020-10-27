/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the BakingSoda class speficiation file.
**					Child class inherits from Parent Class IventoryItem
*************************************************************************/
#include"InventoryItem.hpp"

#ifndef	BAKINGSODA_HPP
#define BAKINGSODA_HPP

class BakingSoda:public InventoryItem
{
private:
public: 
	BakingSoda();
	int getType() override;
	~BakingSoda()override;
};

#endif // !

