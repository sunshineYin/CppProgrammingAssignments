#include<iostream>
#include "statement.h"

using namespace std;

int inputNum[100]={0};
/*************����������������inputNum�����У���0Ϊ����***************/ 
void creatInputNum(int *inputNum)
{
	int i=0;
	do
	{
		cin>>inputNum[i];
	}
	while(inputNum[i++]!=0);
}
