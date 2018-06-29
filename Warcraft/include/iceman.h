// File: iceman.h
// Author: yinganmin6837@163(gmail).com(Ganmin Yin)
// Date: 2018/06/29
// Description:
//    The declaration of the class "Iceman".


#ifndef WARCRAFT_ICEMAN_H
#define WARCRAFT_ICEMAN_H

#include "warrior.h"
#include "headquarter.h"
#include "city.h"

#include<iostream>  
#include<iomanip>  
#include<string>  
#include <cstring>  

using namespace std;

class Iceman;

class Iceman :public Warrior 
{  
    public:
	  
    	Iceman(string name_, int force_, int elem_, int color_, int code_, int site_, string colorNm);
    	~Iceman();
    	// overwrite the member function "moveforward".
		void moveforward(City *city[], int N, Headquarter *headquarter[], int time);  
    
	private:
		int countStep; // the number of steps. 
};

#endif // WARCRAFT_ICEMAN_H  

