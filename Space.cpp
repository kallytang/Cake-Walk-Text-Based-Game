/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Space class implementation file.
**					Space class is an abstract parent class. 
*************************************************************************/
#include"Space.hpp"
/*************************************************************************
* Function Name: Space 
* Description: Default constructor, intializes variables.
**************************************************************************/
Space::Space()
{
	name = " ";
	label = " ";
	top = nullptr;
	right = nullptr;
	left= nullptr;
	bottom=nullptr;
	character = nullptr;

}
/*************************************************************************
* Description: set and get functions for Space class. 
**************************************************************************/
void Space::setTopSpace(Space* ptr)
{
	top = ptr;
}
void Space::setBottomSpace(Space* ptr)
{
	bottom = ptr;
}
void Space::setRightSpace(Space* ptr)
{
	right = ptr;
}
void Space::setLeftSpace(Space* ptr)
{
	left = ptr;
}
Space* Space::getTopSpace()
{
	return top;
}
Space* Space::getBottomSpace()
{
	return bottom;
}
Space* Space::getLeftSpace()
{
	return left;
}
Space* Space::getRightSpace()
{
	return right;
}
void Space::setCharacter(Character* ch)
{
	character = ch;
}
Character* Space::getCharacter()
{
	return character;
}
std::string Space::getSpaceName()
{
	return name; 
}
std::string Space::getLabel()
{
	return label; 
}
/*************************************************************************
* Function Name:
* Description: Function will take an intventory item object pointer and
*		adds object to dropped items of room(dropped items in droppedItems
*		cointainter vector. 
**************************************************************************/
void Space::storeDroppedItems(InventoryItem* item)
{
	droppedItems.push_back(item); 
}
/*************************************************************************
* Function Name: displayDroppedItems
* Description: Function will display dropped items to user(items in 
*		droppedItems vector.
**************************************************************************/
void Space::displayDroppedItems()
{
	int choice;
	int count = 1; 
	unsigned int i; 
	int num; 

	if (droppedItems.empty())
	{
		std::cout << "\nThere's nothing on the floor.\n" << std::endl;
	}
	else
	{
		std::cout << "\nYou found the following items on the floor:" << std::endl; 
		for (i = 0; i < droppedItems.size(); i++)
		{
			
			std::cout << "\t" << count << ". " << droppedItems[i]->getName() << std::endl;
			count++;
		}
		std::cout << "\n";
		std::cout << "Do you want to pick an item up?" << std::endl;
		std::cout << "1. Yes" << std::endl;
		std::cout << "2. No" << std::endl;
		choice = validateInput(1, 2);

		if (choice == 1)
		{
			count = 1;
			std::cout << "\tPlease choose an option:" << std::endl;
			for (i = 0; i < droppedItems.size(); i++)
			{

				std::cout << "\t" << count << ". " << droppedItems[i]->getName() << std::endl;
				count++;
			}
			std::cout << "\t" << count << ". I don't want to pick up any of them." << std::endl;

			choice = validateInput(1, count);

			if (choice == count)
			{
				//do nothing 
			}
			else
			{
				if (character->bagFull() == true)
				{
					std::cout << "Your bag is full. You must drop or use an item to clear up space in your bag." << std::endl;
				}
				else
				{
					num = choice - 1; 
					character->addToBag(pickUpDroppedItem(num));
				}
			}
		}
	}
}
/*************************************************************************
* Function Name: checkBag
* Description: Function will display menu to user to interact with items
*		in bag. Allows user to display contents of bag as well as drop an 
*		item from bag Function does not return nor take any values as 
*		parametes. Child classes will inherit function.
**************************************************************************/
void Space::checkBag() 
{
	int choice, num, item;
	std::cout << "\nPlease choose an option" << std::endl;
	std::cout << "1. Display contents of bag" << std::endl;
	std::cout << "2. Drop an Item" << std::endl;
	std::cout << "3. Go back to menu" << std::endl;

	choice = validateInput(1, 3);

	switch (choice)
	{
	case 1: 
	{
		character->bagMenu();
	}
	break; 
	case 2:
	{
		std::cout << "Pick an item you want to drop" << std::endl;
		num = character->bagMenu(); 
		if (num == -1)
		{
			// do nothing 
		}
		else
		{

			item = num - 1; 
			if (character->getItemType(item)==3 || character->getItemType(item) ==4 || character->getItemType(item) ==5)
			{
				std::cout << "\nCan't drop those items...I'll forget where I put them if I dropped it\n" << std::endl;
			}
			else
			{
				std::cout << character->getItemName(item)<< " is dropped onto the floor"<<std::endl;
				storeDroppedItems(character->takeFromBag(item));
				
			}
			
		}
	}
	break; 
	case 3: 
	{
		//do nothing to go back to main menu
	}
	break;
	}
	
}
/*************************************************************************
* Function Name: pickUpDroppedItems
* Description: Function will take an integer as parameter to find the
*			nth element in the droppedItems vector, delete the nth vector
*			element of droppedItems container. Function returns the item
*			stored in the nth element. 
**************************************************************************/
InventoryItem* Space::pickUpDroppedItem(int num)
{
	InventoryItem* item1; 

	item1 = droppedItems[num]; 
	droppedItems[num] = nullptr;
	droppedItems.erase(droppedItems.begin()+num);
	return item1;
}
/*************************************************************************
* Function Name:validateInput
* Description: Function takes two integer variables and will validate user
*		input, will prompt user to enter a value between min and max until 
*		a valid integer is entered and value is returned.
**************************************************************************/
int Space::validateInput(int min, int max)
{
	char c;
	int option;
	std::string line;
	bool invalid = true;

	//validate user input
	while (invalid == true)
	{
		std::getline(std::cin, line);
		std::stringstream inputStream(line);

		if (!(inputStream >> option) ||
			((option < min) || (option > max)) ||
			(inputStream >> c))
		{
			std::cout << "Invalid input, please choose between "
				<< min << " or " << max << std::endl;
		}
		else
		{
			inputStream >> option;
			invalid = false;

		}
	}
	return option;

}
/*************************************************************************
* Function Name: Space
* Description: Destructor for parent class Space 
**************************************************************************/
Space::~Space()
{
}