/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Rival class specification file.
*					Function is an abstract parent class.
*************************************************************************/
#include"Space.hpp"


#ifndef RIVALHOUSE_HPP
#define RIVALHOUSE_HPP
class RivalHouse :public Space
{
private:
	bool foughtRival;
	BakingSoda* bakingS;
	bool aquiredBakingS;
	Character* rival; 
	bool rivalLost;

public:
	RivalHouse();
	void battle(); 
	void fightRival();
	void raidKitchen();
	void printDescription()override;
	void actionMenu()override;
	int moveMenu()override;
	bool canLeave()override;
	void printWholeRoom()override;
	~RivalHouse() override;
};

#endif

