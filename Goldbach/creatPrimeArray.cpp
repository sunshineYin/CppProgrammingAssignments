#include<iostream>
#include<string.h>
#include "statement.h"

using namespace std;

int prime[200]={0};
/************创建素数数组函数****************/ 
void creatPrimeArray(int *prime)
{
	//给所有不大于MAX的整数设置标签，如果是素数，标签为true，否则为false 
	bool primeTag[MAX];
	//利用memset函数，将该数组初始化为true 
	memset(primeTag,true,sizeof(primeTag));
	//筛选法，将素数按从小到大顺序赋给prime数组 
	int i,j,n=0;
	for(i=2;i<MAX;i++)
	{
		if(primeTag[i])
		{
			for(j=2*i;j<MAX;j+=i)//如果i是素数，则2*i，3*i，4*i...都不是素数 
			{
				primeTag[j] = false;
			}
			prime[n++]=i;
		}
	}
}
