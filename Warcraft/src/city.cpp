// File: city.cpp
// Author: yinganmin6837@163(gmail).com(Ganmin Yin)
// Date: 2018/06/29
// Description:
//    The implementation of the class "City".

#include "city.h"


using namespace std;

// Initialization.
City::City(int site_, int flag_): Place(), site(site_), flag(flag_)
{
	last_winner = 2;
	num_warrior = 0;
	wr[2] = { NULL };
	winnerWr = NULL;
}

City::City(int site_, int flag_, int elem_, int num_) :Place(elem_), site(site_), flag(flag_), num_warrior(num_)  
{
	last_winner = 2;  
    wr[2] = { NULL };  
    winnerWr = NULL;  
}  

City::~City() = default;

void City::elementPlus() 
{ 
	element += 10; 
	winnerWr = NULL; 
}  

void City::transferElem(Headquarter & headquarter, int time,int color)  
{  
    headquarter.element += element;  
    cout << setfill('0') << setw(3) << time / 60 << ":" << setfill('0') << setw(2) << time % 60 << " ";  
    cout << wr[color]->colorName << " " << wr[color]->name << " " << wr[color]->code << " earned " << element << " elements for his headquarter" << endl;  
	element = 0;  
}  

void City::printWarriorArrivedInfo(int time)  
{  
      
    if (wr[0])  
    {  
        cout << setfill('0') << setw(3) << time / 60 << ":" << setfill('0') << setw(2) << time % 60 << " ";  
        cout << "red " << wr[0]->name << " " << wr[0]->code << " marched to city " << site  << " with " << wr[0]->element << " elements and force " << wr[0]->force << endl;  
    }  
    if (wr[1])  
    {  
        cout << setfill('0') << setw(3) << time / 60 << ":" << setfill('0') << setw(2) << time % 60 << " ";  
        cout << "blue " << wr[1]->name << " " << wr[1]->code << " marched to city " << site << " with " << wr[1]->element << " elements and force " << wr[1]->force << endl;
    }  
} 


