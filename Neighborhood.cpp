/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Neighborhood class implementation file.
**					Child class inhereits from Space
*************************************************************************/
#include"Neighborhood.hpp"
Neighborhood::Neighborhood() :Space()
{
	name = "Neighborhood";
	label = "d";
	shovelTaken = false;
	metalDetectorTaken = false;
	coin1Found = false;
	coin2Found = false;
	
}
/*************************************************************************
* Function Name: printDescription
* Description: Function will print description of room.
**************************************************************************/
void Neighborhood::printDescription()
{
	std::cout << "\nNeighborhood street, there's some tools on the lawns " << std::endl;
	std::cout<<"you could borrow to find some coins, but you have to return them. " << std::endl;
	std::cout << "(Digging up coins takes some work)" << std::endl;
}
/*************************************************************************
* Function Name:  Function Name: actionMenu
* Description: Function displays all possible interactions with room.
*		Function does not take any parameters nor does it return any values.
**************************************************************************/
void Neighborhood::actionMenu()
{
	int choice;
	bool runLoop = true;
	while (runLoop == true)
	{
		std::cout << "\nPlease Choose an option:" << std::endl;
		std::cout << "1. Print the Porch space" << std::endl;
		std::cout << "2. Check the floors" << std::endl;
		std::cout << "3. Go to Lawn 1" << std::endl;
		std::cout << "4. Go to Lawn 2" << std::endl;
		std::cout << "5. Check corner of lawn 1" << std::endl;
		std::cout << "6. Check corner of lawn 2" << std::endl;
		std::cout << "7. Check Bag" << std::endl;
		std::cout << "8. Go back to main menu" << std::endl;
		choice = validateInput(1, 8);

		switch (choice)
		{
		case 1:
		{
			printWholeRoom();
		}
		break;
		case 2:
		{
			displayDroppedItems();
		}
		break;
		case 3:
		{
			checkLawn1();
		}
		break;
		case 4:
		{
			checkLawn2();
		}
		break;
		case 5:
		{
			checkCorner1();
		}
		break;
		case 6:
		{
			checkCorner2();
		}
		break;
		case 7:
		{
			checkBag();
		}
		break;
		case 8:
		{
			runLoop = false;
		}
		break;
		}
	}
}
/*************************************************************************
* Function Name: moveMenu
* Description: Function displays areas users is able to move.
*			Function returns an integer depending on choice by user.
*			Function doesn't take any values as parameter.
**************************************************************************/
int Neighborhood::moveMenu()
{
	int choice, room;
	std::cout << "The area at the left is the " << left->getSpaceName() << std::endl;
	//std::cout << "The area to the right is the" << bottom->getSpaceName() << std::endl;
	
	std::cout << "Please choose an option:" << std::endl;
	std::cout << "1. Go to porch" << std::endl;
	std::cout << "2. Go to Rivals House" << std::endl;
	std::cout << "3. Go back to main menu" << std::endl;

	choice = validateInput(1, 3);
	switch (choice)
	{
	case 1:
	{
		room = 4;
	}
	break;
	case 2:
	{
		room = 2;
	}
	break;
	case 3:
	{
		room = 5;
	}
	break;
	}
	return room;
}
/*************************************************************************
* Function Name: canLeave
* Description: Function determines whether user can leave room, if user
*			did not complete any tasks, user is displayed tasks needed to
*			be completed. 
**************************************************************************/
bool Neighborhood::canLeave()
{
	bool leave; 
	if (shovelTaken == false && metalDetectorTaken == false)
	{
		leave = true;
	}
	else if(shovelTaken == true && metalDetectorTaken == true)
	{
		std::cout << "\n\tYou need to return what you borrowed" << std::endl;
		std::cout<<"(shovel from Lawn 1 and metal detector from Lawn 2)..." << std::endl;
		leave = false;
	}
	else if(shovelTaken == false && metalDetectorTaken == true)
	{
		std::cout << "\n\tYou need to return what you borrowed(metal detector from Lawn 2)..." << std::endl;
		leave = false;
	}
	else if(shovelTaken == true && metalDetectorTaken == false)
	{
		std::cout << "\n\tYou need to return what you borrowed(shovel from Lawn 1)..." << std::endl;
		leave = false;
	}
	return leave;
}
/*************************************************************************
* Description: Function will check Lawn 1, function allows uer
*			take or put back shovel.
*************************************************************************/
void Neighborhood::checkLawn1()
{
	int choice; 
	if (shovelTaken == false)
	{
		std::cout << "\nTake the shovel?" << std::endl;
		std::cout << "1. Yes\n";
		std::cout << "2. No\n";
		choice = validateInput(1, 2);
		switch (choice)
		{
		case 1:
		{
			shovelTaken = true;
		}
		break;
		case 2:
		{
			//do nothing 
		}
		break;
		}
	}
	else
	{
		std::cout << "\nPut back shovel?" << std::endl;
		std::cout << "1. Yes\n";
		std::cout << "2. No\n";
		choice = validateInput(1, 2);
		switch (choice)
		{
		case 1:
		{
			shovelTaken = false; 
		}
		break;
		case 2:
		{
			//do nothing 
		}
		break;
		}
	}
}
/*************************************************************************
* Description: Function will check Lawn 2, function allows uer
*			take or put back metal detector.
*************************************************************************/
void Neighborhood::checkLawn2()
{
	int choice;
	if (metalDetectorTaken == false)
	{
		std::cout << "\nTake the metal detector?" << std::endl;
		std::cout << "1. Yes\n";
		std::cout << "2. No\n";
		choice = validateInput(1, 2);
		switch (choice)
		{
		case 1:
		{
			metalDetectorTaken = true; 
		}
		break;
		case 2:
		{
			//do nothing
		}
		break;
		}
	}
	else
	{
		std::cout << "\nPut back metal detector?" << std::endl;
		std::cout << "1. Yes\n";
		std::cout << "2. No\n";
		choice = validateInput(1, 2);
		switch (choice)
		{
		case 1:
		{
			metalDetectorTaken = false; 
		}
		break;
		case 2:
		{
			//do nothing 
		}
		break;
		}
	}
}
/*************************************************************************
* Description: Function will check corner of Lawn 1, function allows uer
*			to find a coin if shovel is taken and metal detector is taken.
*			If coin is already taken user can't get anymore coins.
*************************************************************************/
void Neighborhood::checkCorner1()
{
	int choice;
	if (metalDetectorTaken==true && shovelTaken== true)
	{
		std::cout << "\n Do you want to look for coin?" << std::endl;
		std::cout << "1. Yes\n";
		std::cout << "2. No\n";
		choice = validateInput(1, 2);
		switch (choice)
		{
		case 1:
		{
			if (coin1Found == false)
			{
				std::cout << "You found a coin." << std::endl;
				character->decrementHealth(2);
				character->addToBag(new Coin);
				coin1Found = true;
			}
			else
			{
				std::cout << "There's no more coins to be found. There's only a hole in the lawn..." << std::endl;
			}
		}
		break;
		case 2:
		{
			//do nothing
		}
		break;
		}

		
	}
	else if (metalDetectorTaken == false && shovelTaken == true)
	{
		std::cout << "\nGot the shovel, but you need metal detector to find coin." << std::endl;
		std::cout << "\t(go to Lawn 2 for metal detector )" << std::endl;
	}
	else if (metalDetectorTaken == true && shovelTaken == false)
	{
		std::cout << "\nGot the metal detector...need shovel to dig out coins." << std::endl;
		std::cout << "\t(go to Lawn 1 for shovel)" << std::endl;
	}
	else if (metalDetectorTaken == false && shovelTaken == false)
	{
		std::cout << "\nYou don't have a shovel and a metal detector to find coins" << std::endl;
		std::cout << "\t(go to Lawn 1 for shovel and Lawn 2 for metal detector)" << std::endl;
	}
}
/*************************************************************************
* Description: Function will check corner of Lawn 2, function allows uer
*			to find a coin if shovel is taken and metal detector is taken.
*			If coin is already taken user can't get anymore coins.
*************************************************************************/
void Neighborhood::checkCorner2()
{
	int choice;
	if (metalDetectorTaken == true && shovelTaken == true)
	{
		std::cout << "\n Do you want to look for coin? Takes 2 energy points" << std::endl;
		std::cout << "1. Yes\n";
		std::cout << "2. No\n";
		choice = validateInput(1, 2);
		switch (choice)
		{
		case 1:
		{
			if (coin2Found == false)
			{
				std::cout << "You found a coin." << std::endl;
				character->decrementHealth(2);
				character->addToBag(new Coin);
				coin2Found = true;
			}
			else
			{
				std::cout << "There's no more coins to be found. There's only a hole in the lawn..." << std::endl;
			}
		}
		break;
		case 2:
		{
			//do nothing 
		}
		break;
		}
		
	}
	else if (metalDetectorTaken == false && shovelTaken == true)
	{
		std::cout << "\nGot the shovel, but you need metal detector to find coin." << std::endl;
		std::cout << "\t(go to Lawn 2 for metal detector )" << std::endl;
	}
	else if (metalDetectorTaken == true && shovelTaken == false)
	{
		std::cout << "\nGot the metal detector...need shovel to dig out coins." << std::endl;
		std::cout << "\t(go to Lawn 1 for shovel)" << std::endl;
	}
	else if (metalDetectorTaken == false && shovelTaken == false)
	{
		std::cout << "\nYou don't have a shovel and a metal detector to find coins" << std::endl;
		std::cout << "\t(go to Lawn 1 for shovel and Lawn 2 for metal detector)" << std::endl;
	}
}
/*************************************************************************
* Function Name: printWhole Room
* Description: Function will print map of indivisual space object.
*		Function does not take nor return any values.
**************************************************************************/
void Neighborhood::printWholeRoom()
{
	std::cout << "______________________________________________________________" << std::endl;
	std::cout << "|             |                            |                 |" << std::endl;
	std::cout << "|    Lawn 1   |                            |     Lawn 2      |" << std::endl;
	std::cout << "|             |                            |                 |" << std::endl;
	std::cout << "|_____________|____________________________|_________________|" << std::endl;
	std::cout << "                         sidewalk                           " << std::endl;
	std::cout << "_____________________________________________________________" << std::endl;
	std::cout << "|                                                            |" << std::endl;
	std::cout << "|                           street                           |" << std::endl;
	std::cout << "|____________________________________________________________|" << std::endl;

}
/*************************************************************************
* Description: Destructor for class, will delete all objects in
*		droppedItems container.
**************************************************************************/
Neighborhood::~Neighborhood()
{
	unsigned int i;
	if (!droppedItems.empty())
	{
		for (i = 0; i < droppedItems.size(); i++)
		{
			delete droppedItems[i];
		}
	}
}