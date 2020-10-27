/*************************************************************************
** Project Name:	Text Based Game: Cat Baking Adventure
** Author:			Kally Tang
** Date:			6/11/2019
** Description:		File contains the Neighborhood class specification file.
**					Child class inhereits from Space
*************************************************************************/
#include"Space.hpp"

#ifndef NEIGHBORHOOD_HPP
#define NEIGHBORHOOD_HPP
class Neighborhood:public Space 
{
private:
	bool shovelTaken;
	bool metalDetectorTaken; 
	bool coin1Found;
	bool coin2Found;

public: 
	Neighborhood();
	void printDescription()override;
	void actionMenu()override;
	int moveMenu()override;
	bool canLeave()override;
	void checkLawn1();
	void checkLawn2();
	void checkCorner1(); 
	void checkCorner2();
	void printWholeRoom()override;
	~Neighborhood();
};
#endif // !1
