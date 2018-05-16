/*
* File: main.cpp

* Author: yinganmin6837@163.com(Ganmin Yin)

* Time: 2018/05/15

* Information:
*** This source file is mainly used to determine whether the line segments 
*** input by the file "input.txt" can form a convex polygon.
*** And it also prints out some information 
*** such as the sequence of the points's coordinates, 
*** the area and the outer rectangle of the polygon.

*/

#include<iostream>
#include<string.h>
#include<math.h>
#include "statement.h" 

using namespace std;

const int MAX_POINT_NUM = 10; 
const int MAX_SL_NUM = 10;//SL is "shortline" 
const int MAX_PG_NUM = 20;//PG is "polygon"
#define PI 3.1415926

Point point_list[MAX_POINT_NUM] = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};

/**************the basic information of this project*************/
void title()
{
	cout<<"\n\t\t=======================";
	cout<<"\n\n\t\t*͹����μ�������";
	cout<<"\n\n\t\t*���ߣ���������1600012436��";
	cout<<"\n\n\t\t*ʱ�䣺2018/05/15";
	cout<<"\n\n\t\t=======================";
	cout<<"\n";
	system("pause"); 
}

int main()
{
	title();
	system("cls"); 
	//sl is "shortline"
	Shortline sl_array[MAX_SL_NUM];
	//pg is "polygon" 
	Polyline pg_array[MAX_PG_NUM];
	FILE *pFile;
	pFile = fopen("input.txt","r");
	if(pFile == NULL)
	{
		cout<<"File open error!"<<endl;
		system("pause");
		return 0;
	}
	int i=0;
	//���ļ���input.txt��������߶���Ŀ 
	int sl_num = 0;
	while(!feof(pFile))
	{
		fscanf(pFile,"%f %f\t%f %f",&sl_array[i].first_point.x,&sl_array[i].first_point.y,&sl_array[i].second_point.x,&sl_array[i].second_point.y);
		i++;
		sl_num++;
	}
	//�ڵ����� 
	Point point_array[MAX_POINT_NUM];
	for(int i=0;i<MAX_POINT_NUM;i++)
		point_array[i] = {0,0};//��ʼ�� 
	Point current_point;//���嵱ǰ�ڵ� 
	bool used_or_not[sl_num];//��ʾ����ÿһ�����ߣ��ļ�����ĸ����߶��Ƿ��ڸ������� 
	//����ÿһ�����ߣ�����һ��used_or_not��������sl_used_array(����ά���顱)�洢 
	bool **sl_used_array = new bool*[MAX_PG_NUM];
	memset(used_or_not,0,sizeof(used_or_not));//��ʼ�� 
	int n=0;//n�����õ�����һ������������������ʵ�����Ƕ���εĸ�����
	//ÿ�����߾�����ʼ�߶�
	//����ѭ���������ʼ�߶ζ��Եģ���ʼ�߶��ǵ�1��2,...��sl_num��
	for(int i=0;i<sl_num;i++)
	{
		int j = 0;
		//����ʼ�߶Σ���ʼ�������ֿ��ܣ�first_point or second_point
		
		//��һ�ֿ��ܣ�first_point 
		
		point_array[0] = sl_array[i].first_point;//���ߵĽڵ�����ĵ�һ�� 
		point_array[1] = sl_array[i].second_point;//���ߵĽڵ�����ĵڶ��� 
		used_or_not[i] = 1;//��ʼ�߶��ѱ�ʹ�� 
		current_point = point_array[1];//��ǰ�ڵ�Ϊ�ڵ�����ĵڶ���
		bool flag=1;
		//nLine��ָ���ߵ��߶����� 
		int nLine=1;//nLine = len(point_array)-1
		//����ÿһ�����ߣ�����������ж��� 
		while(flag)
		{
			//��ÿһ������ʱ������Ҫѭ������ 
			for(j=0;j<sl_num;j++)
			{
				//��i���߶����������У����� 
				if(j==i)
					continue;
				//��j���߶����������У��ѱ�ʹ�ã������� 
				if(used_or_not[j])
					continue;
				//�ҵ�ĳ���߶ε�first_point��current_point����ǰ�ڵ��غϣ� 
				if((sl_array[j].first_point.x == current_point.x)&&(sl_array[j].first_point.y == current_point.y))
				{
					nLine++;//�߶�����+1 
					current_point = sl_array[j].second_point;//��ǰ�ڵ��Ϊ���߶ε���һ���㣨second_point�� 
					point_array[nLine] = sl_array[j].second_point;//�����߶ε���һ���㣨second_point��д��point_array�� 
					used_or_not[j] = 1;//���߶��ѱ�ʹ�ã����������У� 
					break;//����forѭ������Ϊһ�������������������߶��У� 
				}
				//�����������һ�������first_point��second_point�Ե� 
				if((sl_array[j].second_point.x == current_point.x)&&(sl_array[j].second_point.y == current_point.y))
				{
					nLine++;
					current_point = sl_array[j].first_point;
					point_array[nLine] = sl_array[j].first_point;
					used_or_not[j] = 1;
					break;
				}
			}
			//�����������߶Σ��������ҵ���һ�ڵ�ʱ����ֹѭ�����ҳ�һ������ 
			if(j == sl_num)
				flag = 0;
		}
		flag = 1;
		//�ҳ��ĵ�һ������ 
		if(n==0)
			*sl_used_array[n] = *used_or_not;
		//���߱�����С��3���Ҿ��ж�Ϊ����� 
		if((nLine>=3)&&Polyline(point_array,nLine+1).isPolygon())
		{
			//�жϸö�����Ƿ����ڶ�������飨pg_array���� 
			for(int i=0;i<n;i++)
			{
				if(memcmp(used_or_not,sl_used_array[i],sizeof(bool)*sl_num))
					flag = 0;
			}
			//�ö���β���pg_array�ڣ�˵����һ�εõ� 
			//��һ�εõ����ö���εĸ��߶ε�ʹ�����(����Щ�߶��ڸö�����ϣ���Щ����)������sl_used_array�У����ں����ж϶�����Ƿ��Ѵ���pg_array�� 
			//��һ�εõ�������pg_array�� 
			if(flag)
			{
				*sl_used_array[n] = *used_or_not;	
				pg_array[n] = Polyline(point_array,nLine+1);
				n++; 
			}
		}
		
		//�ڶ��ֿ��ܣ�second_point(���һ�ֿ��ܹ������)
		
		//���³�ʼ�� 
		memset(used_or_not,0,sizeof(used_or_not));
		for(int i=0;i<MAX_POINT_NUM;i++)
			point_array[i] = {0,0};
		point_array[0] = sl_array[i].second_point;
		point_array[1] = sl_array[i].first_point;
		used_or_not[i] = 1;
		current_point = point_array[1];
		flag = 1;
		nLine=1;//nLine = len(point_array)-1
		//����ÿһ�����ߣ�����������ж��� 
		while(flag)
		{
			//��ÿһ������ʱ������Ҫѭ������ 
			for(j=0;j<sl_num;j++)
			{
				if(j==i)
					continue;
				if(used_or_not[j])
					continue;
				if((sl_array[j].first_point.x == current_point.x)&&(sl_array[j].first_point.y == current_point.y))
				{
					nLine++;
					current_point = sl_array[j].second_point;
					point_array[nLine] = sl_array[j].second_point;
					used_or_not[j] = 1;
					break;
				}
				if((sl_array[j].second_point.x == current_point.x)&&(sl_array[j].second_point.y == current_point.y))
				{
					nLine++;
					current_point = sl_array[j].first_point;
					point_array[nLine] = sl_array[j].first_point;
					used_or_not[j] = 1;
					break;
				}
			}
			if(j == sl_num)
				flag = 0;
		}
		flag = 1;
		if((nLine>=3)&&Polyline(point_array,nLine+1).isPolygon())
		{
			for(int i=0;i<n;i++)
			{
				if(memcmp(used_or_not,sl_used_array[i],sizeof(bool)*sl_num))
					flag = 0;
			}
			if(flag)
			{
				*sl_used_array[n] = *used_or_not;
				pg_array[n] = Polyline(point_array,nLine+1);
				n++; 
			}
		}
		
	}
	float x,y;
	i=0;
	//���pg_array���Ƿ���͹����� 
	while(i<n&&!pg_array[i].isConvex())
		i++;
	//��͹����� 
	if(i!=n)
	{
		//cout<<"===================="<<endl;
		cout<<"����͹�����"<<endl;
		cout<<"���������жϵĵ����꣺"<<endl;
		scanf("%f %f",&x,&y);
		int m = pg_array[i].pointInPolygon({x,y});
		switch(m)
		{
			case 0:cout<<"��"<<x<<","<<y<<"�ڸ�͹�������"<<endl;break;
			case 1:cout<<"��"<<x<<","<<y<<"�ڸ�͹�������"<<endl;break;
			case 2:cout<<"��"<<x<<","<<y<<"�ڸ�͹�������"<<endl;break; 
		}
		cout<<"===================="<<endl;
		cout<<"��������У�"<<endl;
		pg_array[i].print_point_array();
		cout<<"�����"<<pg_array[i].get_polygonarea()<<endl;
		cout<<"������Σ�"<<endl;
		pg_array[i].outer_polygon_info();
		cout<<"===================="<<endl;
	}
	//��͹����� 
	if(i==n)
	{
		cout<<"������͹�����"<<endl;
	}
	fclose(pFile);
	pFile = NULL;
	delete[] sl_used_array;
	return 0;
}
