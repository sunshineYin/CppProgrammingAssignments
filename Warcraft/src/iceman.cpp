// File: iceman.cpp
// Author: yinganmin6837@163(gmail).com(Ganmin Yin)
// Date: 2018/06/29
// Description:
//    The implementation of the class "Iceman".



#include "iceman.h"

using namespace std;

// initialization.
Iceman::Iceman(string name_, int force_, int elem_, int color_, int code_, int site_, string colorNm) :Warrior(name_, force_, elem_, color_, code_, site_, colorNm)
{
	countStep = 0;
} 

Iceman::~Iceman() = default;

void Iceman::moveforward(City *city[], int N, Headquarter *headquarter[],int time)  
{  
	Warrior::moveforward(city, N, headquarter,time);  
    countStep++;  
    if (countStep == 2)  
    {  
        if (element > 9)  
            element -= 9;  
        else  
            element = 1;  
        force += 20;  
        countStep = 0;  
    }  
}   

