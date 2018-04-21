/*************************
* File: creatInputNum1.cpp

* Author: yinganmin6837@163.com(Ganmin Yin)

* Time: 2018/04/21

* Information:
*** This file stores a set of integers entered by the user
*** with a zero-ending condition in an integer array(inputNum[100]).

**************************/

#include<iostream>
#include "creatInputNum1.h"

using namespace std;

extern int inputNum[100];

/********creatInputNum1(normal)********/
void creatInputNum1()
{
	system("cls");
	cout<<"请输入一组整数（1-200），以0为结束："<<endl;
	int i=0;
	do
	{
		cin>>inputNum[i];
	}
	while(inputNum[i++]!=0);
}
