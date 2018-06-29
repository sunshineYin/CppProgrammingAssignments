// File: warrior.h
// Author: yinganmin6837@163(gmail).com(Ganmin Yin)
// Date: 2018/06/29
// Description:
//    The declaration of the class "Warrior".
//    "Warrior" is the abstract class of the class "Dargon", "Ninjia", "Iceman", "Lion" and "Wolf".


#ifndef WARCRAFT_WARRIOR_H
#define WARCRAFT_WARRIOR_H

//#include "headquarter.h"
//#include "city.h" 

#include<iostream>  
#include<iomanip>  
#include<string>  
#include <cstring>   

using namespace std;

class Headquarter;
class City;

class Warrior;

class Warrior 
{  
	public:  
    	string name; 
    	int color;  // the camp which the warrior belongs to. ( 0 is red, 1 is blue)
    	string colorName;  
    	int force;  
    	int element;  
    	int code;  // the number of the warrior.
    	int site; // the number of the city where the warrior is.
    	int tmpElem; // especially for "Lion".   
    	
		Warrior(string name_, int force_, int elem_, int color_, int code_, int site_, string colorNm);
    	virtual ~Warrior();
    	
		virtual void attack(Warrior & enemy, City & city, int time);  
    	virtual void fightback(Warrior & enemy, City & city, int time);  
    	void rewardElem(Headquarter & headquarter); // be rewarded with elements from it's headquarter.  
    	virtual void win(City & city, int time); // win the fight.  
    	virtual void draw(City & city); // both alive, didn't win or lose.
    	virtual void lose(Warrior & enemy, City &city, int time); // lose the fight. And it will die.
    	virtual void moveforward(City *city[], int N, Headquarter *headquarter[], int time);  

}; 

#endif // WARCRAFT_WARRIOR_H 

