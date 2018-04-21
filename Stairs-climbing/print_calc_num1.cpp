/*************************
* File: print_calc_num1.cpp

* Author: yinganmin6837@163.com(Ganmin Yin)

* Time: 2018/04/21

* Information:
*** This file prints out the results of integers that were entered 
*** into inputNum[100] calculated by a recursive method.
*** And for some unreasonale values, it will return the corresponding
*** error message and will not terminate.

**************************/

#include<iostream>
#include "print_calc_num1.h"
#include "calc_recur.h"

using namespace std;

extern int inputNum[100];

/*******print_calc_num1*******/
void print_calc_num1()
{
	system("cls");
	cout<<"以下为计算结果："<<endl;
	int i,n;
	//输出结果，且能够返回错误信息 
	for(i=0;inputNum[i]!=0;i++)
	{
		n = inputNum[i];
		if(n<0)
		{
			cout<<"输入为负数，不能计算"<<endl;
			continue;
		}
		if(n>200)
		{
			cout<<n<<"大于200，超出了题设要求"<<endl;
			continue;
		}
		cout<<calc_recur(n)<<endl;
	}
	cout<<"Bye!\n"<<endl;
	system("pause");
	return ;
}
