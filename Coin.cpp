/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Corn class implementatoin file.
**					Child class inherits from Parent Class IventoryItem
*************************************************************************/
#include"Coin.hpp"
/*************************************************************************
* Description: Default Constructor
**************************************************************************/
Coin::Coin():InventoryItem()
{
	itemName = "Coin";
	type = 6;
}
/*************************************************************************
* Description: returns type
**************************************************************************/
int Coin::getType()
{
	return type;
}
/*************************************************************************
* Description: Destructor
**************************************************************************/
Coin::~Coin()
{

}


