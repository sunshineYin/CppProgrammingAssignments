// File: headquarter.h
// Author: yinganmin6837@163(gmail).com(Ganmin Yin)
// Date: 2018/06/29
// Description:
//    The declaration of the class "Headquarter".



#ifndef WARCRAFT_HEADQUARTER_H
#define WARCRAFT_HEADQUARTER_H

#include "place.h"
#include "warrior.h"

#include<iostream>  
#include<iomanip>  
#include<string>  
#include <cstring>   

using namespace std;

const int WR_TYPE_NUM = 5; // the number of warrior's types.


class Headquarter;

class Headquarter:public Place 
{  
    public:  
    
    	Warrior *enemyWr[2]; // the enemy warriors which arrived at this headquarter.
    	Warrior *newBornWr; // the new born warrior.
    	
		Headquarter(int color_, int elem_, int round_, int site_, string colorNm);
    	~Headquarter();  
    	
		friend class Warrior; friend class City; friend class Lion;  
    	
		void printWarriorBornInfo(int time); // print out the information of born warrior. 
    	void produceWr(int time, int iniElem_Wr[][WR_TYPE_NUM], int iniForce_Wr[][WR_TYPE_NUM]); // produce warrior. 
    	void printEnemyArrivedInfo(int time, bool & stop); // print out the information of enemy warrior arrived. 
    	void printElemInfo(int time); // print out the information of this headquarter's elements. 
	
	private:
	
		int color;  
    	string colorName;  
		int index; 
    	int round; // the number of test case.
    	int site; // the number of the headquarter. ( 0 or N+1) 
		int countEnemy, record; // record is to checkout whether the number of enemy (already arrived at this headquarter) changes. (whether countEnemy equals to record)
		Warrior *army[200];
		int warriorCode;  
    	static int produceWrOrder[2][5]; // the order of producing warriors.
};   

#endif // WARCRAFT_HEADQUARTER_H

