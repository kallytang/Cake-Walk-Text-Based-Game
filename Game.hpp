/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Game class specification file. 
**					Game class implements game for program. 
*************************************************************************/
#include "Character.hpp"
#include"InventoryItem.hpp"
#include "Space.hpp"
#include "BlackCat.hpp"
#include "WhiteCat.hpp"
#include"RivalCat.hpp"
#include"InventoryItem.hpp"
#include <iostream>
#include "Kitchen.hpp"
#include"LivingRoom.hpp"
#include"Porch.hpp"
#include"FarmField.hpp"
#include "Neighborhood.hpp"
#include "RivalHouse.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game
{
private:
	bool runProg;
	Space* currentSpace; 
	Space* kitchen1; 
	Space* livingRoom1;
	Space* porch1; 
	Space* rivalHouse1; 
	Space* farm1; 
	Space* neighborhood1;
	Character *character1;
	

	bool gameWon; 
	bool gameLost; 
	bool gameQuit; 
	bool stopGame; 
	bool wonCatFight;
	
public:
	Game(); 
	void constructMap(); 
	void startGame(); 
	void runGame(); 
	void chooseCharacter();  
	void menu();
	void printMiniMap(); 
	void badEnd(); 
	void goodEnd(); 
	int validateInput(int, int);
	void checkHealthRunOut(); 
	void checkItemsCollected(); 
	~Game(); 
	
};


#endif // !GAME_HPP
