// File: main.cpp
// Author: yinganmin6837@163.com(Ganmin Yin)
// Date: 2018/05/31
// Description:
//    The entrance of the project.
//    For the input commands, we handle them seperately based on the judgement statement.


#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include "point.h"
#include "polyline.h"
#include "ring.h"
#include "polygon.h"
#include "str_split.h"

using namespace std;


int main()
{
	//定义4个容器，分别存储用户输入的Point、Polyline、Ring、Polygon对象 
	vector<class Point> point_array;
	vector<class Polyline> polyline_array;
	vector<class Ring> ring_array;
	vector<class Polygon> polygon_array;
	
	ifstream fin;
	fin.open("input.txt");
	if(!fin)
	{
		cout<<"File open error!"<<endl;
		system("pause");
	}
	
	ofstream fout;
	
	//s用于存储输入文件流ifstream（fin）按行读入的整行信息 
	string s;
	//str_array用于存储字符串s按空格分割后得到的一系列字符串 
	vector<string> str_array; 
	string space_delim = " ";//空格分隔符 
	string comma_delim = ",";//逗号分隔符，主要是对Polyline、Ring、Polygon输入数据时起分割作用 
	double x,y;//存储坐标信息 
	
	while(getline(fin,s))
	{
		
		str_array = str_split(s,space_delim);
		
		//分割字符串后，发现是对point做操作 
		if(str_array[1]=="point")
		{
			//迭代器pt，用于遍历point_array，以查找命令语句操作的确切point对象 
			vector<Point>::iterator pt;//pt is point
			
			//“add point”操作 
			if(str_array[0]=="add")
			{
				//字符串转double，获得点坐标 
				x = atof(str_split(str_array[3],comma_delim)[0].c_str());
				y = atof(str_split(str_array[3],comma_delim)[1].c_str());
				//将add的point存入point_array中 
				point_array.push_back(Point(str_array[2],x,y));
			}
			
			//“del point”操作 
			if(str_array[0]=="del")
			{
				//迭代器pt查找要删除的点 
				for(pt=point_array.begin();pt<point_array.end();pt++)
				{
					//查找到该点 
					if((*pt).get_id() == str_array[2])
					{
						point_array.erase(pt);//在point_array中将该点删除 
						break;
					}
				}
			}
			
			//“set point”操作 
			if(str_array[0]=="set")
			{
				//“set point set”操作 
				if(str_array[3]=="set")
				{
					//字符串转double，获得点坐标 
					x = atof(str_split(str_array[4],comma_delim)[0].c_str());
					y = atof(str_split(str_array[4],comma_delim)[1].c_str());
					
					//查找待操作点 
					for(pt=point_array.begin();pt<point_array.end();pt++)
					{
						if((*pt).get_id() == str_array[2])
							break;
					}
					
					(*pt).set_set(x,y);
				}
				
				//“set point move”操作 
				if(str_array[3]=="move")
				{
					//字符串转double，获得点坐标 
					x = atof(str_split(str_array[4],comma_delim)[0].c_str());
					y = atof(str_split(str_array[4],comma_delim)[1].c_str());
					
					for(pt=point_array.begin();pt<point_array.end();pt++)
					{
						if((*pt).get_id() == str_array[2])
							break;
					}
					
					(*pt).set_move(x,y);
				}
				
				//“set point name”操作 
				if(str_array[3]=="name")
				{
					for(pt=point_array.begin();pt<point_array.end();pt++)
					{
						if((*pt).get_id() == str_array[2])
							break;
					}
					
					(*pt).set_name(str_array[4]);
				}
			}
			
			//“judge”操作 
			if(str_array[0]=="judge")
			{
				string flag;//用于将判断结果写入文件 
				Point a1,a2;
				
				//遍历查找待判断的两点 
				for(pt=point_array.begin();pt<point_array.end();pt++)
				{
					if((*pt).get_id() == str_array[2])
						a1 = *pt;
					if((*pt).get_id() == str_array[4])
						a2 = *pt;
				}
				
				flag = a1.judge(a2)?"True":"False";
				
				//将判断结果写入文件 
				fout.open("output.txt",ios_base::app);
				if(!fout)
				{
					cout<<"File open error!"<<endl;
					system("pause");
				}
				fout<<flag<<endl;
				fout.close();
			}
		}
		
		
		//容器points用于存储创建Polyline、Ring、Polygon对象时，需用到的点列表 
		vector<Point> points;
		
		//对polyline做操作 
		if(str_array[1]=="polyline")
		{
			//迭代器pl用于遍历polyline_array，以查找待操作的polyline对象 
			vector<class Polyline>::iterator pl;
			
			//“add polyline”操作 
			if(str_array[0]=="add")
			{
				//num_vector用于存储输入点的坐标 
				vector<string> num_vector = str_split(str_array[3],comma_delim);
				
				//根据num_vector获得点列表 
				for(int i=0;i<num_vector.size();i++)
				{
					//字符串转double，获得点坐标 
					x = atof(num_vector[i].c_str());
					y = atof(num_vector[++i].c_str());
					points.push_back(Point(x,y));
				}
				//获得新polyline对象 
				Polyline new_polyline(str_array[2],points);
				// 存入polyline_array中 
				polyline_array.push_back(new_polyline);
			}
			
			//“del polyline”操作 
			if(str_array[0]=="del")
			{
				for(pl=polyline_array.begin();pl<polyline_array.end();pl++)
				{
					if((*pl).get_id() == str_array[2])
					{
						//从polyline_array中删去该polyline对象 
						polyline_array.erase(pl);
						break;
					}
				}
			}
			
			//“set polyline”操作 
			if(str_array[0]=="set")
			{
				//“set polyline set”操作 
				if(str_array[3]=="set")
				{
					for(pl=polyline_array.begin();pl<polyline_array.end();pl++)
					{
						//字符串转double 
						x = atof(str_split(str_array[5],comma_delim)[0].c_str());
						y = atof(str_split(str_array[5],comma_delim)[1].c_str());
						
						if((*pl).get_id() == str_array[2])
						{
							//“set polyline set”操作 
							(*pl).set_set(*(str_array[4].c_str())-'0',x,y);
							break;
						}
					}
				}
				
				//“set polyline move”操作 
				if(str_array[3]=="move")
				{
					for(pl=polyline_array.begin();pl<polyline_array.end();pl++)
					{
						//字符串转double 
						x = atof(str_split(str_array[5],comma_delim)[0].c_str());
						y = atof(str_split(str_array[5],comma_delim)[1].c_str());
						
						if((*pl).get_id() == str_array[2])
						{
							(*pl).set_move(*(str_array[4].c_str())-'0',x,y);
							break;
						}
					}
				}
				
				//“set polyline del”操作 
				if(str_array[3]=="del")
				{
					for(pl=polyline_array.begin();pl<polyline_array.end();pl++)
					{
						if((*pl).get_id() == str_array[2])
						{
							(*pl).set_del(*(str_array[4].c_str())-'0');
							break;
						}
					}
				}
				
				//“set polyline set_length”操作 
				if(str_array[3]=="set_length")
				{
					for(pl=polyline_array.begin();pl<polyline_array.end();pl++)
					{
						if((*pl).get_id() == str_array[2])
						{
							(*pl).set_set_length(str_array[4]);
							break;
						}
					}
				}
				
				//“set polyline name”操作 
				if(str_array[3]=="name")
				{
					for(pl=polyline_array.begin();pl<polyline_array.end();pl++)
					{
						if((*pl).get_id() == str_array[2])
						{
							(*pl).set_name(str_array[4]);
							break;
						}
					}
				}
			}
		}
		
		//清除points原有数据 
		points.clear();
		
		//对ring做操作 
		if(str_array[1]=="ring")
		{
			//迭代器rg 
			vector<Ring>::iterator rg;//rg is ring
			
			//“add ring”操作 
			if(str_array[0]=="add")
			{
				//num_vector存储输入点坐标 
				vector<string> num_vector = str_split(str_array[3],comma_delim);
				
				for(int i=0;i<num_vector.size();i++)
				{
					x = atof(num_vector[i].c_str());
					y = atof(num_vector[++i].c_str());
					points.push_back(Point(x,y));
				}
				
				//ring对象最后的点与起始点相同 
				x = atof(num_vector[0].c_str());
				y = atof(num_vector[1].c_str());
				points.push_back(Point(x,y));
				ring_array.push_back(Ring(str_array[2],points));
			}
			
			//“del ring”操作 
			if(str_array[0]=="del")
			{
				for(rg=ring_array.begin();rg<ring_array.end();rg++)
				{
					if((*rg).get_id() == str_array[2])
					{
						ring_array.erase(rg);
						break;
					}
				}
			}
			
			//“set ring”操作 
			if(str_array[0]=="set")
			{
				//“set ring set”操作 
				if(str_array[3]=="set")
				{
					for(rg=ring_array.begin();rg<ring_array.end();rg++)
					{
						x = atof(str_split(str_array[5],comma_delim)[0].c_str());
						y = atof(str_split(str_array[5],comma_delim)[1].c_str());
						
						if((*rg).get_id() == str_array[2])
						{
							(*rg).set_set(*(str_array[4].c_str())-'0',x,y);
							break;
						}
					}
				}
				
				//“set ring move”操作 
				if(str_array[3]=="move")
				{
					for(rg=ring_array.begin();rg<ring_array.end();rg++)
					{
						x = atof(str_split(str_array[5],comma_delim)[0].c_str());
						y = atof(str_split(str_array[5],comma_delim)[1].c_str());
						
						if((*rg).get_id() == str_array[2])
						{
							(*rg).set_move(*(str_array[4].c_str())-'0',x,y);
							break;
						}
					}
				}
				
				//“set ring del”操作 
				if(str_array[3]=="del")
				{
					for(rg=ring_array.begin();rg<ring_array.end();rg++)
					{
						if((*rg).get_id() == str_array[2])
						{
							(*rg).set_del(*(str_array[4].c_str())-'0');
							break;
						}
					}
				}
				
				//“set ring set_length”操作 
				if(str_array[3]=="set_length")
				{
					for(rg=ring_array.begin();rg<ring_array.end();rg++)
					{
						if((*rg).get_id() == str_array[2])
						{
							(*rg).set_set_length(str_array[4]);
							break;
						}
					}
				}
				
				//“set ring set_area”操作 
				if(str_array[3]=="set_area")
				{
					for(rg=ring_array.begin();rg<ring_array.end();rg++)
					{
						if((*rg).get_id() == str_array[2])
						{
							(*rg).set_set_area(str_array[4]);
							break;
						}
					}
				}
				
				//“set ring name”操作 
				if(str_array[3]=="name")
				{
					for(rg=ring_array.begin();rg<ring_array.end();rg++)
					{
						if((*rg).get_id() == str_array[2])
						{
							(*rg).set_name(str_array[4]);
							break;
						}
					}
				}
			}
			
			//“judge”操作 
			if(str_array[0]=="judge")
			{
				string flag;
				
				//找到待判断点 
				vector<class Point>::iterator p1;
				for(p1=point_array.begin();p1<point_array.end();p1++)
				{
					if((*p1).get_id() == str_array[4])
						break;
				}
				
				//找到待操作ring 
				for(rg=ring_array.begin();rg<ring_array.end();rg++)
				{
					if((*rg).get_id() == str_array[2])
						break;
				}
				
				//将判断结果写入文件 
				flag = ((*rg).judge(*p1))?"True":"False";
				fout.open("output.txt",ios_base::app);
				if(!fout)
				{
					cout<<"File open error!"<<endl;
					system("pause");
				}
				fout<<flag<<endl;
				fout.close();
			}
		}
		
		//清除points原有数据 
		points.clear();
		
		//对polygon做操作 
		if(str_array[1]=="polygon")
		{
			//迭代器pg 
			vector<class Polygon>::iterator pg;//pg is polygon
			
			//“add polygon”操作 
			if(str_array[0]=="add")
			{
				
				vector<string> num_vector = str_split(str_array[4],comma_delim);
				
				for(int i=0;i<num_vector.size();i++)
				{
					x = atof(num_vector[i].c_str());
					y = atof(num_vector[++i].c_str());
					points.push_back(Point(x,y));
				}
				
				//polygon末尾点与起始点相同 
				x = atof(num_vector[0].c_str());
				y = atof(num_vector[1].c_str());
				
				//获得新polygon对象 
				points.push_back(Point(x,y));
				Ring outer_ring(str_array[3],points);
				Polygon new_polygon(str_array[2],outer_ring);
				
				//存入polygon_array中 
				polygon_array.push_back(new_polygon);
			}
			
			//“del polygon”操作 
			if(str_array[0]=="del")
			{
				for(pg=polygon_array.begin();pg<polygon_array.end();pg++)
				{
					if((*pg).get_id() == str_array[2])
					{
						//从polygon_array中删去待操作polygon 
						polygon_array.erase(pg);
						break;
					}
				}
			}
			
			//“set polygon”操作 
			if(str_array[0]=="set")
			{
				//“set polygon inner”操作 
				if(str_array[3]=="inner")
				{
					//points清除原数据 
					points.clear();
					
					for(pg=polygon_array.begin();pg<polygon_array.end();pg++)
					{
						if((*pg).get_id() == str_array[2])
						{
							vector<string> num_vector = str_split(str_array[4],comma_delim);
							
							for(int i=0;i<num_vector.size();i++)
							{
								x = atof(num_vector[i].c_str());
								y = atof(num_vector[++i].c_str());
								points.push_back(Point(x,y));
							}
							
							//inner ring最后点与起始点相同 
							x = atof(num_vector[0].c_str());
							y = atof(num_vector[1].c_str());
							
							points.push_back(Point(x,y));
							Ring inner_ring(str_array[3],points);
							(*pg).set_inner(inner_ring);
							break;
						}
					}
				}
				
				//“set polygon set”操作 
				if(str_array[3]=="set")
				{
					//“set polygon set outer”操作 
					if(str_array[4]=="outer")
					{
						for(pg=polygon_array.begin();pg<polygon_array.end();pg++)
						{
							x = atof(str_split(str_array[6],comma_delim)[0].c_str());
							y = atof(str_split(str_array[6],comma_delim)[1].c_str());
							if((*pg).get_id() == str_array[2])
							{
								(*pg).set_set_outer(*(str_array[5].c_str())-'0',x,y);
								break;
							}
						}
					}
					
					//“set polygon set inner”操作 
					if(str_array[4]=="inner")
					{
						for(pg=polygon_array.begin();pg<polygon_array.end();pg++)
						{
							x = atof(str_split(str_array[6],comma_delim)[0].c_str());
							y = atof(str_split(str_array[6],comma_delim)[1].c_str());
							if((*pg).get_id() == str_array[2])
							{
								(*pg).set_set_inner(*(str_array[5].c_str())-'0',x,y);
								break;
							}
						}
					}
				}
				
				//“set polygon move”操作 
				if(str_array[3]=="move")
				{
					//“set polygon move outer”操作 
					if(str_array[4]=="outer")
					{
						for(pg=polygon_array.begin();pg<polygon_array.end();pg++)
						{	
							x = atof(str_split(str_array[6],comma_delim)[0].c_str());
							y = atof(str_split(str_array[6],comma_delim)[1].c_str());
							if((*pg).get_id() == str_array[2])
							{
								(*pg).set_move_outer(*(str_array[5].c_str())-'0',x,y);
								break;
							}
						}
					}
					
					//“set polygon move inner”操作 
					if(str_array[4]=="inner")
					{
						for(pg=polygon_array.begin();pg<polygon_array.end();pg++)
						{	
							x = atof(str_split(str_array[6],comma_delim)[0].c_str());
							y = atof(str_split(str_array[6],comma_delim)[1].c_str());
							if((*pg).get_id() == str_array[2])
							{
								(*pg).set_move_inner(*(str_array[5].c_str())-'0',x,y);
								break;
							}
						}
					}
				}
				
				//“set polygon del”操作 
				if(str_array[3]=="del")
				{
					//“set polygon del outer”操作 
					if(str_array[4]=="outer")
					{
						for(pg=polygon_array.begin();pg<polygon_array.end();pg++)
						{
							if((*pg).get_id() == str_array[2])
							{
								(*pg).set_del_outer(*(str_array[5].c_str())-'0');
								break;
							}
						}
					}
					
					//“set polygon del inner”操作 
					if(str_array[4]=="inner")
					{
						for(pg=polygon_array.begin();pg<polygon_array.end();pg++)
						{
							if((*pg).get_id() == str_array[2])
							{
								(*pg).set_del_inner(*(str_array[5].c_str())-'0');
								break;
							}
						}
					}
				}
				
				//“set polygon set_length”操作 
				if(str_array[3]=="set_length")
				{
					for(pg=polygon_array.begin();pg<polygon_array.end();pg++)
					{
						if((*pg).get_id() == str_array[2])
						{
							(*pg).set_set_length(str_array[4]);
							break;
						}
					}
				}
				
				//“set polygon set_area”操作 
				if(str_array[3]=="set_area")
				{
					for(pg=polygon_array.begin();pg<polygon_array.end();pg++)
					{
						if((*pg).get_id() == str_array[2])
						{
							(*pg).set_set_area(str_array[4]);
							break;
						}
					}
				}
				
				//“set polygon name”操作 
				if(str_array[3]=="name")
				{
					for(pg=polygon_array.begin();pg<polygon_array.end();pg++)
					{
						if((*pg).get_id() == str_array[2])
						{
							(*pg).set_name(str_array[4]);
							break;
						}
					}
				}
			}
			
			//judge操作 
			if(str_array[0]=="judge")
			{
				string flag;
				
				//找到待判断点 
				vector<Point>::iterator p1;
				for(p1=point_array.begin();p1<point_array.end();p1++)
				{
					if((*p1).get_id() == str_array[4])
						break;
				}
				
				//找到待判断polygon 
				for(pg=polygon_array.begin();pg<polygon_array.end();pg++)
				{
					if((*pg).get_id() == str_array[2])
						break;
				}
				
				flag = ((*pg).judge(*p1))?"True":"False";
				fout.open("output.txt",ios_base::app);
				if(!fout)
				{
					cout<<"File open error!"<<endl;
					system("pause");
				}
				fout<<flag<<endl;
				fout.close();
			}
		}
	}
	
	fin.close();
	
	//输出各个类对象的信息 
	for(vector<class Point>::iterator p=point_array.begin();p<point_array.end();p++)
		(*p).printout();	
	for(vector<class Polyline>::iterator p=polyline_array.begin();p<polyline_array.end();p++)
		(*p).printout();
	for(vector<class Ring>::iterator p=ring_array.begin();p<ring_array.end();p++)
		(*p).printout();
	for(vector<class Polygon>::iterator p=polygon_array.begin();p<polygon_array.end();p++)
		(*p).printout();
	
	fout.close();
	
	return 0;
}
