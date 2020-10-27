/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Kitchen class implementation file.
**					Child class inhereits from Space
*************************************************************************/
#include"Kitchen.hpp"

/*************************************************************************
* Function Name: Kitchen 
* Description: Default constructor
**************************************************************************/
Kitchen::Kitchen() :Space()
{
	character = nullptr; 
	name = "Kitchen";
	label = "a";
	foodEaten = false; 
	checkedFridge = false; 
	checkedCupBd = false; 
	droppedItems.push_back(new Coin);
	top = nullptr;
	right = nullptr;
	left = nullptr;
	bottom = nullptr;
}
/*************************************************************************
* Function Name: printDescription
* Description: Function will print description of room.
**************************************************************************/
void Kitchen::printDescription()
{
	std::cout << character->getName() << "'s Kitchen, check the cupboards and fridge for ingredients you'll need to find. " << std::endl;
}
/*************************************************************************
* Function Name: actionMenu
* Description: Function displays all possible interactions with room.
*		Function does not take any parameters nor does it return any values.
**************************************************************************/
void Kitchen::actionMenu()
{
	int choice;
	bool runLoop = true; 
	while (runLoop == true)
	{
		std::cout << "\nPlease Choose an option:" << std::endl;
		std::cout << "1. Print the Kitchen space" << std::endl;
		std::cout << "2. Check the floors" << std::endl;
		std::cout << "3. Check fridge" << std::endl;
		std::cout << "4. Check cupboards" << std::endl;
		std::cout << "5. Eat Food(can be used once to replenish health)" << std::endl;
		std::cout << "6. Check Bag" << std::endl;
		std::cout << "7. Go back to main menu" << std::endl;

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
			checkFrige();
		}
		break;
		case 4:
		{
			checkCupBoard();
		}
		break;
		case 5:
		{
			eatFood(); 
		}
		break;
		case 6: 
		{
			checkBag(); 
		}
		break;
		case 7:
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
int Kitchen::moveMenu()
{
	int choice, room;
	std::cout << "\nThe room to the bottom is the " << bottom->getSpaceName() << std::endl;
	std::cout << "Please choose an option:" << std::endl;
	std::cout << "1. Go to Living Room" << std::endl;
	std::cout << "2. Go back to main menu" << std::endl;

	choice = validateInput(1, 2);

	if (choice == 1)
	{
		room = 3;
	}
	else
	{
		room = 5;
	}
	return room;

}
/*************************************************************************
* Function Name: canLeave
* Description: Function determines whether user can leave room, if user
*			did not complete any tasks, user is displayed tasks needed to
*			be completed. 
**************************************************************************/
bool Kitchen::canLeave()
{
	bool leave= false; 
	if (checkedFridge == true && checkedCupBd == true)
	{
		leave = true;
	}
	else if (checkedFridge == false && checkedCupBd == true)
	{
		std::cout << "We can't leave yet, we need to check the fridge!" << std::endl;
		leave = false; 
	}
	else if ((checkedFridge == true && checkedCupBd == false))
	{
		std::cout << "We can't leave yet, we need to check the cupboards!" << std::endl; 
		leave = false;
	}
	else if (checkedFridge == false && checkedCupBd == false)
	{
		leave = false;
		std::cout << "We can't leave yet, we need to check the cupboard and fridge!" << std::endl;
	}
	return leave; 
}
/*************************************************************************
* Function Name: printWhole Room
* Description: Function will print map of indivisual space object.
*		Function does not take nor return any values.
**************************************************************************/
void Kitchen::printWholeRoom()
{
	std::cout << "\t___________________________________________________" << std::endl; 
	std::cout << "\t|                 |                               |" << std::endl;
	std::cout << "\t|    Fridge       |      sink/stove/oven area     |" << std::endl;
	std::cout << "\t|                 |                               |" << std::endl;
	std::cout << "\t|_________________|_______________________        |" << std::endl;
	std::cout << "\t|                                        |        |" << std::endl;
	std::cout << "\t|                                        |        |" << std::endl;
	std::cout << "\t|                                        |        |" << std::endl;
	std::cout << "\t|                                        |        |" << std::endl;
	std::cout << "\t|______                                  |________|" << std::endl;
	std::cout << "\t|      |                                          |" << std::endl;
	std::cout << "\t|      |                                          |"<< std::endl;
	std::cout << "\t|      |                                          | " << std::endl;
	std::cout << "\t|      |______________________________ 	          | " << std::endl;
	std::cout << "\t|                                     |           | " << std::endl;
	std::cout << "\t|     Cupboards                       |           |  " << std::endl;
	std::cout << "\t|_____________________________________|           | " << std::endl;

}
/*************************************************************************
* Function Name: checkFridge
* Description: Function is used to check fridge. If user has checked 
*		fridge it sets checkedFridge to true.  Function also
*		displays status messages of whether user has item that is needed
*		if called. 
**************************************************************************/
void Kitchen::checkFrige()
{
	if (character->findItem(4) == false)
	{
		std::cout << "\nWe're out of eggs." << std::endl;
		std::cout << "We need to go visit the hens at the farm.\n" << std::endl;
	}
	else if (character->findItem(4)==true)
	{
		std::cout << "\nWe have eggs in our bag." << std::endl;
	}
	checkedFridge = true;
}
/*************************************************************************
* Function Name: checkCupBoard
* Description: Function allows user to check cupBoard. If user has 
*		checked board, checkedCupBd is set to true. Function also
*		displays status messages of whether user has item that is needed
*		if called.
**************************************************************************/
void Kitchen::checkCupBoard()
{
	if (character->findItem(5) == false && character->findItem(3) == false)
	{
		std::cout << "\nWe're out of flour and baking soda." << std::endl;
		std::cout << "\t(Find flour at the farm and find baking soda in rival's kitchen)" << std::endl;
	}
	else if (character->findItem(5) == true && character->findItem(3) == false)
	{
		std::cout << "\nWe have baking soda but we don't have flour." << std::endl;
		std::cout << "\t(Find flour at the farm)" << std::endl;
	}
	else if (character->findItem(5) == false && character->findItem(3) == true)
	{
		std::cout << "\nWe have flour but not baking soda." << std::endl; 
		std::cout << "\t(Find baking soda in rival's kitchen)" << std::endl;
	}
	checkedCupBd = true; 
}
/*************************************************************************
* Function Name: eatFood
* Description: Function allows user to replenish health only once. 
**************************************************************************/
void Kitchen::eatFood()
{
	if (foodEaten == false)
	{
		character->addHealth(10);
		character->printHealthBar(); 
		foodEaten = true;
	}
	else
	{
		std::cout << "\n\tYou already ate your food...\n" << std::endl;
	}
}
/*************************************************************************
* Description: Destructor for Kitchen class, will delete all objects in
*		droppedItems container. 
**************************************************************************/
Kitchen::~Kitchen()
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