// File: dragon.cpp
// Author: yinganmin6837@163(gmail).com(Ganmin Yin)
// Date: 2018/06/29
// Description:
//    The implementation of the class "Dragon".



#include "dragon.h"



using namespace std;


Dragon::Dragon(string name_, int force_, int elem_, int color_, int code_, int site_, string colorNm) :Warrior(name_, force_, elem_, color_, code_, site_, colorNm){}

Dragon::~Dragon() = default;

void Dragon::attack(Warrior & enemy, City & city,int time)  
{  
    if (enemy.name == "lion")  
        enemy.tmpElem = enemy.element;  
    enemy.element = enemy.element - force;  
	cout << setfill('0') << setw(3) << time / 60 << ":" << setfill('0') << setw(2) << time % 60 << " ";  
    cout << colorName<<" " << name << " " << code << " attacked " <<enemy.colorName<<" "<< enemy.name << " " << enemy.code << " in city " << city.site<< " with " << element << " elements and force " << force << endl;    
	
	if (enemy.element <= 0)  
    {  
        enemy.lose(*this,city,time); // enemy lose(die).
        city.winnerWr = this; 
        yell(city, time); // the dragon will yell.
        win(city, time);  
    }  
    else  
    {    
        enemy.fightback(*this, city, time);  
        if (element > 0)  
            yell(city, time); // the dragon didn't die. and it also would yell.
    }  
} 

void Dragon::yell(City & city, int time)  
{  
    cout << setfill('0') << setw(3) << time / 60 << ":" << setfill('0') << setw(2) << time % 60 << " ";  
    cout<<colorName<<" dragon "<<code<< " yelled in city " << city.site << endl;
}  


