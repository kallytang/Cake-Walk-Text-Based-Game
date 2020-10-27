/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Eggs class implementation file.
**					Child class inherits from Parent Class IventoryItem
**************************************************************************/
#include"Eggs.hpp"
Eggs::Eggs()
{
	itemName = "Eggs";
	type = 4;
}
int Eggs::getType()
{
	return type;
}
Eggs::~Eggs()
{

}