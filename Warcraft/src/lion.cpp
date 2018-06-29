// File: lion.cpp
// Author: yinganmin6837@163(gmail).com(Ganmin Yin)
// Date: 2018/06/29
// Description:
//    The implementation of the class "Lion".


#include "lion.h"


using namespace std;

Lion::Lion(string name_, int force_, int elem_, int color_, int code_, int site_, string colorNm) :Warrior(name_, force_, elem_, color_, code_, site_, colorNm){} 

Lion::~Lion() = default;

void Lion::lose(Warrior & enemy,City& city,int time)  
{  
    cout << setfill('0') << setw(3) << time / 60 << ":" << setfill('0') << setw(2) << time % 60 << " ";  
    cout << colorName << " lion "<< code << " was killed in city " << city.site << endl;  
    
	enemy.element += tmpElem; city.num_warrior--;  
    city.wr[color]=NULL;  
}  

