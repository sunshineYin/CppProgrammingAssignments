// File: ninjia.cpp
// Author: yinganmin6837@163(gmail).com(Ganmin Yin)
// Date: 2018/06/29
// Description:
//    The implementation of the class "Ninjia".


#include "ninjia.h"

using namespace std;

Ninjia::Ninjia(string name_, int force_, int elem_, int color_, int code_, int site_, string colorNm) :Warrior(name_, force_, elem_, color_, code_, site_, colorNm){}

Ninjia::~Ninjia() = default;

void Ninjia::fightback(Warrior & enemy, City & city,int time)  
{  
    draw(city);  
    enemy.draw(city);  
}  

