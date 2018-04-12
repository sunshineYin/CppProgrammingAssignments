#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "statement.h"

using namespace std;

/**************主函数程序*****************/
double x,y;

int main()
{
	time_t t_start,t_end;
	t_start = time(NULL);//计算函数所耗时间 
	long Num = 50000000;//蒙特卡洛投点次数 
	long Count = 0;
	srand((unsigned)time(NULL));//以时间为随机数种子 
	for(long k=0;k<Num;k++)
	{
		x = (int)(20000.0*rand()/RAND_MAX);
		y = (int)(20000.0*rand()/RAND_MAX);
		if(checkFunc(x,y)==1)
		{
			Count++;
		}
	}
	double pi;
	pi = 4.0*Count/Num;//估算PI值
	/**********判断估算值有效位数**********/ 
	char str[20],piStr[20]="3.1415926";
	char *p = float2str(pi,str);
	int n=0;
	for(int k=0;k<20;k++)
	{
		if(p[k]==piStr[k])
			n++;
		else
			break;
	}
	/*************输出各种信息*************/ 
	cout<<"作者：尹赣闽（1600012436）"<<"\t"<<"提交时间：2018/03/16"<<endl;
	cout<<"程序的目标和主要方法："<<endl;
	cout<<"程序目标：估算PI值"<<"\t"<<"主要方法：蒙特卡洛随机法"<<endl;
	cout<<"程序亮点：感觉没有:)"<<endl;
	printf("本次计算获得的PI值为：%.7f\n",pi);
	t_end = time(NULL);
	printf("本次估算耗费的时间为：%f s\n",difftime(t_end,t_start));
	printf("PI的有效位数为：%d",n-1);//去掉小数点包含的一位，实际有效位数为n-1 
	system("pause");
	return 0;
 } 
