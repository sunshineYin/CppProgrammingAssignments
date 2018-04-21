/*************************
* File: calc_not_recur.cpp

* Author: yinganmin6837@163.com(Ganmin Yin)

* Time: 2018/04/21

* Information:
*** This file uses a non-recursive method to calculate the number of climbing stairs.
*** Based on a from-bottom-to-up idea, it uses a character pointer array(char* str_array)
*** to store all the big numbers, achieving space-for-time effects.

**************************/

#include<iostream>
#include<string.h>
#include "calc_not_recur.h"
#include "big_number_plus.h"

using namespace std;

extern const int MAX_STRLEN;
extern const int MAX_INPUTNUM;

/**********calc_not_recur**********/
char* calc_not_recur(int num)
{
	char *p = new char[MAX_STRLEN];
	if(num == 1)
	{
		strcpy(p,"1");
		return p;
	}
	if(num == 2)
	{
		strcpy(p,"2");
		return p;
	}
	//创建一个字符指针数组来存储大整数结果，以空间换时间 
	char *str_array[MAX_INPUTNUM+1];
	char *p1 = new char[MAX_STRLEN];
	strcpy(p1,"0");
	//str_array[0]初始化，并分配空间 
	str_array[0]=new char[MAX_STRLEN];
	strcpy(str_array[0],p1); 
	
	strcpy(p1,"1");
	//str_array[1]初始化，并分配空间 
	str_array[1]=new char[MAX_STRLEN];
	strcpy(str_array[1],p1);
	
	strcpy(p1,"2");
	//str_array[2]初始化，并分配空间 
	str_array[2]=new char[MAX_STRLEN];
	strcpy(str_array[2],p1);
	for(int i=3;i<=MAX_INPUTNUM;i++)
	{
		//str_array[i]初始化，并分配空间 
		str_array[i]=new char[MAX_STRLEN];
		strcpy(p1,big_number_plus(str_array[i-1],str_array[i-2]));
		strcpy(str_array[i],p1);
	}
	strcpy(p,str_array[num]);
	delete[] p1;
	return p;
}
