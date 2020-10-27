/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Key class speficiation file.
**					Child class inherits from Parent Class IventoryItem
*************************************************************************/
#include"Key.hpp"
Key::Key():InventoryItem()
{
	itemName = "Key";
	type = 1;
}

int Key::getType()
{
	return type; 
}

Key::~Key()
{

}