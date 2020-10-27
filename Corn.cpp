/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Cornclass speficiation file.
**					Child class inherits from Parent Class IventoryItem
*************************************************************************/

#include"Corn.hpp"
/*************************************************************************
* Description: Default Constructor
**************************************************************************/
Corn::Corn() :InventoryItem()
{
	itemName = "Corn";
	type = 2;
}
/*************************************************************************
* Function Name:
* Description:
**************************************************************************/
int Corn::getType()
{
	return type;
}
/*************************************************************************
* Function Name:
* Description:
**************************************************************************/
Corn::~Corn()
{

}
