/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the RivalCat class speficiation file.
**					Child class inherits from Parent Class Character
*************************************************************************/
#include"RivalCat.hpp"
/*************************************************************************
* Function Name: RivalCat
* Description: Default constructor, will initialize variables to a value
*		or string.
**************************************************************************/
RivalCat::RivalCat():Character()
{
	name = "Catvin";
	health = 8;
	attackC = 8;
	maxHealth = 8;
	type = 3;
	winner = false;
}
/*************************************************************************
* Function Name: printIntro
* Description: Function will print introduction to character. Function
*		does not take nor return any values
**************************************************************************/
void RivalCat::printIntro()
{
	std::cout << "This is your neighbor's cat, Catvin. You regularily pester him for things." << std::endl;
}
/*************************************************************************
* Description: Function will print image of cat. 
**************************************************************************/
void RivalCat::printCat()
{
	std::cout << "   *       *" << std::endl;
	std::cout << "  *  ****** *" << std::endl;
	std::cout << " *     ******" << std::endl;
	std::cout << " =  ò  X *ó **=" << std::endl;
	std::cout << "  *         *" << std::endl;
	std::cout << "   *********" << std::endl;
}
/*************************************************************************
* Description: Function will print fight message to user. 
**************************************************************************/
void RivalCat::printFightSpeech()
{
	std::cout << "   *       *" << std::endl;
	std::cout << "  *  ****** *" << std::endl;
	std::cout << " *     ***)(*" << std::endl;
	std::cout << " =  O  X *O **=" << std::endl;
	std::cout << "  *         *" << std::endl;
	std::cout << "  *********" << std::endl;
	std::cout << "\n\t" << getName() << ": " << std::endl;
	std::cout << "\t------------------------" << std::endl;
	std::cout << "\t| AGAIN??? THIS IS THE  |" << std::endl;
	std::cout << "\t| THIRD TIME THIS MONTH.|" << std::endl;
	std::cout << "\t| ALRIGHT PUT 'EM UP!   |" << std::endl;
	std::cout << "\t-------------------------" << std::endl;

}
/*************************************************************************
* Description: Function will print sad cat face
**************************************************************************/
void RivalCat::printSadCatFace()
{
	std::cout << "   *       *" << std::endl;
	std::cout << "  *  ****** *" << std::endl;
	std::cout << " *     ******" << std::endl;
	std::cout << " = TT  X *TT**=" << std::endl;
	std::cout << "  *         *" << std::endl;
	std::cout << "   *********" << std::endl;
}
void RivalCat::printLoserFace()
{
	std::cout << "   *       *" << std::endl;
	std::cout << "  *  ****** *" << std::endl;
	std::cout << " * #  ******" << std::endl;
	std::cout << " =   TT  x *TT**=" << std::endl;
	std::cout << "  *        ## *" << std::endl;
	std::cout << "   *********" << std::endl;
	std::cout << name <<": I lost..." << std::endl;

}
/*************************************************************************
* Description: Function will return a value of true if cat won else will
*		return a false value
**************************************************************************/
bool RivalCat::fightWon()
{
	bool found;
	if (winner == false)
	{
		found = false;
	}
	else if (winner == true)
	{
		found = true;
	}
	return found;
}
RivalCat::~RivalCat()
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




