/*************************
* File:big_number_plus.cpp

* Author:yinganmin6837@163.com(Ganmin Yin)

* Time:2018/04/21

* Information:
*** This file mainly implements the add operation(plus) of big numbers(integers).
*** It uses character pointers(char*) to store big numbers.
*** And it uses character pointers(char*) as input parameters and output results. 
*** The nonsense 0(many) in the biginning of its return result(big number)
*** are removed to conform our usage habits.(e.g. 000012345678987654321 -> 12345678987654321)

**************************/

#include<iostream>
#include<string.h>
#include "big_number_plus.h"

using namespace std;

extern const int MAX_STRLEN = 70;
extern const int MAX_INPUTNUM = 200;

/***************Big Number Plus******************/
char* big_number_plus(char *num_str1,char *num_str2)
{
	/*
	用两个数组存储传入的大整数的各个位的数字，
	数组第一项num_array[0]表示个位数，第二项表示十位数，以此类推
	目的是便于实现对大整数加法中各个位数字的相加，进而实现大整数加法 
	*/
	int num_array1[MAX_STRLEN];
	int num_array2[MAX_STRLEN];
	//数组初始化 
	memset(num_array1,0,sizeof(num_array1));
	memset(num_array2,0,sizeof(num_array2));
	int i,j;
	int len1 = strlen(num_str1);
	int len2 = strlen(num_str2); 
	j=0;
	//循环实现数组存储大整数1 
	for(i=len1-1;i>=0;i--)
		num_array1[j++]=num_str1[i]-'0';
	j=0;
	//循环实现数组存储大整数2 
	for(i=len2-1;i>=0;i--)
		num_array2[j++]=num_str2[i]-'0';
	//实现大整数加法的核心代码 
	for(i=0;i<MAX_STRLEN;i++)
	{
		num_array1[i]+=num_array2[i];
		if(num_array1[i]>=10)
		{
			num_array1[i]-=10;
			num_array1[i+1]++;
		}
	}
	//再将得到的大整数的存储数组转换为字符指针并返回 
	char num_str3[MAX_STRLEN];
	j=0;
	for(i=MAX_STRLEN;i>0;i--)
		num_str3[i]=num_array1[j++]+'0';
	char *p=num_str3;
	while(*(++p)=='0');//去除大整数第一个非零数字前面的众多“0”，以符合实际使用习惯 
	return p;
}
