/*************************
* File: creatInputNum2.cpp

* Author: yinganmin6837@163.com(Ganmin Yin)

* Time: 2018/04/21

* Information:
*** This file reads a set of integers in a file with a zero-ending condition
*** into an integer array(inputNum[100]).

**************************/

#include<iostream>
#include<string.h>
#include "creatInputNum2.h"

using namespace std;

extern int inputNum[100];

/*********creatInputNum2(file)********/
void creatInputNum2()
{
	system("cls");
	FILE *pFile;
	pFile = fopen("data.txt","r");
	if(pFile==NULL)
	{
		cout<<"File open error!"<<endl;
		system("pause");
		return ;
	}
	//从文件中读取整数组到数组inputNum[100]中 
	int i,j=0;
	while(!feof(pFile))
	{
		fscanf(pFile,"%d",&i);
		inputNum[j++]=i;
	}
	fclose(pFile);
	pFile=NULL;
}
