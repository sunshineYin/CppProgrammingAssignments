/************************** 
* File:main.cpp

* Author:yinganmin6837@163.com(Ganmin Yin) 

* Time:2018/04/21

* Information:
*** This file is main function of the project.
*** And it includes the basic information function(title()) of this project.
*** Besides.it also implements a cyclical framework of the whole project.

**************************/ 

#include <iostream>
#include<string.h>
#include<stdlib.h>
#include "select_menu1.h"
#include "select_menu2.h"
#include "creatInputNum1.h"
#include "creatInputNum2.h"
#include "print_calc_num1.h"
#include "print_calc_num2.h"

using namespace std;

const int MAX_STRLEN = 70;//��Ԥ���㣬����200λ����¥�ݷ�������������һ��������70λ������ 
const int MAX_INPUTNUM = 200;//��ĿҪ���������������ֵ 

int inputNum[100] = {0};//���û�����/�ļ������һ������������һ�������У�Ĭ������Ϊ100���������޸� 

/**************��Ŀ�����Ϣ����*****************/ 
void title()
{
	cout<<"\n\t\t=======================";
	cout<<"\n\n\t\t*��¥������";
	cout<<"\n\n\t\t*���ߣ���������1600012436��";
	cout<<"\n\n\t\t*ʱ�䣺2018/04/21";
	cout<<"\n\n\t\t=======================";
	cout<<"\n";
	system("pause"); 
}

int main() 
{
	int n,m;
	title();
	//��һ��ѭ��������û����������ݷ�ʽ��ѡ�񣬼���������/�ļ����� 
	while(1)
	{
		n = select_menu1();
		if(n == 1)
		{
			//�ڶ���ѭ��������û��Լ��㷽����ѡ�񣬼��ݹ�/�ǵݹ� 
			while(1)
			{
				m = select_menu2();
				if(m == 1)
				{
					creatInputNum1();
					print_calc_num1();
					//��һ�β�����Ϊ����inputNum����ǰ��Ӱ�죬��������С����㡱���� 
					memset(inputNum,0,sizeof(inputNum));
				}
				if(m == 2)
				{
					creatInputNum1();
					print_calc_num2();
					//�����㡱���� 
					memset(inputNum,0,sizeof(inputNum));
				}
				if(m == 0) break;//��ֹ�ڲ�ѭ����ʵ�֡�������һ�������� 
				
			}
		}
		if(n == 2)
		{
			while(1)
			{
				m = select_menu2();
				if(m == 1)
				{
					creatInputNum2();
					print_calc_num1();
					//�����㡱���� 
					memset(inputNum,0,sizeof(inputNum));
				}
				if(m == 2)
				{
					creatInputNum2();
					print_calc_num2();
					//�����㡱���� 
					memset(inputNum,0,sizeof(inputNum));
				}
				if(m == 0) break;//��ֹ�ڲ�ѭ����ʵ�֡�������һ�������� 
			}
		}
		//��ֹ���ѭ�����˳����� 
		if(n == 0)
		{
			cout<<"\nHave a nice day!Bye~\n"<<endl;
			system("pause");
			exit(0);
		}
	}
	return 0;
}
