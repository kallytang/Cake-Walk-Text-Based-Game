/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the FarmField class implementation file.
**					Child class inhereits from Space
*************************************************************************/
#include"RivalHouse.hpp"
RivalHouse::RivalHouse() :Space()
{
	name = "Rival's House";
	label = "e";
	character = nullptr;
	foughtRival = false;
	aquiredBakingS = false; 
	rival = new RivalCat;
	rivalLost = false;
	
}
/*************************************************************************
Description: function implements battle between characters. 
*************************************************************************/
void RivalHouse::battle()
{
	bool battleRuns = true;
	character->printFightSpeech();
	rival->printFightSpeech();

	while (battleRuns==true)
	{
		rival->defense(character->attack());
			
		if (character->getHealth() <= 0)
		{
			battleRuns=false; 
			rivalLost = false;
		}
		else
		{
			character->defense(rival->attack());
		}

		if (rival->getHealth()<= 0)
		{
			battleRuns = false; 
			rivalLost = true; 
		}
	}
	foughtRival = true; 
}
/*************************************************************************
* Description: Function implements battle, allows user to choose to 
*		fight rival.
*************************************************************************/
void RivalHouse::fightRival()
{
	int choice;
	std::cout << "Do you want to fight rival now?" << std::endl;
	std::cout << "1. Yes" << std::endl;
	std::cout << "2. No, not now" << std::endl;
	choice = validateInput(1, 2);
	switch (choice)
	{
	case 1:
	{
		battle();
	}
	break;
	case 2:
	{
		//do nothing
	}
	break;
	}
}

void RivalHouse::raidKitchen()
{
	if (foughtRival == true)
	{
		if (aquiredBakingS == false)
		{
			std::cout << "You have found baking soda." << std::endl;
			if (character->bagFull() == true)
			{
				std::cout << "Your bag is full. drop an item to add baking soda" << std::endl;
			}
			else
			{
				character->addToBag(new BakingSoda);
				aquiredBakingS = true; 
			}
		}
		else
		{
			std::cout << "Nothin in the kitchen to take" << std::endl;
		}
		
	}
	else
	{
		std::cout << "Your rival is guarding the kitchen, you need to fight him!" << std::endl;
	}
}
/*************************************************************************
* Function Name: printDescription
* Description: Function will print description of room.
**************************************************************************/
void RivalHouse::printDescription()
{
	std::cout << "Your rival's house, he's not actually a bad guy. But you need go borrow some baking soda." << std::endl;
}
/*************************************************************************
* Function Name:  Function Name: actionMenu
* Description: Function displays all possible interactions with room.
*		Function does not take any parameters nor does it return any values.
**************************************************************************/
void RivalHouse::actionMenu()
{
	int choice;
	bool runLoop = true;
	while (runLoop == true)
	{
		std::cout << "\nPlease Choose an option:" << std::endl;
		std::cout << "1. Print the Living room space" << std::endl;
		std::cout << "2. Check the floors" << std::endl;
		std::cout << "3. Fight rival" << std::endl;
		std::cout << "4. Raid Kitchen" << std::endl;
		std::cout << "5. Check Bag" << std::endl;
		std::cout << "6. Go back to main menu" << std::endl;
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
			fightRival();
			if (rivalLost == true)
			{
				std::cout << "\nYou won!" << std::endl;
				rival->printLoserFace();
				character->printHealthBar();
			}
			else
			{
				std::cout << "\nYou won!" << std::endl;
				character->printLoserFace(); 
				runLoop = false; 
			}
		}
		break;
		case 4:
		{
			raidKitchen(); 
		}
		break;
		case 5:
		{
			checkBag();
		}
		break;
		case 6:
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
int RivalHouse::moveMenu()
{
	int choice, room;
	std::cout << "\nThe area on the right is the " << left->getSpaceName() << std::endl;
	std::cout << "Please choose an option:" << std::endl;
	std::cout << "1. Go to neighborhood" << std::endl;
	std::cout << "2. Go back to main menu" << std::endl;

	choice = validateInput(1, 2);
	switch (choice)
	{
	case 1:
	{
		room = 4;
	}
	break;
	case 2:
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
bool RivalHouse::canLeave()
{
	bool leave;
	if (foughtRival == true && aquiredBakingS==true)
	{
		leave = true;
	}
	else if (foughtRival == true && aquiredBakingS == false)
	{
		std::cout<<"\nYou can't leave until you get the baking soda from the kitchen..." << std::endl;
		leave = false;
	}
	else if (foughtRival == false && aquiredBakingS == false)
	{
		std::cout << "\nDon't forget you still need to fight your rival for baking soda" << std::endl;
		leave = true;
	}
	return leave;
}
/*************************************************************************
* Function Name: printWhole Room
* Description: Function will print map of indivisual space object.
*		Function does not take nor return any values.
**************************************************************************/
void RivalHouse::printWholeRoom()
{
	std::cout << "\t_______________________________________________________" << std::endl;
	std::cout << "\t|                       |                            |" << std::endl;
	std::cout << "\t|                       |                            |" << std::endl;
	std::cout << "\t|                       |           kitchen          |" << std::endl;
	std::cout << "\t|                       |                            |" << std::endl;
	std::cout << "\t|                       |                            |" << std::endl;
	std::cout << "\t|                       |____________________________|" << std::endl;
	std::cout << "\t|                                                    |" << std::endl;
	std::cout << "\t|                                                    |" << std::endl;
	std::cout << "\t|                                                    |" << std::endl;
	std::cout << "\t                                              _______|" << std::endl;
	std::cout << "\t                            ^---^             |      |" << std::endl;
	std::cout << "\t                          =( oxo )=           |      |" << std::endl;
	std::cout << "\t                            rival             |      |" << std::endl;
	std::cout << "\t|                                             |      |" << std::endl;
	std::cout << "\t|________________                             |      |" << std::endl;
	std::cout << "\t|               |                 ____________|      |" << std::endl;
	std::cout << "\t|    table      |                 |     couch        |" << std::endl;
	std::cout << "\t|_______________|_________________|__________________|" << std::endl;
}
/*************************************************************************
* Description: Destructor for class, will delete all objects in
*		droppedItems container.
**************************************************************************/
RivalHouse::~RivalHouse()
{
	delete rival;

	unsigned int i;
	if (!droppedItems.empty())
	{
		for (i = 0; i < droppedItems.size(); i++)
		{
			delete droppedItems[i];
		}
	}
}