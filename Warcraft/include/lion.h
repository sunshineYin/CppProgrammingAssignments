// File: lion.h
// Author: yinganmin6837@163(gmail).com(Ganmin Yin)
// Date: 2018/06/29
// Description:
//    The declaration of the class "Lion".


#ifndef WARCRAFT_LION_H
#define WARCRAFT_LION_H

#include "warrior.h"
#include "city.h"

#include<iostream>  
#include<iomanip>  
#include<string>  
#include <cstring>  

using namespace std;

class Lion;

class Lion :public Warrior 
{  
	public:  
    	Lion(string name_, int force_, int elem_, int color_, int code_, int site_, string colorNm);
		~Lion(); 
    	
		// overwrite the member function "lose".
    	void lose(Warrior & enemy, City & city, int time);  
};  

#endif // WARCRAFT_LION_H

