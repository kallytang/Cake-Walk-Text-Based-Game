/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Kitchen class implementation file.
**					Child class inhereits from Space
*************************************************************************/
#include "LivingRoom.hpp"

/*************************************************************************
* Function Name: LivingRoom
* Description: Default constructor.
**************************************************************************/
LivingRoom::LivingRoom()
{
	name = "Living Room";
	label = "b";
	coinTaken = false; 
	coin1 = new Coin;
}
/*************************************************************************
* Function Name: printDescription
* Description: Function will print description of room.
**************************************************************************/
void LivingRoom::printDescription()
{
	std::cout << name << "'s Living room, there might be some spare change in the couch" << std::endl;
}
/*************************************************************************
* Function Name Function Name: actionMenu
* Description: Function displays all possible interactions with room.
*		Function does not take any parameters nor does it return any values.
**************************************************************************/
void LivingRoom::actionMenu()
{
	int choice;
	bool runLoop = true;
	while (runLoop == true)
	{
		std::cout << "\nPlease Choose an option:" << std::endl;
		std::cout << "1. Print the Living room space" << std::endl;
		std::cout << "2. Check the floors" << std::endl;
		std::cout << "3. Check couch cusions" << std::endl;
		std::cout << "4. Check Bag" << std::endl;
		std::cout << "5. Go back to main menu" << std::endl;
		choice = validateInput(1, 7);

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
			checkCouch(); 
		}
		break;
		case 4:
		{
			checkBag();
		}
		break;
		case 5:
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
int LivingRoom::moveMenu()
{
	int choice, room;
	std::cout << "The area to the bottom is the" << bottom->getSpaceName() << std::endl;
	std::cout << "The room at the top is the " << top->getSpaceName() << std::endl; 
	std::cout << "Please choose an option:" << std::endl;
	std::cout << "1. Go to Kitchen" << std::endl;
	std::cout << "2. Go outside to the porch" << std::endl;
	std::cout << "3. Go back to main menu" << std::endl;

	choice = validateInput(1, 3);
	switch (choice)
	{
	case 1: 
	{
		room = 1;
	}
	break;
	case 2:
	{
		room = 3;
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
* Description: Function will return a value of true, allowing user to 
*		to leave room. 
**************************************************************************/
bool LivingRoom::canLeave()
{

	return true; 
}
/*************************************************************************
* Function Name: printWhole Room 
* Description: Function will print map of indivisual space object. 
*		Function does not take nor return any values. 
**************************************************************************/
void LivingRoom::printWholeRoom()
{
	std::cout << "\t_________________________________            |" << std::endl;
	std::cout << "\t|             |    TV       |                |" << std::endl;
	std::cout << "\t|             |_____________|                |" << std::endl;
	std::cout << "\t|                                            |" << std::endl;
	std::cout << "\t|                                         ___|" << std::endl;
	std::cout << "\t|                                        |   |" << std::endl;
	std::cout << "\t|                                        | c |" << std::endl;
	std::cout << "\t|                                        | l |" << std::endl;
	std::cout << "\t|______          ___________             | o |" << std::endl;
	std::cout << "\t|   c  |        |          |             | s |" << std::endl;
	std::cout << "\t|   o  |        | table    |             | e |" << std::endl;
	std::cout << "\t|   u  |        |__________|             | t |" << std::endl;
	std::cout << "\t|   c  |                                 |   |" << std::endl;
	std::cout << "\t|   h  |                                 |   |" << std::endl;
	std::cout << "\t|      |                                 |   |" << std::endl;
	std::cout << "\t|      |________________                 |   |" << std::endl;
	std::cout << "\t|                       |                |___|" << std::endl;
	std::cout << "\t|                       |                    |" << std::endl;
	std::cout << "\t|_______________________|____                |" << std::endl;
}
/*************************************************************************
* Function Name: checkCouch
* Description: Function allows user to check couch. If coin has not been
*		taken user is able to take the coin.
*		If user has taken coin, user is displayed a message that there's
*		no coins. 
**************************************************************************/
void LivingRoom::checkCouch()
{
	int choice;

	if (coinTaken == false)
	{
		std::cout <<"\nYou found a coin" << std::endl;
		std::cout << "Do you want to add it to your bag?" << std::endl;
		std::cout << "1. Yes\n";
		std::cout << "2. No\n";

		choice = validateInput(1, 2);
		if (choice == 1)
		{
			if (character->bagFull() == true)
			{
				std::cout << "\nYour bag is full... can't take the coin" << std::endl;
			}
			else
			{
				character->addToBag(coin1);
				coin1 = nullptr;
				coinTaken = true; 
			}
			
		}
	}
	else
	{
		std::cout << "There's nothing in the couch but some dust bunnies" << std::endl;
	}
	

}
/*************************************************************************
* Description: Destructor, will delete all objects that were created in
*		class or any objects in droppedItems vector. 
**************************************************************************/
LivingRoom::~LivingRoom()
{
	if (coinTaken == false)
	{
		delete coin1; 
	}
	delete character;
	unsigned int i;
	if (!droppedItems.empty())
	{
		for (i = 0; i < droppedItems.size(); i++)
		{
			delete droppedItems[i];
		}
	}
	 
}