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
		cout<<"��ѡ����㷽�����ݹ�/�ǵݹ飩��\n"<<endl;
		cout<<"1���ݹ�\t2���ǵݹ�\t0��������һ��\n"<<endl;
		cout<<"��ѡ��0-2��"<<endl;
		cin>>c;
		switch(c)
		{
			case '1':cout<<"���õݹ鷽��"<<endl;cout<<"Ϊ��������������벻Ҫ�����������֣���:30+��������...\n"<<endl;break;
			case '2':cout<<"���÷ǵݹ鷽��\n"<<endl;break;
			case '0':break;
		}
		system("pause");
	}
	while(c<'0'||c>'2');
	return c-'0';
}
