#include<iostream>
#include<string.h>
//#include<typeinfo.h> 
#include "statement.h"

using namespace std;

extern const int MAX = 1000;//定义外部常量MAX=1000 

/************主函数**************/ 
int main()
{
	int i,n,m;
	bool flag;//验证哥德巴赫猜想的结果 
	creatPrimeArray(prime);//创建不大于1000的素数数组 
	cout<<"请输入一组不小于4，且不大于"<<MAX<<"的偶数（以0为结束）"<<endl;
	creatInputNum(inputNum);//用户一次性输入多个整数，以0为结束，得到一个数组 
	system("cls");
	/*****用户友好界面：可以选择输出一组或所有素数组合******/ 
	cout<<"请选择输出方式（0/1）："<<endl;
	cout<<"0：输出一组素数组合\t1：输出所有素数组合"<<endl;
	cout<<"请输入0/1："<<endl;
	cin>>m; 
	system("cls");
	//对所有输入整数（已被存入数组inputNum中）进行验证 
	for(i=0;inputNum[i]!=0;i++)
	{
		n=inputNum[i];
		/***对不合要求的整数作抛出错误处理，并给出清晰的提示信息，同时不终止程序*****/
		/*if(typeid(n)!=typeid(int))
		{
			cout<<n<<"不是整数，不能验证哥德巴赫猜想"<<endl;
			continue;
		} */
		if(n<=2)
		{
			cout<<n<<"小于等于2，不能验证哥德巴赫猜想"<<endl;
			continue;
		}
		if(n>MAX)
		{
			cout<<n<<"大于"<<MAX<<"，超出了题设验证范围"<<endl;
			continue; 
		}
		if(n%2==1)
		{
			cout<<n<<"是奇数，不能验证哥德巴赫猜想"<<endl;
			continue;
		}
		flag=false;//初始化flag 
		int j,k;
		//prime[j]、prime[k]分别是较小、较大的素数 
		for(j=0;prime[j]<=int(n/2);j++)
		{
			for(k=j;prime[j]+prime[k]<n;k++);
			if(prime[j]+prime[k]==n)
			{
				flag=true;
				cout<<n<<'='<<prime[j]<<'+'<<prime[k]<<endl;
				if(m==0) break;//输出一组/输出所有 
			}
		}
		//“可能”出现的哥德巴赫猜想出错的情况 :) 
		if(!flag) cout<<"已证明哥德巴赫猜想错误！\t反例："<<n<<endl;
	}
	cout<<"Bye!"<<endl;
	system("pause");
	return 0;
}
