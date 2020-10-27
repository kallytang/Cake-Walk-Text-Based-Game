/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the BakingSoda class speficiation file.
**					Child class inherits from Parent Class IventoryItem
*************************************************************************/
#include"BakingSoda.hpp"
/*************************************************************************
* Description: Default Constructor
**************************************************************************/
BakingSoda::BakingSoda(): InventoryItem()
{
	itemName = "Baking Soda";
	type = 5;
}
/*************************************************************************
* Description: returns type
**************************************************************************/
int BakingSoda::getType()
{
	return type; 
}
/*************************************************************************
* Description: Destructor
**************************************************************************/
BakingSoda::~BakingSoda()
{

}