/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Space class specification file.
*					Function is an abstract parent class.
*************************************************************************/
#include"Space.hpp"

#ifndef FARMFIELD_HPP
#define FARMFIELD_HPP

class FarmField :public Space
{
private:
	bool gotKey;
	bool millOpen;
	bool gotEggs;
	bool gotCorn;
	bool gotFlour; 
	bool fedChickens;


public:
	FarmField();
	void checkHaystack();
	void visitChickens();
	void feedChicken(); 
	void openMill(); 
	void printDescription()override;
	void actionMenu()override;
	int moveMenu()override;
	bool canLeave()override;
	void printWholeRoom()override;
	~FarmField()override; 
};
#endif // !FARMFIELD_HPP

