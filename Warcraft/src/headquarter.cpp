// File: headquarter.cpp
// Author: yinganmin6837@163(gmail).com(Ganmin Yin)
// Date: 2018/06/29
// Description:
//    The implementation of the class "Headquarter".



#include "headquarter.h"
#include "dragon.h"
#include "ninjia.h"
#include "iceman.h"
#include "lion.h"
#include "wolf.h"

using namespace std;

// initialization
Headquarter::Headquarter(int color_, int elem_, int round_, int site_, string colorNm) :Place(elem_),color(color_), round(round_), site(site_), colorName(colorNm) 
{
	enemyWr[2] = { NULL };
    newBornWr=NULL;
    index = 0;
    countEnemy = 0; 
	record = 0;
    army[200] = { NULL };  
    warriorCode = 0;
}  

Headquarter::~Headquarter()  
{  
    for (int i = 0; i < warriorCode; i++)  
        if (army[i])  
            delete army[i];  
}  

void Headquarter::printWarriorBornInfo(int time)  
{  
    cout << setfill('0') << setw(3) << time / 60 << ":" << setfill('0') << setw(2) << time % 60 << " ";  
    cout << colorName << " " << army[warriorCode]->name << " " << warriorCode + 1 << " born" << endl;  
    
}  

// Based on the "produceWrOrder", to produce warriors.
void Headquarter::produceWr(int time, int iniElem_Wr[][WR_TYPE_NUM], int iniForce_Wr[][WR_TYPE_NUM])  
{  
    switch (produceWrOrder[color][index])  
    {  
    case 0:  
    {  
        if (iniElem_Wr[round][0] <= element)  
        {  
            element -= iniElem_Wr[round][0];  
            army[warriorCode] = new Dragon("dragon", iniForce_Wr[round][0], iniElem_Wr[round][0], color, warriorCode + 1, site, colorName);  
            newBornWr = army[warriorCode];  
            printWarriorBornInfo(time);   
            warriorCode++; index++;   
            if (index == 5) index = 0;  
        }  
        break;  
    }  
    case 1:  
    {  
        if (iniElem_Wr[round][1] <= element)  
        {  
            element -= iniElem_Wr[round][1];  
            army[warriorCode] = new Ninjia("ninja", iniForce_Wr[round][1], iniElem_Wr[round][1], color, warriorCode + 1, site, colorName);  
            newBornWr = army[warriorCode];  
            printWarriorBornInfo(time);  
            warriorCode++; index++;   
            if (index == 5) index = 0;  
        }  
        break;  
    }  
    case 2:  
    {  
        if (iniElem_Wr[round][2] <= element)  
        {  
            element -= iniElem_Wr[round][2];  
            army[warriorCode] = new Iceman("iceman", iniForce_Wr[round][2], iniElem_Wr[round][2], color, warriorCode + 1, site, colorName);  
            newBornWr = army[warriorCode];  
            printWarriorBornInfo(time);  
            warriorCode++; index++;   
            if (index == 5) index = 0;  
        }  
        break;  
    }  
    case 3:  
    {  
        if (iniElem_Wr[round][3] <= element)  
        {  
            element -= iniElem_Wr[round][3];  
            army[warriorCode] = new Lion("lion", iniForce_Wr[round][3], iniElem_Wr[round][3], color, warriorCode + 1, site, colorName);  
            newBornWr = army[warriorCode];  
            printWarriorBornInfo(time);  
            //cout << "Its loyalty is " << element << endl;  
            warriorCode++; index++;   
            if (index == 5) index = 0;  
        }  
        break;  
    }  
    case 4:  
    {  
        if (iniElem_Wr[round][4] <= element)  
        {  
            element -= iniElem_Wr[round][4];  
            army[warriorCode] = new Wolf("wolf", iniForce_Wr[round][4], iniElem_Wr[round][4], color, warriorCode + 1, site, colorName);  
            newBornWr = army[warriorCode];  
            printWarriorBornInfo(time);  
            warriorCode++; index++;   
            if (index == 5) index = 0;  
        }  
        break;  
    }  
    }  
}  

void Headquarter::printEnemyArrivedInfo(int time, bool & stop)  
{
	// the number of arrived enemy didn't change. do nothing and derectly return.  
    if (record == countEnemy)  
        return;  
    else  
    {  
        switch (countEnemy)  
        {  
        case 0: break;
		// 1 enemy arrived.  
        case 1: {  
            cout << setfill('0') << setw(3) << time / 60 << ":" << setfill('0') << setw(2) << time % 60 << " ";  
            cout << enemyWr[0]->colorName << " " << enemyWr[0]->name << " " << enemyWr[0]->code << " reached " << colorName << " headquarter with " << enemyWr[0]->element << " elements and force " << enemyWr[0]->force << endl;  
			
			record = 1; break;  
        }  
        // 2 enemy arrived. and this headquarter would be taken. game is over.
        case 2:  
        {  
            cout << setfill('0') << setw(3) << time / 60 << ":" << setfill('0') << setw(2) << time % 60 << " ";  
            cout << enemyWr[1]->colorName << " " << enemyWr[1]->name << " " << enemyWr[1]->code << " reached " << colorName << " headquarter with " << enemyWr[1]->element << " elements and force " << enemyWr[1]->force << endl;  
            
            cout << setfill('0') << setw(3) << time / 60 << ":" << setfill('0') << setw(2) << time % 60 << " ";  
            cout << colorName << " headquarter was taken" << endl;  
            
            stop = 1; record = 2; break;  
        }  
        }  
    }  
}  

void Headquarter::printElemInfo(int time)//输出阵营的生命元  
{  
    cout << setfill('0') << setw(3) << time / 60 << ":" << setfill('0') << setw(2) << time % 60 << " ";  
    cout << element << " elements in " << colorName << " headquarter" << endl;
}  

int Headquarter::produceWrOrder[2][5] = { { 2,3,4,1,0 },{ 3,0,1,2,4 } };  


