/*************************
* File: calc_recur.cpp

* Author: yinganmin6837@163.com(Ganmin Yin)

* Time: 2018/04/21

* Information:
*** This file uses a simple recursive method to calculate the number of climbing stairs.

**************************/

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include "big_number_plus.h"
#include "calc_recur.h"

using namespace std;

extern const int MAX_STRLEN;

/***********calc_recur***********/
char* calc_recur(int num)
{
	char *p = (char*)calloc(MAX_STRLEN,sizeof(char*));
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
	strcpy(p,big_number_plus(calc_recur(num-1),calc_recur(num-2)));
	return p;
}
