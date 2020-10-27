/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Game class implementation file.
**					Game class implements game for program.
*************************************************************************/
#include"Game.hpp"
/*************************************************************************
* Function Name: Game
* Description: Default constructor, will create objects for game and 
*		initialize variables. 
**************************************************************************/
Game::Game()
{
	currentSpace= nullptr;
	kitchen1 = new Kitchen;
	livingRoom1 = new LivingRoom;
	porch1 = new Porch;
	rivalHouse1= new RivalHouse;
	farm1 = new FarmField;
	neighborhood1 = new Neighborhood;
	character1 = nullptr;


	runProg = true; 
	gameWon = false; 
	gameLost = false; 
	gameQuit = false; 
	stopGame = false;

}
/*************************************************************************
* Function Name: constructMap
* Description: Function will construct map of game. Function does not 
*		take nor return any values. 
**************************************************************************/
void Game::constructMap()
{
	
	//connect to bedroom 
	currentSpace = kitchen1;
	kitchen1->setCharacter(character1);

	kitchen1->setBottomSpace(livingRoom1);

	livingRoom1->setTopSpace(kitchen1);

	livingRoom1->setBottomSpace(porch1);

	porch1->setTopSpace(livingRoom1);

	porch1->setRightSpace(neighborhood1);
	porch1->setBottomSpace(farm1);

	farm1->setTopSpace(porch1);
	rivalHouse1->setLeftSpace(neighborhood1);

	neighborhood1->setLeftSpace(porch1);
	neighborhood1->setRightSpace(rivalHouse1);

	
}
/*************************************************************************
* Function Name: startGame
* Description: Function starts game and allows user to play again. If user 
*		chooses to end game, game ends. Allows uer to play again after game
*		ends. Function does not take nor return any values. 
**************************************************************************/
void Game::startGame()
{
	int choice; 
	Character* charaHolder;
	
	std::cout << "Start Game?\n";
	std::cout << "1. Yes\n";
	std::cout << "2. No, Quit\n";
	choice = validateInput(1, 2);
	
	switch (choice)
	{
	case 1: 
	{
		runProg = true; 
	}
	break;
	case 2: 
	{
		runProg = false;
	}
	break; 
	}

	while (runProg == true)
	{
		constructMap();
		chooseCharacter();
		charaHolder = currentSpace->getCharacter();
		charaHolder->printIntro();
		charaHolder->printHealthBar();
		runGame();

		std::cout << "Do you want to play again?\n";
		std::cout << "1. Yes\n";
		std::cout << "2. No\n";
		choice = validateInput(1, 2);
		if (choice == 2)
		{
			runProg = false;
		}
		else
		{
			//delete all objects 
			delete character1;
			delete kitchen1;
			delete livingRoom1;
			delete porch1;
			delete rivalHouse1;
			delete farm1;
			delete neighborhood1;
			
			//create objects
			currentSpace = nullptr;
			kitchen1 = new Kitchen;
			livingRoom1 = new LivingRoom;
			porch1 = new Porch;
			rivalHouse1 = new RivalHouse;
			farm1 = new FarmField;
			neighborhood1 = new Neighborhood;
			character1 = nullptr;

			//reset class variables 
			runProg = true;
			gameWon = false;
			gameLost = false;
			gameQuit = false;
			stopGame = false;
		}
	}
}
/*************************************************************************
* Function Name: runGame
* Description: Function runs games and checks if items are collected and 
*			if health ran out. If all items are collected or health runs 
*			out. game ends.Function does not take nor return any values. 
**************************************************************************/
void Game::runGame()
{
	while (stopGame == false)
	{
		menu();
		
	} 
}
/*************************************************************************
* Function Name: chooseCharacter
* Description: Function allows user to choose between two characters. 
*		Function creates character object of user's choice. Function does 
*		not take nor return any values. 
**************************************************************************/
void Game::chooseCharacter()
{
	int choice;
	//print cats

	std::cout << "   *       *        *       *" << std::endl;
	std::cout << "  *  *****  *      *  ******  *" << std::endl;
	std::cout << " *     *     *    *************" << std::endl;
	std::cout << " =  o  X  o  =   ****O**X**O****" << std::endl;
	std::cout << "  * ****** *      *************" << std::endl;
	std::cout << "   ********         *********" << std::endl;

	std::cout << "Please Choose a character:" << std::endl;
	std::cout << "1. Black and White Tuxedo Cat" << std::endl;
	std::cout << "2. White Fluffy Cat" << std::endl;

	choice = validateInput(1, 2);
	std::string name;

	switch (choice)
	{
	case 1:
	{
		character1 = new BlackCat;
		std::cout << "Please give your cat a name:";
		std::getline(std::cin, name);
		character1->setName(name);
		kitchen1->setCharacter(character1);

	}
	break;
	case 2:
	{
		//kitchen->character = new WhiteCat; 
		std::cout << "Please give your cat a name: ";
		std::getline(std::cin, name);
		std::cout << "\nFluffy III: Excuse me Narrator, I actually have a name, you didn't ask." << std::endl;
		std::cout << "My name is Fluffy the Third"<< std::endl;
		character1 = new WhiteCat;
		kitchen1->setCharacter(character1);
	}
	break;
	}
}
/*************************************************************************
* Function Name: menu 
* Description: Function displays main menu options to user, allows user
*		to check space object's area, move to another area, print a map
*		and print health bar to user. Function does not take nor return
*		any values. 
**************************************************************************/
void Game::menu()
{
	int choice, choice1; 
	Character* temp; 
	std::cout << "\nYou're currently at the " << currentSpace->getSpaceName() << std::endl;;
	std::cout << "Main Menu: Please choose an option:" << std::endl; 
	std::cout << "1. Check out the area" << std::endl; 
	std::cout << "2. Move to another area" << std::endl; 
	std::cout << "3. Print Mini Map" << std::endl;
	std::cout << "4. Print Health Bar" << std::endl;
	std::cout << "5. Print current location's description" << std::endl;
	std::cout << "6. End current game" << std::endl;

	choice = validateInput(1, 6);
	switch (choice)
	{
	case 1: 
	{ 
		currentSpace->actionMenu(); 
		checkItemsCollected();
		checkHealthRunOut();
	}
	break; 
	case 2: 
	{
		if (currentSpace->canLeave() == true)
		{
			choice1 = currentSpace->moveMenu();
			switch (choice1)
			{
			case 1: //move up 
			{
				temp = currentSpace->getCharacter();
				currentSpace->setCharacter(nullptr);
				currentSpace = currentSpace->getTopSpace();
				currentSpace->setCharacter(temp);
				temp->decrementHealth(1);
				temp->printHealthBar();
			}
			break;
			case 2: //move right
			{
				temp = currentSpace->getCharacter();
				currentSpace->setCharacter(nullptr);
				currentSpace = currentSpace->getRightSpace();
				currentSpace->setCharacter(temp);
				temp->decrementHealth(1);
				temp->printHealthBar();
			}
			break;
			case 3://move down
			{
				temp = currentSpace->getCharacter();
				currentSpace->setCharacter(nullptr);
				currentSpace = currentSpace->getBottomSpace();
				currentSpace->setCharacter(temp);
				temp->decrementHealth(1);
				temp->printHealthBar();
			}
			break;
			case 4: //move left
			{
				temp = currentSpace->getCharacter();
				currentSpace->setCharacter(nullptr);
				currentSpace = currentSpace->getLeftSpace();
				currentSpace->setCharacter(temp);
				temp->decrementHealth(1);
				temp->printHealthBar();
			}
			break;
			case 5: //continue 
			{
				//do nothing 
			}
			break;
			}
		}
	}
	break;
	case 3: 
	{
		printMiniMap();
	}
	break;
	case 4:
	{
		temp = currentSpace->getCharacter();
		temp->printHealthBar();
	}
	break; 
	case 5:
	{
		currentSpace->printDescription();
	}
	break;
	case 6:
	{
		runProg = false;
		gameQuit = false;
		stopGame = true;
	}
	break;
	}
	
	
}
/*************************************************************************
* Function Name: printMiniMap
* Description: Function will print out map represenation of the space 
*		class objects. Function does not take any parameters nor does it
*		return any parameters.
**************************************************************************/
void Game::printMiniMap()
{
	std::cout << "      _______         " << std::endl;
	std::cout << "      |  a. |        " << std::endl;
	std::cout << "      _______    " << std::endl;
	std::cout << "      |  b. |  " << std::endl;
	std::cout << "      __________________" << std::endl;
	std::cout << "      |  c. |  d. |  e. |" << std::endl;
	std::cout << "      ___________________" << std::endl;
	std::cout << "      |  f. |" << std::endl;
	std::cout << "      _______" << std::endl;


	std::cout << "\n\tKey: " << std::endl;
	std::cout << "a. Kitchen" << std::endl;
	std::cout << "b. Living Room" << std::endl;
	std::cout << "c. Your Front Porch" << std::endl;
	std::cout << "d. Street" << std::endl;
	std::cout << "e. Rival's House" << std::endl;
	std::cout << "f. Farm" << std::endl;

	std::cout << "\n\nYour current location is " << currentSpace->getLabel() << ". " << currentSpace->getSpaceName() << "." << std::endl;
}
/*************************************************************************
* Function Name: badEnd
* Description: Function will print bad ending image. Function does not 
*		take nor return any values.
**************************************************************************/
void Game::badEnd()
{
	Character *temp;
	std::cout << "\tBad End:" << std::endl; 
	std::cout << "\tNo cake. " << std::endl;
	temp = currentSpace->getCharacter();
	temp->printSadCatFace();
}
/*************************************************************************
* Function Name: goodEnd
* Description: Function will print out good ending. Function does not 
*		take nor return any values;
**************************************************************************/
void Game::goodEnd()
{
	if (character1->getType() == 1)
	{
		std::cout << "\tSucess! We made a cake." << std::endl;
		std::cout << " @@@@@@@@@@@@@@@@@@" << std::endl;
		std::cout << "|                  |" << std::endl;
		std::cout << "|                  |" << std::endl;
		std::cout << " @@@@@@@@@@@@@@@@@@" << std::endl;
		std::cout << "|                  |" << std::endl;
		std::cout << "|                  |" << std::endl;
		std::cout << " @@@@@@@@@@@@@@@@@@" << std::endl;
	}
	else if(character1->getType()==2)
	{
		std::cout << "\tSucess! We made a cake." << std::endl;
		std::cout << " @@@@@@@@@@@@@@@@@@" << std::endl;
		std::cout << " |      @@         |" << std::endl;
		std::cout << "  |       @          |" << std::endl;
		std::cout << "   @@@@@@@@@@@@@@@@@@" << std::endl;
		std::cout << "   |         @@@      |" << std::endl;
		std::cout << "  |          @@       |" << std::endl;
		std::cout << "  @@@@@@@@@@@@@@@@@@@@ @@@" << std::endl;
		std::cout << "Fluffy III is bad at making cakes" << std::endl;
		
	}
	

}
/*************************************************************************
* Function Name: validateInput
* Description: Function takes two integer variables and will validate user
*		input, will prompt user to enter a value between min and max until 
*		a valid integer is entered and value is returned.
**************************************************************************/
int Game::validateInput(int min, int max)
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
* Function Name: HealthRunOut
* Description: Function will check if health ran out, if it runs out
*		it will cause the game to end. 
**************************************************************************/
void Game::checkHealthRunOut()
{
	Character* chara;

	chara =currentSpace->getCharacter();

	if (chara->getHealth() <= 0)
	{
		badEnd();
		stopGame = true;
	}
}
/*************************************************************************
* Function Name: ItemsCollected
* Description: Function checks if character has collected all necessary 
*		items to bake the cake. Function does not return nor 
*		take any values as parameter.
**************************************************************************/
void Game::checkItemsCollected()
{
	Character* charHolder;
	bool flourFound; 
	bool eggsFound;
	bool bakingSodaFound;
	charHolder = currentSpace->getCharacter();
	flourFound = charHolder->findItem(3);
	eggsFound = charHolder->findItem(4);
	bakingSodaFound = charHolder->findItem(5);
	if (flourFound == true && eggsFound==true && bakingSodaFound==true)
	{
		std::cout << "Sucess you have gotten all the Items, now it's time to make the cake" << std::endl;
		goodEnd();
		stopGame = true;
	}

}
/************************************************************************* 
* Description: Game destructor, will free all memory of objects that were
*		created. 
**************************************************************************/
Game::~Game()
{
	
	delete character1;
	delete kitchen1; 
	delete livingRoom1; 
	delete porch1;
	delete rivalHouse1;
	delete farm1;
	delete neighborhood1;
	

}