#include<iostream>
#include<string.h>
//#include<typeinfo.h> 
#include "statement.h"

using namespace std;

extern const int MAX = 1000;//�����ⲿ����MAX=1000 

/************������**************/ 
int main()
{
	int i,n,m;
	bool flag;//��֤��°ͺղ���Ľ�� 
	creatPrimeArray(prime);//����������1000���������� 
	cout<<"������һ�鲻С��4���Ҳ�����"<<MAX<<"��ż������0Ϊ������"<<endl;
	creatInputNum(inputNum);//�û�һ������������������0Ϊ�������õ�һ������ 
	system("cls");
	/*****�û��Ѻý��棺����ѡ�����һ��������������******/ 
	cout<<"��ѡ�������ʽ��0/1����"<<endl;
	cout<<"0�����һ���������\t1����������������"<<endl;
	cout<<"������0/1��"<<endl;
	cin>>m; 
	system("cls");
	//�����������������ѱ���������inputNum�У�������֤ 
	for(i=0;inputNum[i]!=0;i++)
	{
		n=inputNum[i];
		/***�Բ���Ҫ����������׳���������������������ʾ��Ϣ��ͬʱ����ֹ����*****/
		/*if(typeid(n)!=typeid(int))
		{
			cout<<n<<"����������������֤��°ͺղ���"<<endl;
			continue;
		} */
		if(n<=2)
		{
			cout<<n<<"С�ڵ���2��������֤��°ͺղ���"<<endl;
			continue;
		}
		if(n>MAX)
		{
			cout<<n<<"����"<<MAX<<"��������������֤��Χ"<<endl;
			continue; 
		}
		if(n%2==1)
		{
			cout<<n<<"��������������֤��°ͺղ���"<<endl;
			continue;
		}
		flag=false;//��ʼ��flag 
		int j,k;
		//prime[j]��prime[k]�ֱ��ǽ�С���ϴ������ 
		for(j=0;prime[j]<=int(n/2);j++)
		{
			for(k=j;prime[j]+prime[k]<n;k++);
			if(prime[j]+prime[k]==n)
			{
				flag=true;
				cout<<n<<'='<<prime[j]<<'+'<<prime[k]<<endl;
				if(m==0) break;//���һ��/������� 
			}
		}
		//�����ܡ����ֵĸ�°ͺղ���������� :) 
		if(!flag) cout<<"��֤����°ͺղ������\t������"<<n<<endl;
	}
	cout<<"Bye!"<<endl;
	system("pause");
	return 0;
}
