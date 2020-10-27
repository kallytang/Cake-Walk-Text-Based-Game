/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Porch class implementation file.
**					Child class inhereits from Space
*************************************************************************/
#include"Porch.hpp"
Porch::Porch()
{
	name ="Porch";
	label= "c";
	top = nullptr;
	right = nullptr;
	left = nullptr;
	bottom = nullptr;
	character = nullptr;
}
/*************************************************************************
* Function Name: printDescription
* Description: Function will print description of room.
**************************************************************************/
void Porch::printDescription()
{
	std::cout << "The front of " << character->getName() << "'s Home" << std::endl;
}
/*************************************************************************
* Function Name:  Function Name: actionMenu
* Description: Function displays all possible interactions with room.
*		Function does not take any parameters nor does it return any values.
**************************************************************************/
void Porch::actionMenu()
{
	int choice;
	bool runLoop = true;
	while (runLoop == true)
	{
		std::cout << "\nPlease Choose an option:" << std::endl;
		std::cout << "1. Print the Porch space" << std::endl;
		std::cout << "2. Check the floors" << std::endl;
		std::cout << "3. Use vending machine" << std::endl;
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
			useVendingMachine();
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
int Porch::moveMenu()
{
	int choice, room;
	//std::cout << "/nThe area to the bottom is the" << bottom->getSpaceName() << std::endl;
	std::cout<<"\nThe area on the right is the "<<right->getSpaceName()<<std::endl;
	std::cout << "The room at the top is the " << top->getSpaceName() << std::endl;
	std::cout << "Please choose an option:" << std::endl;
	std::cout << "1. Go to living room" << std::endl;
	std::cout << "2. Go walk down to farm " << std::endl;
	std::cout << "3. Go walk to the neighborhood " << std::endl;
	std::cout << "4. Go back to main menu" << std::endl;

	choice = validateInput(1, 4);
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
		room = 2; 
	}
	break;
	case 4:
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
bool Porch::canLeave()
{
	return true;
}
/*************************************************************************
* Function Name: useVendingMachine
* Description:
**************************************************************************/
void Porch::useVendingMachine()
{
	int choice; 
	int type;
	bool itemWrong = true;
	InventoryItem* coin;
	std::cout << "\nWould you like to use vending machine?(Requires 1 coin, gives 5 pts of health" << std::endl;
	std::cout << "1. Yes" << std::endl;
	std::cout << "2. No" << std::endl;
	choice = validateInput(1, 2);

	switch (choice)
	{
	case 1:
	{
		if (character->findItem(6)==true)
		{

			std::cout << "Pick an item from bag" << std::endl;
			while (itemWrong == true)
			{
				choice = character->bagMenu();
				if (choice == -1)
				{
					//exit loop
					itemWrong = false;
				}
				else
				{
					choice = choice - 1;

					type = character->getItemType(choice);

					if (type == 6)
					{
						coin = character->takeFromBag(choice);
						delete coin;
						std::cout << "One coin was used" << std::endl;
						itemWrong = false; 
						character->addHealth(5);
						character->printHealthBar();
					}
					else
					{
						std::cout << "That wasn't a coin." << std::endl;
					}
				}
			
			}
		}
		else
		{
			std::cout << "You don't have any coins!" << std::endl;
		}
	}
	break;
	case 2:
	{
		// do nothing; 
	}
	break;
	}

}
/*************************************************************************
* Function Name:
* Description:
**************************************************************************/
void Porch::printWholeRoom()
{
	std::cout << "\t_________________________________                _______" << std::endl;
	std::cout << "\t|                                                        |" << std::endl;
	std::cout << "\t|                                                        |" << std::endl;
	std::cout << "\t|                                                        |" << std::endl;
	std::cout << "\t|                                                        |" << std::endl;
	std::cout << "\t|                          ______________________________|" << std::endl;
	std::cout << "\t|                          |      stairs                 |" << std::endl;
	std::cout << "\t|                          ______________________________|" << std::endl;
	std::cout << "\t|                          |                             |" << std::endl;
	std::cout << "\t|                          ______________________________|" << std::endl;
	std::cout << "\t|                          |                             |" << std::endl;
	std::cout << "\t|                          ______________________________|" << std::endl;
	std::cout << "\t|                          |                             |" << std::endl;
	std::cout << "\t|                          ______________________________|" << std::endl;
	std::cout << "\t|                          |                             |" << std::endl;
	std::cout << "\t|__________________________|_____________________________|" << std::endl;
	std::cout << "\t|                                                        |" << std::endl;
	std::cout << "\t|                                                        |" << std::endl;
	std::cout << "\t|                                                        " << std::endl;
	std::cout << "\t|___________________                                     " << std::endl;
	std::cout << "\t|                   |                                    " << std::endl;
	std::cout << "\t| vending machine   |                                    " << std::endl;
	std::cout << "\t|                   |                                    " << std::endl;
	std::cout << "\t|                   |                                    " << std::endl;
	std::cout << "\t|                   |                                    " << std::endl;
	std::cout << "\t|                   |                                    |" << std::endl;
	std::cout << "\t|_________________________________                   ____|" << std::endl;



}
/*************************************************************************
* Description: Destructor for class, will delete all objects in
*		droppedItems container.
**************************************************************************/
Porch::~Porch()
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