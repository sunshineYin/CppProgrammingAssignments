#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "statement.h"

using namespace std;

/**************����������*****************/
double x,y;

int main()
{
	time_t t_start,t_end;
	t_start = time(NULL);//���㺯������ʱ�� 
	long Num = 50000000;//���ؿ���Ͷ����� 
	long Count = 0;
	srand((unsigned)time(NULL));//��ʱ��Ϊ��������� 
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
	pi = 4.0*Count/Num;//����PIֵ
	/**********�жϹ���ֵ��Чλ��**********/ 
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
	/*************���������Ϣ*************/ 
	cout<<"���ߣ���������1600012436��"<<"\t"<<"�ύʱ�䣺2018/03/16"<<endl;
	cout<<"�����Ŀ�����Ҫ������"<<endl;
	cout<<"����Ŀ�꣺����PIֵ"<<"\t"<<"��Ҫ���������ؿ��������"<<endl;
	cout<<"�������㣺�о�û��:)"<<endl;
	printf("���μ����õ�PIֵΪ��%.7f\n",pi);
	t_end = time(NULL);
	printf("���ι���ķѵ�ʱ��Ϊ��%f s\n",difftime(t_end,t_start));
	printf("PI����Чλ��Ϊ��%d",n-1);//ȥ��С���������һλ��ʵ����Чλ��Ϊn-1 
	system("pause");
	return 0;
 } 
