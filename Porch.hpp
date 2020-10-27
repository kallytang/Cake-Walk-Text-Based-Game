/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Space class specification file.
*					Function is an abstract parent class. 
*************************************************************************/
#include "Space.hpp"

#ifndef PORCH_HPP
#define PORCH_HPP


class Porch:public Space
{
private:
public:
	Porch();
	void printDescription()override;
	void actionMenu()override;
	int moveMenu()override;
	bool canLeave()override;
	void useVendingMachine(); 
	void printWholeRoom()override;
	~Porch()override;
};



#endif // !
