/************************************************************************
** Project Name : Text Based Game: Cake Adventure
** Author : Kally Tang
** Date : 6 / 11 / 19
* * Description : Parent class for Character class, abstract class that
**					allows child characters to inherit
*************************************************************************/

#include"Character.hpp"
/*************************************************************************
* Function Name: Character
* Description: Default constructor, will set integer variables to 0 
*		and string variables as a blank.
**************************************************************************/
Character::Character()
{
	name = " ";
	health = 0;
	attackC = 0;
	maxHealth = 0;
	type = 0;
	winner = false;
}
/*************************************************************************
* Function Name: setName getName and getType
* Description: Set and get functions for name variable. 
**************************************************************************/
int Character::getType() 
{
	return type;
}
void Character::setName(std::string name1)
{
	name = name1; 
}
std::string Character::getName()
{
	return name; 
}
void Character::setMatchStatus(bool stat)
{
	winner = stat; 
}
/*************************************************************************
* Function Name: addHealth
* Description: Function will take an integer as a parameter and adds it
*		to health of character. Function does not return any value. 
**************************************************************************/
void Character::addHealth(int addedHealth)
{
	int oldHealth;
	int totalGained; 
	oldHealth = health; 
	health += addedHealth;

	if (health > maxHealth)
	{
		health = maxHealth;

		totalGained = health - oldHealth;
		std::cout << "\t" << name << " has gained " << totalGained << " health points." << std::endl;

	}
	else
	{
		totalGained = health - oldHealth;
		std::cout << "\t" << name << " has gained " << totalGained << " health points." << std::endl;
	}


}
/*************************************************************************
* Function Name: getHealth
* Description: Funtion returns the health of character. Function does not
**		take any values as parameter. 
**************************************************************************/
int Character::getHealth()
{
	return health;
}
/*************************************************************************
* Function Name: decrementHealth
* Description: Function will take an integer value as parameter. 
**************************************************************************/
void Character::decrementHealth(int val)
{
	health = health-val;  
}
/*************************************************************************
* Function Name: printHealthBar
* Description: Funciton will print health bar to user. 
**************************************************************************/
void Character::printHealthBar()
{
	int usedHealth; 
	usedHealth = maxHealth - health;
	
	if (health >= 20)
	{
		std::cout << "\t  ^---^ " << std::endl;
		std::cout << "\t=(o w o)= " <<name << ": I feel great!" << std::endl;
	}
	else if(health<20 && health>=7)
	{
		std::cout << "\t  ^---^ " << std::endl;
		std::cout << "\t=(e _ e)= " <<name<<": I feel okay... I might need to find food soon" << std::endl;
	}
	else if (health <7 && health>=4)
	{
		std::cout << "\t  ^---^ " << std::endl;
		std::cout << "\t=(= m =)= " <<name << ": Need... food...." << std::endl;

	}
	else if (health < 4)
	{
		std::cout << "\t  ^---^ " << std::endl;
		std::cout << "\t=(x - x)= " <<name << ":Please feed me...." << std::endl;
	}
	std::cout <<"\t"<< name << "'s Health:" << health << std::endl;
	std::cout << "\t";
	
	for (int k = 0; k < health; k++)
	{
		std::cout << "*";
	}

	//print used health 

	for (int i = 0; i < usedHealth; i++)
	{
		std::cout << "X";
	}
	std::cout << "\n";

}
/*************************************************************************
* Function Name: attack
* Description: Function will generate a value between attack and 1 and
*			return value generated. 
**************************************************************************/
int Character::attack()
{
	int val;
	val = rand() % attackC + 1;
	return val; 
}
/*************************************************************************
* Function Name: defense
* Description: Function will take an integer value and subtract it from
*		character's health.
**************************************************************************/
void Character::defense(int val)
{

	health = health - val;

}
/*************************************************************************
* Function Name: findItem
* Description: Function will take an integer value as parameter and find
*		whether the type of object is found in character's bag. Function
*		will return true if item of specified type is found. 
**************************************************************************/
bool Character::findItem(int type)
{
	unsigned int count = 0;
	bool found = false; 
	if (bag.empty())
	{
		return false;
	}
	else
	{
		//search in bag
		while (count < bag.size())
		{
			if (bag[count]->getType() == type)
			{
				found = true; 
			}
			count++;
		}
	}

	if (found == true)
	{
		return true; 
	}
	else
	{
		return false; 
		
	}
}
/*************************************************************************
* Function Name: bagMenu
* Description: Function will display menu to user to interact with bag. 
*		User is given to display item to user, to choose an item to remove. 
*		If user chooses to only view items or if user chooses not to take
*		any items out, function returns a value of -1, if user chooses
*		to remove an item from bag, file returns the nth element place +1.
*		Function does not take any values as parameter. 
**************************************************************************/
int Character::bagMenu()
{
	unsigned int i;
	int val; 
	int count = 1;
	int choice; 
	if (bag.empty())
	{
		std::cout << "\nYour bag is currently empty" << std::endl;
		val = -1; 
	}
	else
	{
		std::cout << "\n\tYour bag has the following items:" << std::endl;
		for (i=0; i < bag.size(); i++)
		{
			std::cout << "\t" << count << ". " << bag[i]->getName() << std::endl;
			count++; 
		}
		std::cout <<"\t" << count << ". I want to go back." << std::endl;;

		choice = validateInput(1, count);
		if (choice == count)
		{
			val = -1;
		}
		else
		{
			val = choice; 
		}
	}
	return val; 

}
/*************************************************************************
* Function Name: addToBag
* Description: Function allows user to add a pointer to item to bag. 
**************************************************************************/
void Character::addToBag(InventoryItem* item)
{
	if (bag.size() == MAX_SIZEBAG)
	{
		// don't add
	}
	else
	{
		bag.push_back(item);
		std::cout <<"\n"<< item->getName() << " has been added to your bag." << std::endl; 
	}
}
/*************************************************************************
* Function Name: takeFromBag
* Description: Funciton allows user to take an item from bag and return
*		pointer to item. 
**************************************************************************/
InventoryItem* Character::takeFromBag(int num)
{
	InventoryItem *item; 
	item = bag[num];
	bag[num] = nullptr;
	bag.erase(bag.begin()+num);
	return item;
}
/*************************************************************************
* Function Name: displayBag
* Description: Function will display contents to bag if not empty, 
*		otherwise function gives a message that bag is empty.
**************************************************************************/
void Character::displayBag()
{
	unsigned int num; 
	if (bag.empty())
	{
		std::cout << "\n\tYour bag is currently empty\n" << std::endl; 

	}
	else
	{
		std::cout << "\nContents of bag" << std::endl; 
		for (num = 0; num < bag.size(); num++)
		{
			std::cout <<"\t"<<(num + 1) << ". " <<bag[num]->getName()<< std::endl;
		}
	}
}

