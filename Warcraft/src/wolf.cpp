// File: wolf.cpp
// Author: yinganmin6837@163(gmail).com(Ganmin Yin)
// Date: 2018/06/29
// Description:
//    The implementation of the class "Wolf".


#include "wolf.h"


using namespace std;

// initialization.
Wolf::Wolf(string name_, int force_, int elem_, int color_, int code_, int site_, string colorNm) :Warrior(name_, force_, elem_, color_, code_, site_, colorNm) 
{
	num_kills_by_attack = 0;
}  

Wolf::~Wolf() = default;

void Wolf::attack(Warrior & enemy,City & city,int time)  
{  
    if (enemy.name == "lion")  
        enemy.tmpElem = enemy.element;  
    enemy.element = enemy.element - force;  

	cout << setfill('0') << setw(3) << time / 60 << ":" << setfill('0') << setw(2) << time % 60 << " ";  
    cout << colorName<<" " << name << " " << code << " attacked " <<enemy.colorName<<" "<< enemy.name << " " << enemy.code << " in city " << city.site<< " with " << element << " elements and force " << force << endl;    
    
	if (enemy.element <= 0)  
    {  
		num_kills_by_attack++;
		if(num_kills_by_attack % 2 == 0)
		{
			element += element;
			force += force;
		}  
        enemy.lose(*this,city,time);  
        city.winnerWr= this;
        win(city, time);  
    }  
    else  
        enemy.fightback(* this, city,time);       
}  


