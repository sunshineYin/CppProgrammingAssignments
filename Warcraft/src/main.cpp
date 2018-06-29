#include<iostream>  
#include<iomanip>  
#include<string>  
#include <cstring>   

#include "place.h"
#include "headquarter.h"
#include "city.h"
#include "warrior.h"
#include "dragon.h"
#include "ninjia.h"
#include "iceman.h"
#include "lion.h"
#include "wolf.h"

using namespace std;  


// should not be regarded as global variables.
   
const int TEST_MAX_NUM = 100;//Ԥ����������ݵ������������պ��޸ġ�  



int main()  
{  
    int test;  
    cin >> test;  
    bool stop;//�Ƿ�����Ӫ��ռ��
    int iniElem_Wr[TEST_MAX_NUM][WR_TYPE_NUM] = { 0 }, iniForce_Wr[TEST_MAX_NUM][WR_TYPE_NUM] = { 0 };   
    //int M[testdata] = { 0 }, N[testdata] = { 0 }, T[testdata] = { 0 };
    int M[TEST_MAX_NUM] = { 0 }, N[TEST_MAX_NUM] = { 0 }, T[TEST_MAX_NUM] = { 0 };  
	for (int i = 0; i < test; i++)//�������в�������  
    {  
        cin >> M[i] >> N[i] >> T[i];
		//fscanf(pFile,"%d %d %d", &M[i], &N[i], &T[i]);
		//fscanf(pFile,"%d %d %d %d %d", &iniElem_Wr[i][0], &iniElem_Wr[i][1], &iniElem_Wr[i][2], &iniElem_Wr[i][3], &iniElem_Wr[i][4]);
		//fscanf(pFile,"%d %d %d %d %d", &iniForce_Wr[i][0], &iniForce_Wr[i][1], &iniForce_Wr[i][2], &iniForce_Wr[i][3], &iniForce_Wr[i][4]);

        for (int j = 0; j < WR_TYPE_NUM; j++)  
            cin >> iniElem_Wr[i][j];  
        for (int j = 0; j < WR_TYPE_NUM; j++)  
            cin >> iniForce_Wr[i][j];

    }  
    
    system("cls");
    
    for (int i = 0; i < test; i++)//��ʼ��Ϸ  
    {  
        int time = 0;  
        Headquarter *headquater[2];  
        City*city[25] = {NULL};  
        headquater[0] = new Headquarter(0, M[i], i, 0, "red");  
        headquater[1] = new Headquarter(1, M[i], i, N[i] + 1, "blue");  
		for (int j = 1; j < N[i] + 1; j++)  
		{	  
    		city[j] = new City(j, 2);  
    		city[j]->site = j;  
		} 
		
		cout << "Case " << i + 1 << ":" << endl; 
		
		while (!stop)  
		{  
    		//������ʿ  
    		headquater[0]->produceWr(time, iniElem_Wr, iniForce_Wr);  
    		headquater[1]->produceWr(time, iniElem_Wr, iniForce_Wr);  
    		
			time += 10; if (time > T[i]) break;//��10���ӣ����ָ�벻Ϊ�գ���ôָ��ָ�����ʿǰ��  
    		for (int j = N[i]; j > 0; j--)  
        		if (city[j]->wr[0])  
            		city[j]->wr[0]->moveforward(city, N[i], headquater, time);  
    		if (headquater[0]->newBornWr)  
    		{  
        		headquater[0]->newBornWr->moveforward(city, N[i], headquater, time);  
        		headquater[0]->newBornWr = NULL;  
    		}  
    		for (int j = 1; j < N[i] + 1; j++)  
        		if (city[j]->wr[1])  
            		city[j]->wr[1]->moveforward(city, N[i], headquater, time);  
    		if (headquater[1]->newBornWr)  
    		{  
        		headquater[1]->newBornWr->moveforward(city, N[i], headquater, time);  
        		headquater[1]->newBornWr = NULL;  
    		}  
    		headquater[0]->printEnemyArrivedInfo(time, stop);//��ӡ��ʿǰ�������  
    		for (int j = 1; j < N[i] + 1; j++)  
        		city[j]->printWarriorArrivedInfo(time);  
    		headquater[1]->printEnemyArrivedInfo(time, stop);
			  
    		if (!stop)  
    		{  
        		time += 10; if (time > T[i]) break;//��20���ӣ���������10��element  
        		for (int j = 1; j < N[i] + 1; j++)  
            		city[j]->elementPlus(); 
					 
        		time += 10; if (time > T[i]) break;//��30���ӣ��������ֻ��һ����ʿ����ô��ʿȡ��element  
        		for (int j = 1; j < N[i] + 1; j++)  
        		{  
            		if ((city[j]->wr[0] == NULL)&&(city[j]->wr[1] != NULL))  
                		city[j]->transferElem(*headquater[1], time, 1);  
            		if ((city[j]->wr[0] != NULL)&&(city[j]->wr[1] == NULL))  
                		city[j]->transferElem(*headquater[0], time, 0);  
        		}  
        		time += 10; if (time > T[i]) break;//��40���ӣ������򶫣�ս����ʼ  
        		for (int j = 1; j < N[i] + 1; j++)  
        		{  
            		if (city[j]->num_warrior == 2)  
            		{  
                		if ((city[j]->wr[0]->element > 0)&&(city[j]->wr[1]->element > 0))  
                		{  
                    		if ((city[j]->flag == 0) || ((city[j]->flag == 2)&&(city[j]->site % 2 == 1)))  
                        		city[j]->wr[0]->attack(*city[j]->wr[1], *city[j], time);  
                    		else  
                        		city[j]->wr[1]->attack(*city[j]->wr[0], *city[j], time);  
                		}  
                		else if ((city[j]->wr[1]->element <= 0)&&(city[j]->wr[0]->element <=0))  
                		{  
                    		city[j]->winnerWr = NULL;  
                    		city[j]->num_warrior = 0;  
                    		city[j]->wr[0] = NULL; city[j]->wr[1] = NULL;  
                		}  
                		else if ((city[j]->wr[0]->element > 0)&&(city[j]->wr[1]->element <= 0))  
                		{  
                    		//city[j]->wr[0]->getWeapon(*city[j]->wr[1]);  
                    		city[j]->wr[0]->win(*city[j], time);  
                    		city[j]->winnerWr = city[j]->wr[0];  
                    		city[j]->wr[1] = NULL; city[j]->num_warrior--;  
                		}  
                		else if ((city[j]->wr[0]->element <= 0)&&(city[j]->wr[1]->element>0))  
                		{  
                    		//city[j]->wr[1]->getWeapon(*city[j]->wr[0]);  
                    		city[j]->wr[1]->win(*city[j], time); 
							city[j]->winnerWr = city[j]->wr[1];   
                    		city[j]->wr[0] = NULL; city[j]->num_warrior--;  
                		}         
            		}  
            		else if (city[j]->num_warrior == 1)  
            		{  
                		if (city[j]->wr[0])  
                		{  
                    		if (city[j]->wr[0]->element <= 0)  
                    		{  
                        		city[j]->wr[0] = NULL;  
                        		city[j]->num_warrior = 0;  
                    		}  
                		}  
                		else if (city[j]->wr[1])  
                		{  
                    		if (city[j]->wr[1]->element <= 0)  
                    		{  
                        		city[j]->wr[1] = NULL;  
                        		city[j]->num_warrior = 0;  
                    		}  
                		}  
            		}  
        		}
					  
        		for (int j = 1; j < N[i] + 1; j++)//�����򶫣�����Ӫ������ʤ��ʿ  
        		{  
            		if (city[j]->winnerWr)  
                		if (city[j]->winnerWr->color == 1)  
                    		city[j]->winnerWr->rewardElem(*headquater[1]);  
        		}  
        		for (int j = N[i]; j > 0; j--)//�Զ�����������Ӫ������ʤ��ʿ  
        		{  
            		if (city[j]->winnerWr)  
                		if (city[j]->winnerWr->color == 0)  
                    		city[j]->winnerWr->rewardElem(*headquater[0]);  
        		}
				  
        		for (int j = 1; j < N[i] + 1; j++)//ʤ�߻��ճ���element  
            		if (city[j]->winnerWr)  
            		{  
                		headquater[city[j]->winnerWr->color]->element += city[j]->element;  
                		city[j]->element = 0;  
            		}  
            		
        		time += 10; if (time > T[i]) break;//��50���ӣ���Ӫ����element  
        		headquater[0]->printElemInfo(time);  
        		headquater[1]->printElemInfo(time);  
        	}  
        	time += 10;  
        }  
        delete headquater[0]; delete headquater[1];  
        for (int i = 0; i < 25; i++)  
            if (city[i])  
                delete city[i];  
        cout<<"\n";
        stop = 0;  
    }  
    system("pause");
    return 0;  
}  

