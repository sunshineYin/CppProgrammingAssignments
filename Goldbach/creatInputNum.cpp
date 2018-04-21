#include<iostream>
#include "statement.h"

using namespace std;

int inputNum[100]={0};
/*************将输入多个整数存入inputNum数组中，以0为结束***************/ 
void creatInputNum(int *inputNum)
{
	int i=0;
	do
	{
		cin>>inputNum[i];
	}
	while(inputNum[i++]!=0);
}
