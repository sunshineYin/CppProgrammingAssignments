// File: dragon.h
// Author: yinganmin6837@163(gmail).com(Ganmin Yin)
// Date: 2018/06/29
// Description:
//    The declaration of the class "Dragon".


#ifndef WARCRAFT_DRAGON_H
#define WARCRAFT_DRAGON_H

#include "warrior.h"
#include "city.h"

#include<iostream>  
#include<iomanip>  
#include<string>  
#include <cstring>  

using namespace std;

class Dragon;

class Dragon :public Warrior 
{  
    public:  
    	
		Dragon(string name_, int force_, int elem_, int color_, int code_, int site_, string colorNm);
		~Dragon();  
		
    	// overwrite the member function "attack".
		void attack(Warrior & enemy, City & city, int time);  
    	// add member function "yell".
		void yell(City & city, int time);  
};  

#endif // WARCRAFT_DRAGON_H

