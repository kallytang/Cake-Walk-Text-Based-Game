/*************************************************************************
** Project Name:	Text Based Game
** Author:			Kally Tang
** Date:			6/11/19
** Description:		Parent class for Character class, abstract class that
**					allows child characters to inherit. Specification
**					file of class. 
*************************************************************************/
#include<string>
#include<iostream>
#include<sstream>
#include"InventoryItem.hpp"
#include<vector>
#include <time.h>
#include <stdlib.h>  
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character 
{
protected:
	std::string name; 
	int health; 
	int maxHealth;
	int attackC; 
	const unsigned int MAX_SIZEBAG = 5; 
	std::vector<InventoryItem*> bag;
	int type;
	bool winner;

public: 
	Character(); 
	int getType();
	void setName(std::string);
	std::string getName(); 
	virtual void setMatchStatus(bool);
	virtual void printCat()=0; 
	void addHealth(int); 
	int getHealth();
	void decrementHealth(int); 
	void printHealthBar(); 
	virtual void printFightSpeech()=0; 
	virtual void printIntro()=0; 
	int attack(); 
	void defense(int); 
	bool findItem(int); 
	int bagMenu(); 
	void addToBag(InventoryItem*); 
	InventoryItem* takeFromBag(int); 
	void displayBag();
	virtual void printSadCatFace() = 0; 
	bool bagFull(); 
	int validateInput(int, int);
	std::string getItemName(int);
	int getItemType(int ); 
	virtual void printLoserFace() = 0;
	virtual bool fightWon() = 0;
	virtual ~Character();

};

#endif 
