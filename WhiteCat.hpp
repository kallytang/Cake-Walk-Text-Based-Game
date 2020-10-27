
/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the BlackCat class speficiation file.
**					Child class inherits from Parent Class Character
*************************************************************************/
#include "Character.hpp"
#include"InventoryItem.hpp"

#ifndef WHITECAT_HPP
#define WHITECAT_HPP

class WhiteCat : public Character
{
private:

public:
	WhiteCat();
	void printCat() override;
	void printIntro()override;
	void printFightSpeech() override;
	void printSadCatFace() override;
	void printLoserFace() override;
	bool fightWon();
	~WhiteCat()override;

};

#endif 