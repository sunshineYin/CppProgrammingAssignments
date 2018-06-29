// File: wolf.h
// Author: yinganmin6837@163(gmail).com(Ganmin Yin)
// Date: 2018/06/29
// Description:
//    The declaration of the class "Wolf".


#ifndef WARCRAFT_WOLF_H
#define WARCRAFT_WOLF_H

#include "warrior.h"
#include "city.h"

#include<iostream>  
#include<iomanip>  
#include<string>  
#include <cstring>  

using namespace std;

class Wolf;

class Wolf :public Warrior 
{  
	public:  
    	Wolf(string name_, int force_, int elem_, int color_, int code_, int site_, string colorNm);
    	~Wolf();
		
		// overwrite the member function "attack".
    	void attack(Warrior & enemy, City & city, int time);
	
	private:
		int num_kills_by_attack; // to count the number of warriors killed by wolf's attack.
};  

#endif // WARCRAFT_WOLF_H

