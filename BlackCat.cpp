/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the BlackCat class implemenation file.
**					Child class inherits from Parent Class Character
*************************************************************************/
#include "BlackCat.hpp"
/*************************************************************************
* Function Name:
* Description:
**************************************************************************/
BlackCat::BlackCat():Character()
{
	name = "Mr. FancyPants";
	health = 25; 
	attackC = 10; 

	maxHealth = 25; 
	winner = false;
	type = 1;
}
/*************************************************************************
* Description: Function will print image of cat.
**************************************************************************/
void BlackCat::printCat()
{
	std::cout << "   *       *" << std::endl;
	std::cout << "  *  *****  *" << std::endl; 
	std::cout << " *     *     *" << std::endl;
	std::cout << " =  o  X  o  =" << std::endl; 
	std::cout << "  **********" << std::endl;
	std::cout << "   *********" << std::endl;

}
/*************************************************************************
* Description: Function will print introduction to character. Function
*		does not take nor return any values
**************************************************************************/
void BlackCat::printIntro()
{
	printCat(); 
	std::cout << "\t" << getName() << ": " << std::endl; 
	std::cout << "\t-----------------------------------------------" << std::endl;
	std::cout << "\t| Hi there, today we're going to make a cake,  |" << std::endl; 
	std::cout << "\t| well not really making...I need to get the   |" << std::endl;
	std::cout << "\t| ingredients to make the cake.                |" << std::endl;
	std::cout << "\t|                                              |" << std::endl;
	std::cout << "\t| To find missing ingredients, we'll have      |" << std::endl;
	std::cout << "\t| to find the ingredients in the surrounding.  |" << std::endl;
	std::cout << "\t| areas.                                       |" << std::endl;
	std::cout << "\t|                                              |" << std::endl;
	std::cout << "\t| To replenish health collect coins and use    |" << std::endl;
	std::cout << "\t| them at the vending machine at the porch.    |" << std::endl;
	std::cout << "\t| There's also cat food in the kitchen that'll |" << std::endl;
	std::cout << "\t| replenish health too.                        |" << std::endl;
	std::cout << "\t|                                              |" << std::endl;
	std::cout << "\t| Let's check our kitchen for some ingredients!|" << std::endl;
	std::cout << "\t-----------------------------------------------" << std::endl;

}
/*************************************************************************
* Function Name:
* Description:
**************************************************************************/
void BlackCat::printFightSpeech()
{
	std::cout << "   *       *" << std::endl;
	std::cout << "  *  *****  *" << std::endl;
	std::cout << " *     *     *" << std::endl;
	std::cout << " =  o  X  o  =" << std::endl;
	std::cout << "  **********" << std::endl;
	std::cout << "   *********" << std::endl;

	std::cout << "\n\t" << getName() << ": " << std::endl;
	std::cout << "\t------------------------" << std::endl;
	std::cout << "\t| HELLO, Catvin.        |" << std::endl;
	std::cout << "\t| IM HERE TO ROB YOU!!  |" << std::endl;
	std::cout << "\t-------------------------" << std::endl;
}
/*************************************************************************
* Function Name:
* Description:
**************************************************************************/
void BlackCat::printSadCatFace()
{
	std::cout << "   *       *" << std::endl;
	std::cout << "  *  *****  *" << std::endl;
	std::cout << " *      *    *" << std::endl;
	std::cout << " =   TT  X  TT =" << std::endl;
	std::cout << "   **********" << std::endl;
	std::cout << "   *********" << std::endl;
	std::cout << name <<"No cake..." << std::endl;
}
void BlackCat::printLoserFace()
{
	std::cout << "   *       *" << std::endl;
	std::cout << "  *  *****  *" << std::endl;
	std::cout << " *#    * ##  *" << std::endl;
	std::cout << " =  >  X  <  =" << std::endl;
	std::cout << "  **## *****" << std::endl;
	std::cout << "   *********" << std::endl;
	std::cout << name<<" NOOO..I lost...\n" << std::endl;
}
/*************************************************************************
* Description: Function will return a value of true if cat won else will
*		return a false value
**************************************************************************/
bool BlackCat::fightWon()
{
	bool found; 
	if (winner == false)
	{
		found = false;
	}
	else if(winner ==true)
	{
		found = true;
	}
	return found;
}
BlackCat::~BlackCat()
{
	unsigned int i;
	if (!bag.empty())
	{
		for (i = 0; i < bag.size(); i++)
		{
			delete bag[i];
		}
	}
	bag.clear();
}







