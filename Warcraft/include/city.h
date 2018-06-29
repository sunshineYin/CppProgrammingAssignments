// File: city.h
// Author: yinganmin6837@163(gmail).com(Ganmin Yin)
// Date: 2018/06/29
// Description:
//    The declaration of the class "City".


#ifndef WARCRAFT_CITY_H
#define WARCRAFT_CITY_H

#include "place.h"
#include "headquarter.h"
#include "warrior.h"
#include "dragon.h"
#include "ninjia.h"
#include "iceman.h"
#include "lion.h"
#include "wolf.h"

#include<iostream>  
#include<iomanip>  
#include<string>  
#include <cstring>   

using namespace std;

class City;

class City:public Place
{  
	public:  
      
    	int site; // The number of city.
    	int flag; // The camp which the city belongs to. ( 0 is red, 1 is blue, 2 is neutral)
    	int last_winner; // The last winner warrior's camp of this city. ( 0 is red, 1 is blue, 2 is neutral) 
    	int num_warrior; // The number of warriors in this city at this moment.
    	Warrior *winnerWr; // The winner warrior.
    	Warrior *wr[2]; // The warriors's condition of this city.
    	
    	City(int site_, int flag_);
		City(int site_, int flag_, int elem_, int num_); 
		~City();
		
    	void elementPlus(); // At the 20th minute of each hour, the city will produce 10 elements.
    	void transferElem(Headquarter & headquarter, int time,int color = 0); // The city transfer it's elements to one of the headquarters. 
    	void printWarriorArrivedInfo(int time); // To print out the informations of warriors which arrived at this city.
    	  
    	friend class Warrior; friend class Dragon; friend class Ninjia; friend class Iceman; friend class Lion; friend class Wolf;  

};  

#endif // WARCRAFT_CITY_H

