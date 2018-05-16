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
	cout<<"\n\n\t\t*凸多边形检索问题";
	cout<<"\n\n\t\t*作者：尹赣闽（1600012436）";
	cout<<"\n\n\t\t*时间：2018/05/15";
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
	//从文件“input.txt”输入的线段数目 
	int sl_num = 0;
	while(!feof(pFile))
	{
		fscanf(pFile,"%f %f\t%f %f",&sl_array[i].first_point.x,&sl_array[i].first_point.y,&sl_array[i].second_point.x,&sl_array[i].second_point.y);
		i++;
		sl_num++;
	}
	//节点数组 
	Point point_array[MAX_POINT_NUM];
	for(int i=0;i<MAX_POINT_NUM;i++)
		point_array[i] = {0,0};//初始化 
	Point current_point;//定义当前节点 
	bool used_or_not[sl_num];//表示对于每一条折线，文件输入的各条线段是否在该折线上 
	//对于每一条折线，均有一个used_or_not，这里用sl_used_array(“二维数组”)存储 
	bool **sl_used_array = new bool*[MAX_PG_NUM];
	memset(used_or_not,0,sizeof(used_or_not));//初始化 
	int n=0;//n代表获得的满足一定条件的折线条数（实际上是多边形的个数）
	//每条折线均有起始线段
	//这重循环是针对起始线段而言的，起始线段是第1、2,...，sl_num条
	for(int i=0;i<sl_num;i++)
	{
		int j = 0;
		//对起始线段，起始点有两种可能，first_point or second_point
		
		//第一种可能：first_point 
		
		point_array[0] = sl_array[i].first_point;//折线的节点数组的第一项 
		point_array[1] = sl_array[i].second_point;//折线的节点数组的第二项 
		used_or_not[i] = 1;//起始线段已被使用 
		current_point = point_array[1];//当前节点为节点数组的第二项
		bool flag=1;
		//nLine是指折线的线段条数 
		int nLine=1;//nLine = len(point_array)-1
		//对于每一条折线，求出它的所有顶点 
		while(flag)
		{
			//求每一个顶点时，都需要循环查找 
			for(j=0;j<sl_num;j++)
			{
				//第i条线段已在折线中，跳过 
				if(j==i)
					continue;
				//第j条线段已在折线中（已被使用），跳过 
				if(used_or_not[j])
					continue;
				//找到某条线段的first_point与current_point（当前节点重合） 
				if((sl_array[j].first_point.x == current_point.x)&&(sl_array[j].first_point.y == current_point.y))
				{
					nLine++;//线段条数+1 
					current_point = sl_array[j].second_point;//当前节点变为该线段的另一顶点（second_point） 
					point_array[nLine] = sl_array[j].second_point;//将该线段的另一顶点（second_point）写入point_array中 
					used_or_not[j] = 1;//该线段已被使用（已在折线中） 
					break;//跳出for循环（因为一个顶点最多出现在两条线段中） 
				}
				//上面情况的另一种情况，first_point、second_point对调 
				if((sl_array[j].second_point.x == current_point.x)&&(sl_array[j].second_point.y == current_point.y))
				{
					nLine++;
					current_point = sl_array[j].first_point;
					point_array[nLine] = sl_array[j].first_point;
					used_or_not[j] = 1;
					break;
				}
			}
			//当遍历所有线段，都不能找到下一节点时，终止循环，找出一条折线 
			if(j == sl_num)
				flag = 0;
		}
		flag = 1;
		//找出的第一条折线 
		if(n==0)
			*sl_used_array[n] = *used_or_not;
		//折线边数不小于3，且经判断为多边形 
		if((nLine>=3)&&Polyline(point_array,nLine+1).isPolygon())
		{
			//判断该多边形是否已在多边形数组（pg_array）内 
			for(int i=0;i<n;i++)
			{
				if(memcmp(used_or_not,sl_used_array[i],sizeof(bool)*sl_num))
					flag = 0;
			}
			//该多边形不在pg_array内，说明第一次得到 
			//第一次得到，该多边形的各线段的使用情况(即哪些线段在该多边形上，哪些不在)，存入sl_used_array中，用于后续判断多边形是否已存入pg_array中 
			//第一次得到，存入pg_array中 
			if(flag)
			{
				*sl_used_array[n] = *used_or_not;	
				pg_array[n] = Polyline(point_array,nLine+1);
				n++; 
			}
		}
		
		//第二种可能：second_point(与第一种可能过程相近)
		
		//重新初始化 
		memset(used_or_not,0,sizeof(used_or_not));
		for(int i=0;i<MAX_POINT_NUM;i++)
			point_array[i] = {0,0};
		point_array[0] = sl_array[i].second_point;
		point_array[1] = sl_array[i].first_point;
		used_or_not[i] = 1;
		current_point = point_array[1];
		flag = 1;
		nLine=1;//nLine = len(point_array)-1
		//对于每一条折线，求出它的所有顶点 
		while(flag)
		{
			//求每一个顶点时，都需要循环查找 
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
	//检查pg_array中是否含有凸多边形 
	while(i<n&&!pg_array[i].isConvex())
		i++;
	//有凸多边形 
	if(i!=n)
	{
		//cout<<"===================="<<endl;
		cout<<"存在凸多边形"<<endl;
		cout<<"请输入需判断的点坐标："<<endl;
		scanf("%f %f",&x,&y);
		int m = pg_array[i].pointInPolygon({x,y});
		switch(m)
		{
			case 0:cout<<"点"<<x<<","<<y<<"在该凸多边形内"<<endl;break;
			case 1:cout<<"点"<<x<<","<<y<<"在该凸多边形上"<<endl;break;
			case 2:cout<<"点"<<x<<","<<y<<"在该凸多边形外"<<endl;break; 
		}
		cout<<"===================="<<endl;
		cout<<"坐标点序列："<<endl;
		pg_array[i].print_point_array();
		cout<<"面积："<<pg_array[i].get_polygonarea()<<endl;
		cout<<"外包矩形："<<endl;
		pg_array[i].outer_polygon_info();
		cout<<"===================="<<endl;
	}
	//无凸多边形 
	if(i==n)
	{
		cout<<"不存在凸多边形"<<endl;
	}
	fclose(pFile);
	pFile = NULL;
	delete[] sl_used_array;
	return 0;
}
