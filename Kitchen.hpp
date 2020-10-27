/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Kitchen class specification file.
**					Child class inhereits from Space
*************************************************************************/
#include"Space.hpp"

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

class Kitchen : public Space
{
private:
	bool checkedFridge;
	bool checkedCupBd; 
	bool foodEaten; 

public: 
	Kitchen(); 
	void printDescription() override; 
	void actionMenu()override;
	int moveMenu() override;
	bool canLeave() override;
	void printWholeRoom()override;
	void checkFrige(); 
	void checkCupBoard();
	void eatFood(); 
	~Kitchen()override; 



};


#endif 
