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

/**********定义结构体（线段）***********/
struct Shortline
{
	Point first_point;
	Point second_point;
};

//定义类（折线）
//将多边形看成是首尾节点相同的折线
class Polyline
{
	public:
		Polyline(Point *p_array=point_list,int nPoint = 0);//初始化缺省值 
		Point* get_point_array(); //获得折线的节点数组 
		bool isPolygon();//判断“折线”是否为多边形 
		bool isConvex();//判断多边形的凹凸性 
		int pointInPolygon(Point p);//0 is in, 1 is on, 2 is out
		void print_point_array();//打印出折线的节点坐标信息 
		float get_polygonarea();//计算多边形面积 
		void outer_polygon_info();//输出多边形外包矩形的信息 
	private:
		Point *point_array;
		int numPoint;
};

//初始化“折线”函数 
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
	//计算多边形每个内角 
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
			return false;//只要存在大于PI的内角，即为凹多边形 
	}
	return true;//内角都小于PI，为凸多边形 
}


//“射线法”判断点是否在多边形内
//返回值：0代表在多边形内，1代表在多边形上，2代表在多边形外 
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

//输出折线节点坐标信息 
void Polyline::print_point_array()
{
	for(int i=0;i<numPoint-1;i++)
		cout<<point_array[i].x<<' '<<point_array[i].y<<endl;
	//如果是多边形（首尾节点重合），仅输出首节点，不输出尾节点 
	if(!this->isPolygon())
		cout<<point_array[numPoint-1].x<<' '<<point_array[numPoint-1].y<<endl; 
}

//求多边形面积
//多边形可划分为小三角形
//每个小三角形均可以下列公式求解
//进而可求多边形面积 
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


//输出多边形外包矩形信息 
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
