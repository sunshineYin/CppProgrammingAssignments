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

const int MAX_STRLEN = 70;//经预计算，对于200位的爬楼梯方法的总数，是一个不超过70位的整数 
const int MAX_INPUTNUM = 200;//题目要求最大输入整数的值 

int inputNum[100] = {0};//将用户输入/文件读入的一组整数，存在一个数组中，默认上限为100个，可以修改 

/**************项目相关信息函数*****************/ 
void title()
{
	cout<<"\n\t\t=======================";
	cout<<"\n\n\t\t*爬楼梯问题";
	cout<<"\n\n\t\t*作者：尹赣闽（1600012436）";
	cout<<"\n\n\t\t*时间：2018/04/21";
	cout<<"\n\n\t\t=======================";
	cout<<"\n";
	system("pause"); 
}

int main() 
{
	int n,m;
	title();
	//第一重循环，针对用户对输入数据方式的选择，即正常输入/文件读入 
	while(1)
	{
		n = select_menu1();
		if(n == 1)
		{
			//第二重循环，针对用户对计算方法的选择，即递归/非递归 
			while(1)
			{
				m = select_menu2();
				if(m == 1)
				{
					creatInputNum1();
					print_calc_num1();
					//在一次操作后，为避免inputNum数组前后影响，在这里进行“清零”操作 
					memset(inputNum,0,sizeof(inputNum));
				}
				if(m == 2)
				{
					creatInputNum1();
					print_calc_num2();
					//“清零”操作 
					memset(inputNum,0,sizeof(inputNum));
				}
				if(m == 0) break;//终止内层循环，实现“返回上一级”操作 
				
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
					//“清零”操作 
					memset(inputNum,0,sizeof(inputNum));
				}
				if(m == 2)
				{
					creatInputNum2();
					print_calc_num2();
					//“清零”操作 
					memset(inputNum,0,sizeof(inputNum));
				}
				if(m == 0) break;//终止内层循环，实现“返回上一级”操作 
			}
		}
		//终止外层循环，退出程序 
		if(n == 0)
		{
			cout<<"\nHave a nice day!Bye~\n"<<endl;
			system("pause");
			exit(0);
		}
	}
	return 0;
}
