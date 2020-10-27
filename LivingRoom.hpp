/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the LivingRoom class specification file.
**					Child class inhereits from Space
*************************************************************************/
#include"Space.hpp"

#ifndef LivingROOM_HPP
#define LIVINGROOM_HPP

class LivingRoom:public Space
{
private:
	bool coinTaken;
	InventoryItem* coin1;
public: 
	LivingRoom();
	void printDescription() override;
	void actionMenu() override;
	int moveMenu() override;
	bool canLeave() override;
	void printWholeRoom() override;
	void checkCouch(); 
	~LivingRoom()override;
};

#endif // !
