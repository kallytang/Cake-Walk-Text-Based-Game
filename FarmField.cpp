/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the FarmField class implementation file.
**					Child class inhereits from Space
*************************************************************************/
#include "FarmField.hpp"
FarmField::FarmField():Space()
{
	name = "Farm";
	label = "f";
	gotKey = false;
	millOpen= false;
	gotEggs=false;
	gotCorn=false;
	gotFlour=false;
	fedChickens = false;
	droppedItems.push_back(new Corn);
}
void FarmField::checkHaystack()
{
	int choice;
	if (gotKey == false)
	{
		std::cout << "Do you want to pick up key?" << std::endl;
		std::cout << "1. Yes" << std::endl;
		std::cout << "2. No" << std::endl;

		choice = validateInput(1, 2);
		switch (choice)
		{
		case 1:
		{
			if (character->bagFull() == true)
			{
				std::cout << "You don't have room for the key, you have to drop an item" << std::endl;
			}
			else
			{
				character->addToBag(new Key);
				std::cout << "You have now obtained the key to the flour mill" << std::endl;
				gotKey = true; 
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
	else
	{
		std::cout << "There's nothing here but lots of hay." << std::endl;
	}


}
void FarmField::visitChickens()
{
	int choice;
	std::cout << "The chickens are hungry. If you feed them maybe they'll give you eggs" << std::endl;
	std::cout << "Do you want to feed chickens?" << std::endl;
	std::cout << "1. Yes" << std::endl;
	std::cout << "2. No" << std::endl;
	
	choice = validateInput(1, 2);
	switch (choice)
	{
	case 1:
	{
		if (fedChickens == true)
		{
			std::cout << "You already fed the chickens" << std::endl;
		}
		else
		{
			feedChicken();
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

void FarmField::feedChicken()
{
	InventoryItem *corn1;
	int choice;
	bool itemWrong = true;
	int type;

	if (character->findItem(2) == true)
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

				if (type == 2)
				{
					corn1 = character->takeFromBag(choice);
					delete corn1;

					std::cout << "Chickens were fed! They gave you eggs" << std::endl;
					character->addToBag(new Eggs);
					fedChickens = true;
					gotEggs = true;

					itemWrong = false;

				}
				else
				{
					std::cout << "That's not corn." << std::endl;
				}
			}
		}
	}
	else
	{
		if (fedChickens==false)
		{
			std::cout << "You don't have corn for them, go find some!" << std::endl;
		}
		else
		{
			std::cout << "You already fed the chickens" << std::endl;
		}

	}
}
void FarmField::openMill()
{
	InventoryItem* key1;
	int choice;
	bool itemWrong = true;
	int type;
	if (millOpen == false)
	{
		if (gotKey == true)
		{
			millOpen = true;
			std::cout << "Key was used to open flour mill" << std::endl;
			std::cout << "Do you want do get some flour?" << std::endl;
			std::cout << "1. Yes\n";
			std::cout << "2. No I want to go back\n";

			choice = validateInput(1, 2);
			switch (choice)
			{
			case 1:
			{
				if (character->findItem(1) == true)
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

							if (type == 1)
							{
								key1 = character->takeFromBag(choice);
								delete key1;

								std::cout << "You took flour from the mill" << std::endl;
								character->addToBag(new Flour);
								gotFlour = true;

								itemWrong = false;

							}
							else
							{
								std::cout << "That's not a key." << std::endl;
							}
						}
					}
				}
			}
			break;
			case 2:
			{
				std::cout << "You don't have a key, find it in the hay stack" << std::endl;
			}
			break;
			}

		}
		else
		{
			std::cout << "You don't have the key for the flour mill.." << std::endl;
			std::cout << "\t(try checking the hay stack" << std::endl;
		}
	}
	else
	{
		std::cout << "You already got flour." << std::endl;
	}
}
/*************************************************************************
* Function Name: printDescription
* Description: Function will print description of room.
**************************************************************************/
void FarmField::printDescription()
{
	std::cout << "The farm, has eggs and flour." << std::endl;
}
void FarmField::actionMenu()
{
	int choice;
	bool runLoop = true;
	while (runLoop == true)
	{
		std::cout << "\nPlease Choose an option:" << std::endl;
		std::cout << "1. Print the Farm area" << std::endl;
		std::cout << "2. Check the floors" << std::endl;
		std::cout << "3. Check haystack" << std::endl;
		std::cout << "4. Go to chicken coop" << std::endl;
		std::cout << "5. Go insde the flour mill" << std::endl;
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
			checkHaystack();
		}
		break;
		case 4:
		{
			visitChickens();
		}
		break;
		case 5:
		{
			openMill();
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
int FarmField::moveMenu()
{
	int choice, room;
	std::cout << "\nThe area on the top is the " << top->getSpaceName() << std::endl;
	std::cout << "Please choose an option:" << std::endl;
	std::cout << "1. Go to porch" << std::endl;
	std::cout << "2. Go back to main menu" << std::endl;

	choice = validateInput(1, 2);
	switch (choice)
	{
	case 1:
	{
		room = 1;
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
bool FarmField::canLeave()
{
	bool leave;
	if (gotFlour == true && gotEggs == true)
	{
		leave = true;
	}
	else if (gotFlour == false && gotEggs == true)
	{
		std::cout << "You still need to get flour, can't leave just yet." << std::endl;
		leave = false;
	}
	else if (gotFlour == true && gotEggs == false)
	{
		std::cout << "You still need to get eggs, can't leave just yet. " << std::endl;
		leave = false;
	}
	else if (gotFlour == false && gotEggs == false)
	{
		std::cout << "You still need to get eggs and flour" << std::endl;
		leave = false;
	}
	return leave;
}
/*************************************************************************
* Function Name: printWhole Room
* Description: Function will print map of indivisual space object.
*		Function does not take nor return any values.
**************************************************************************/
void FarmField::printWholeRoom()
{
	std::cout << "\t__________________________            ________________" << std::endl;
	std::cout << "\t|                 |                           #######|" << std::endl;
	std::cout << "\t|                 |                         haystack#|" << std::endl;
	std::cout << "\t|   Flour Mill    |                        ##########|" << std::endl;
	std::cout << "\t|                 |                           ###### |" << std::endl;
	std::cout << "\t|                 |                                  |" << std::endl;
	std::cout << "\t|                 |                                  |" << std::endl;
	std::cout << "\t|_________________|                                  |" << std::endl;
	std::cout << "\t|                                                    |" << std::endl;
	std::cout << "\t|                                                    |" << std::endl;
	std::cout << "\t|                                                    |" << std::endl;
	std::cout << "\t|                                                    |" << std::endl;
	std::cout << "\t|                                                    |" << std::endl;
	std::cout << "\t|_____________________________                       |" << std::endl;
	std::cout << "\t|                            |                       |" << std::endl;
	std::cout << "\t|                            |                       |" << std::endl;
	std::cout << "\t|       Chicken Coop         |                       |" << std::endl;
	std::cout << "\t|                            |                       |" << std::endl;
	std::cout << "\t|____________________________|_______________________|" << std::endl;

} 
/*************************************************************************
* Description: Destructor for class, will delete all objects in
*		droppedItems container.
**************************************************************************/
FarmField::~FarmField()
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