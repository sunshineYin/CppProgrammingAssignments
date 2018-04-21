/*************************
* File: select_menu2.cpp

* Author: yinganmin6837@163.com(Ganmin Yin)

* Time: 2018/04/21

* Information:
*** This file provides user with 3 choices of calculation methods.
*** Totally 3 choices:
*** 1.recursive  2.non-recursive  0.back to previous.

**************************/

#include<iostream>
#include "select_menu2.h"

using namespace std;

/********select calc ways********/
int select_menu2()
{
	//1.recursion
	//2.not recursion
	//0.exit
	char c;
	do
	{
		system("cls");
		cout<<"请选择计算方法（递归/非递归）：\n"<<endl;
		cout<<"1、递归\t2、非递归\t0、返回上一级\n"<<endl;
		cout<<"请选择0-2："<<endl;
		cin>>c;
		switch(c)
		{
			case '1':cout<<"采用递归方法"<<endl;cout<<"为避免电脑死机，请不要输入过大的数字（如:30+）！！！...\n"<<endl;break;
			case '2':cout<<"采用非递归方法\n"<<endl;break;
			case '0':break;
		}
		system("pause");
	}
	while(c<'0'||c>'2');
	return c-'0';
}
