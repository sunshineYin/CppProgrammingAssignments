// File: warrior.cpp
// Author: yinganmin6837@163(gmail).com(Ganmin Yin)
// Date: 2018/06/29
// Description:
//    The implementation of the class "Warrior".


#include "warrior.h"
#include "headquarter.h"
#include "city.h"



using namespace std;

// initialization.
Warrior::Warrior(string name_, int force_, int elem_, int color_, int code_, int site_, string colorNm) :name(name_), force(force_), element(elem_), color(color_), code(code_), site(site_), colorName(colorNm){}  

Warrior::~Warrior() = default;

void Warrior::attack(Warrior & enemy,City & city,int time)  
{  
    if (enemy.name == "lion")  
        enemy.tmpElem = enemy.element;  
    enemy.element = enemy.element - force;  
	cout << setfill('0') << setw(3) << time / 60 << ":" << setfill('0') << setw(2) << time % 60 << " ";  
    cout << colorName<<" " << name << " " << code << " attacked " <<enemy.colorName<<" "<< enemy.name << " " << enemy.code << " in city " << city.site<< " with " << element << " elements and force " << force << endl;    
	
	if (enemy.element <= 0)  
    {
        enemy.lose(*this,city,time);  
        city.winnerWr= this; 
        win(city, time);  
    }  
    else  
        enemy.fightback(* this, city,time);   
} 

void Warrior::fightback(Warrior & enemy, City & city,int time)  
{  
    enemy.element = enemy.element - force/2;  
    cout << setfill('0') << setw(3) << time / 60 << ":" << setfill('0') << setw(2) << time % 60 << " ";  
    cout <<colorName<<" " << name << " " << code << " fought back against "<<enemy.colorName<<" "<< enemy.name << " " << enemy.code << " in city " << city.site << endl;  
    
	if (enemy.element <= 0)  
    {    
        enemy.lose(*this,city,time);  
        city.winnerWr = this; 
        win(city, time);  
    }  
    else  
    {  
        draw(city);  
        enemy.draw(city);  
    }  
}  

void Warrior::rewardElem(Headquarter & headquarter)
{  
    if (headquarter.element >= 8)  
    {  
        element += 8;  
        headquarter.element -= 8;  
    }  
} 

void Warrior::win(City & city,int time) 
{  
    cout << setfill('0') << setw(3) << time / 60 << ":" << setfill('0') << setw(2) << time % 60 << " ";  
    cout << colorName << " " << name << " " << code << " earned " << city.element << " elements for his headquarter" << endl;  
    
	// occupy this city. 
    if ((city.flag != color)&&(city.last_winner == color))  
    {  
        city.flag = color;  
        cout << setfill('0') << setw(3) << time / 60 << ":" << setfill('0') << setw(2) << time % 60 << " ";  
        cout << colorName << " flag raised in city " << city.site << endl;  
    }  
    else  
        city.last_winner = color;  
}  

void Warrior::draw(City & city)  
{  
    city.last_winner=2;  
}  

void Warrior::lose(Warrior & enemy,City &city,int time)  
{  
    cout << setfill('0') << setw(3) << time / 60 << ":" << setfill('0') << setw(2) << time % 60 << " ";  
    cout << colorName<<" " << name << " " << code << " was killed in city " << city.site << endl;  
    
    city.num_warrior--;  
    city.wr[color]=NULL;  
}   

void Warrior::moveforward(City *city[],int N,Headquarter *headquarter[],int time)  
{  
	// Reduce the number of warriors in this city by one, 
	// then move to the next city, 
	// and increase the number of warriors in the next city by one. 
	// At the same time, point the warrior pointer in the city to itself. 
    if (color == 0)  
    {  
        if(site!=0)  
        {  
            city[site]->num_warrior--;  
            city[site]->wr[color] = NULL;  
        }  
        site++;  
        if (site == N + 1)  
        {  
            headquarter[1]->enemyWr[headquarter[1]->countEnemy]=this;  
            headquarter[1]->countEnemy++;  
        }  
        else  
        {  
            city[site]->num_warrior++;  
            city[site]->wr[color] = this;  
        }  
    }  
    if(color == 1)  
    {  
          
        if (site != N + 1)  
        {  
            city[site]->num_warrior--;  
            city[site]->wr[color] = NULL;  
        }  
        site--;  
        if (site ==0)  
        {  
            headquarter[0]->enemyWr[headquarter[0]->countEnemy] = this;  
            headquarter[0]->countEnemy++;  
        }  
        else  
        {  
            city[site]->num_warrior++;  
            city[site]->wr[color] = this;  
        }  
    }  
}

