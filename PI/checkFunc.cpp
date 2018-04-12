#include <iostream>
#include "statement.h"

using namespace std;

/**********判断点是否位于圆内函数***********/ 

int checkFunc(double x,double y)
{
	double i,j;
	i = x/10000-1;
	j = y/10000-1;
	//在圆内返回1 
	if((i*i+j*j)<=1)
	{
		return 1;
	}
	//不在圆内返回0 
	else
	{
		return 0;
	}
}
