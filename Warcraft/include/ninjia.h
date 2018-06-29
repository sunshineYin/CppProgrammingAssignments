// File: ninjia.h
// Author: yinganmin6837@163(gmail).com(Ganmin Yin)
// Date: 2018/06/29
// Description:
//    The declaration of the class "Ninjia".


#ifndef WARCRAFT_NINJIA_H
#define WARCRAFT_NINJIA_H

#include "warrior.h"
#include "city.h"

#include<iostream>  
#include<iomanip>  
#include<string>  
#include <cstring>  

using namespace std;

class Ninjia;

class Ninjia :public Warrior 
{  
	public:  

    	Ninjia(string name_, int force_, int elem_, int color_, int code_, int site_, string colorNm);
		~Ninjia();  
    	
    	// overwrite the member function "fightback".
		void fightback(Warrior & enemy, City & city,int time);
};  

#endif // WARCRAFT_NINJIA_H

