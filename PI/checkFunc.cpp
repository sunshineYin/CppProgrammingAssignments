#include <iostream>
#include "statement.h"

using namespace std;

/**********�жϵ��Ƿ�λ��Բ�ں���***********/ 

int checkFunc(double x,double y)
{
	double i,j;
	i = x/10000-1;
	j = y/10000-1;
	//��Բ�ڷ���1 
	if((i*i+j*j)<=1)
	{
		return 1;
	}
	//����Բ�ڷ���0 
	else
	{
		return 0;
	}
}
