#include<iostream>
#include<string.h>
#include "statement.h"

using namespace std;

int prime[200]={0};
/************�����������麯��****************/ 
void creatPrimeArray(int *prime)
{
	//�����в�����MAX���������ñ�ǩ���������������ǩΪtrue������Ϊfalse 
	bool primeTag[MAX];
	//����memset���������������ʼ��Ϊtrue 
	memset(primeTag,true,sizeof(primeTag));
	//ɸѡ��������������С����˳�򸳸�prime���� 
	int i,j,n=0;
	for(i=2;i<MAX;i++)
	{
		if(primeTag[i])
		{
			for(j=2*i;j<MAX;j+=i)//���i����������2*i��3*i��4*i...���������� 
			{
				primeTag[j] = false;
			}
			prime[n++]=i;
		}
	}
}