/*************************************************************************
* Function Name: bagFull
* Description: Function return a value of true if bag is at max capacity.
**************************************************************************/
bool Character::bagFull()
{
	if (bag.size() ==MAX_SIZEBAG)
	{
		return true;
	}
	else
	{
		return false; 
	}
}
/*************************************************************************
* Function Name: getItemName
* Description: Function return item name in bag of the nth element.
**************************************************************************/
std::string Character::getItemName(int num)
{
	std::string itemName;


	itemName = bag[num]->getName();

	return itemName;
}
/*************************************************************************
* Function Name: getItemName
* Description: Function return item type in bag of the nth element.
**************************************************************************/
int Character::getItemType(int num)
{
	int itemType; 

	itemType = bag[num]->getType(); 

	return itemType;
}
/*************************************************************************
* Function Name: validateInput
* Description: Function takes two integer variables and will validate user
*		input, will prompt user to enter a value between min and max until 
*		a valid integer is entered and value is returned.
**************************************************************************/
int Character::validateInput(int min, int max)
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
* Description: Destructor, function will delete all items in bag. 
**************************************************************************/
Character::~Character()
{
	unsigned int i; 
	while (!bag.empty())
	{
		for (i = 0; i < bag.size(); i++)
		{
			delete bag[i];
		}
	}
	bag.clear(); 
}
