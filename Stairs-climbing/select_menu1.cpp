/*************************
* File: select_menu1.cpp

* Author: yinganmin6837@163.com(Ganmin Yin)

* Time: 2018/04/21

* Information:
*** This file provides user with 3 chioces of data-input methods.
*** Totally 3 chioces:
*** 1.nomally  2.file  0.exit 

**************************/

#include<iostream>
#include "select_menu1.h"

using namespace std;

/*****select i/o ways****/
int select_menu1()
{
	//1.normal
	//2.file
	//0.exit
	char c;
	do
	{
		system("cls");
		cout<<"��ѡ���������ݵķ�ʽ��\n"<<endl;
		cout<<"1��������������\t2���ļ���������\t0���˳�\n"<<endl;
		cout<<"��ѡ��0-2��"<<endl;
		cin>>c;
		switch(c)
		{
			case '1':cout<<"������������\n"<<endl;break;
			case '2':cout<<"�ļ���������\n"<<endl;break;
			case '0':break;
		}
		system("pause");
	}
	while(c<'0'||c>'2');
	return c-'0';
}
