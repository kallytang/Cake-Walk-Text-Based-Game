/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the RivalCat class speficiation file.
**					Child class inherits from Parent Class Character
*************************************************************************/
#include "Character.hpp"

#ifndef RIVALCAT_HPP
#define RIVALCAT_HPP

class RivalCat :public Character
{
private:

public: 
	RivalCat(); 
	void printCat() override; 
	void printIntro()override;
	void printFightSpeech() override;
	void printSadCatFace()override;
	void printLoserFace() override;
	bool fightWon()override;
	~RivalCat()override; 


};
#endif 
