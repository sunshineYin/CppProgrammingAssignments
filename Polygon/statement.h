/*
* File: statement.h

* Author: yinganmin6837@163.com(Ganmin Yin)

* Time: 2018/05/15

* Information:
*** The declaration of structure(Point, Shortline), 
*** and the class(Polyline) used in main.cpp.

*/

#ifndef POLYGON_STATEMENT_H
#define POLYGON_STATEMENT_H

#include<iostream>
#include<math.h>
#include "statement.h"

using namespace std;

#define PI 3.1415926
extern const int MAX_POINT_NUM;

//Point point_list[MAX_POINT_NUM] = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};


struct Point
{
	float x;
	float y;
};

//Point point_list[MAX_POINT_NUM] = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};

extern Point point_list[10];//10 is MAX_POINT_NUM

/**********����ṹ�壨�߶Σ�***********/
struct Shortline
{
	Point first_point;
	Point second_point;
};

//�����ࣨ���ߣ�
//������ο�������β�ڵ���ͬ������
class Polyline
{
	public:
		Polyline(Point *p_array=point_list,int nPoint = 0);//��ʼ��ȱʡֵ 
		Point* get_point_array(); //������ߵĽڵ����� 
		bool isPolygon();//�жϡ����ߡ��Ƿ�Ϊ����� 
		bool isConvex();//�ж϶���εİ�͹�� 
		int pointInPolygon(Point p);//0 is in, 1 is on, 2 is out
		void print_point_array();//��ӡ�����ߵĽڵ�������Ϣ 
		float get_polygonarea();//����������� 
		void outer_polygon_info();//��������������ε���Ϣ 
	private:
		Point *point_array;
		int numPoint;
};

//��ʼ�������ߡ����� 
Polyline::Polyline(Point p_array[],int nPoint)
{
	point_array = p_array;
	numPoint = nPoint;
}
 
Point *Polyline::get_point_array()
{
	return point_array;
}

bool Polyline::isPolygon()
{
	return(point_array[0].x==point_array[numPoint-1].x&&point_array[0].y==point_array[numPoint-1].y);
}

bool Polyline::isConvex()
{
	Point p1,p2,p3;
	//��������ÿ���ڽ� 
	for(int i=0;i<numPoint;i++)
	{
		p1 = point_array[i];
		p2 = point_array[(i+1)%numPoint];
		p3 = point_array[(i+2)%numPoint];
		float x1,y1,x2,y2,l1,l2;
		x1 = p1.x-p2.x; y1 = p1.y-p2.y;
		x2 = p3.x-p2.x; y2 = p3.y-p2.y;
		l1 = sqrt(pow(x1,2)+pow(y1,2));
		l2 = sqrt(pow(x2,2)+pow(y2,2));
		float angle = acos((x1*x2+y1*y2)/(l1*l2));
		if(angle>PI)
			return false;//ֻҪ���ڴ���PI���ڽǣ���Ϊ������� 
	}
	return true;//�ڽǶ�С��PI��Ϊ͹����� 
}


//�����߷����жϵ��Ƿ��ڶ������
//����ֵ��0�����ڶ�����ڣ�1�����ڶ�����ϣ�2�����ڶ������ 
int Polyline::pointInPolygon(Point p)
{ 
	bool flag=0;
	for(int i=0,j=numPoint-1;i<numPoint;j=i,i++)
	{
		float sx = point_array[i].x;
		float sy = point_array[i].y;
		float tx = point_array[j].x;
		float ty = point_array[j].y;
		if((sx==p.x&&sy==p.y)||tx==p.x&&ty==p.y)
			return 1;
		if((sy<p.y&&ty>=p.y)||(sy>=p.y&&ty<p.y))
		{
			float x = sx+(p.y-sy)*(tx-sx)/(ty-sy);
			if(x==p.x)
				return 1;
			if(x>p.x)
				flag = !flag;
		}
	}
	return(flag?0:2);
}

//������߽ڵ�������Ϣ 
void Polyline::print_point_array()
{
	for(int i=0;i<numPoint-1;i++)
		cout<<point_array[i].x<<' '<<point_array[i].y<<endl;
	//����Ƕ���Σ���β�ڵ��غϣ���������׽ڵ㣬�����β�ڵ� 
	if(!this->isPolygon())
		cout<<point_array[numPoint-1].x<<' '<<point_array[numPoint-1].y<<endl; 
}

//���������
//����οɻ���ΪС������
//ÿ��С�����ξ��������й�ʽ���
//��������������� 
float Polyline::get_polygonarea()
{
	int i,j;
	float area = 0.0;
	for(i=0;i<numPoint;i++)
	{
		j = (i+1)%numPoint;
		area += point_array[i].x*point_array[j].y;
		area -= point_array[i].y*point_array[j].x;
	}
	area /= 2;
	return (area<0?-area:area);
}


//�����������������Ϣ 
void Polyline::outer_polygon_info()
{
	float xmin = point_array[0].x;
	float xmax = point_array[0].x;
	float ymin = point_array[0].y;
	float ymax = point_array[0].y;
	for(int i=1;i<numPoint;i++)
	{
		if(point_array[i].x <= xmin)
			xmin = point_array[i].x;
		if(point_array[i].x >= xmax)
			xmax = point_array[i].x;
		if(point_array[i].y <= ymin)
			ymin = point_array[i].y;
		if(point_array[i].y >= ymax)
			ymax = point_array[i].y;
	}
	cout<<"xmin = "<<xmin<<endl;
	cout<<"xmax = "<<xmax<<endl;
	cout<<"ymin = "<<ymin<<endl;
	cout<<"ymax = "<<ymax<<endl;
}
#endif //POLYGON_STATEMENT_H
