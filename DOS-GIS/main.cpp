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
	//����4���������ֱ�洢�û������Point��Polyline��Ring��Polygon���� 
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
	
	//s���ڴ洢�����ļ���ifstream��fin�����ж����������Ϣ 
	string s;
	//str_array���ڴ洢�ַ���s���ո�ָ��õ���һϵ���ַ��� 
	vector<string> str_array; 
	string space_delim = " ";//�ո�ָ��� 
	string comma_delim = ",";//���ŷָ�������Ҫ�Ƕ�Polyline��Ring��Polygon��������ʱ��ָ����� 
	double x,y;//�洢������Ϣ 
	
	while(getline(fin,s))
	{
		
		str_array = str_split(s,space_delim);
		
		//�ָ��ַ����󣬷����Ƕ�point������ 
		if(str_array[1]=="point")
		{
			//������pt�����ڱ���point_array���Բ���������������ȷ��point���� 
			vector<Point>::iterator pt;//pt is point
			
			//��add point������ 
			if(str_array[0]=="add")
			{
				//�ַ���תdouble����õ����� 
				x = atof(str_split(str_array[3],comma_delim)[0].c_str());
				y = atof(str_split(str_array[3],comma_delim)[1].c_str());
				//��add��point����point_array�� 
				point_array.push_back(Point(str_array[2],x,y));
			}
			
			//��del point������ 
			if(str_array[0]=="del")
			{
				//������pt����Ҫɾ���ĵ� 
				for(pt=point_array.begin();pt<point_array.end();pt++)
				{
					//���ҵ��õ� 
					if((*pt).get_id() == str_array[2])
					{
						point_array.erase(pt);//��point_array�н��õ�ɾ�� 
						break;
					}
				}
			}
			
			//��set point������ 
			if(str_array[0]=="set")
			{
				//��set point set������ 
				if(str_array[3]=="set")
				{
					//�ַ���תdouble����õ����� 
					x = atof(str_split(str_array[4],comma_delim)[0].c_str());
					y = atof(str_split(str_array[4],comma_delim)[1].c_str());
					
					//���Ҵ������� 
					for(pt=point_array.begin();pt<point_array.end();pt++)
					{
						if((*pt).get_id() == str_array[2])
							break;
					}
					
					(*pt).set_set(x,y);
				}
				
				//��set point move������ 
				if(str_array[3]=="move")
				{
					//�ַ���תdouble����õ����� 
					x = atof(str_split(str_array[4],comma_delim)[0].c_str());
					y = atof(str_split(str_array[4],comma_delim)[1].c_str());
					
					for(pt=point_array.begin();pt<point_array.end();pt++)
					{
						if((*pt).get_id() == str_array[2])
							break;
					}
					
					(*pt).set_move(x,y);
				}
				
				//��set point name������ 
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
			
			//��judge������ 
			if(str_array[0]=="judge")
			{
				string flag;//���ڽ��жϽ��д���ļ� 
				Point a1,a2;
				
				//�������Ҵ��жϵ����� 
				for(pt=point_array.begin();pt<point_array.end();pt++)
				{
					if((*pt).get_id() == str_array[2])
						a1 = *pt;
					if((*pt).get_id() == str_array[4])
						a2 = *pt;
				}
				
				flag = a1.judge(a2)?"True":"False";
				
				//���жϽ��д���ļ� 
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
		
		
		//����points���ڴ洢����Polyline��Ring��Polygon����ʱ�����õ��ĵ��б� 
		vector<Point> points;
		
		//��polyline������ 
		if(str_array[1]=="polyline")
		{
			//������pl���ڱ���polyline_array���Բ��Ҵ�������polyline���� 
			vector<class Polyline>::iterator pl;
			
			//��add polyline������ 
			if(str_array[0]=="add")
			{
				//num_vector���ڴ洢���������� 
				vector<string> num_vector = str_split(str_array[3],comma_delim);
				
				//����num_vector��õ��б� 
				for(int i=0;i<num_vector.size();i++)
				{
					//�ַ���תdouble����õ����� 
					x = atof(num_vector[i].c_str());
					y = atof(num_vector[++i].c_str());
					points.push_back(Point(x,y));
				}
				//�����polyline���� 
				Polyline new_polyline(str_array[2],points);
				// ����polyline_array�� 
				polyline_array.push_back(new_polyline);
			}
			
			//��del polyline������ 
			if(str_array[0]=="del")
			{
				for(pl=polyline_array.begin();pl<polyline_array.end();pl++)
				{
					if((*pl).get_id() == str_array[2])
					{
						//��polyline_array��ɾȥ��polyline���� 
						polyline_array.erase(pl);
						break;
					}
				}
			}
			
			//��set polyline������ 
			if(str_array[0]=="set")
			{
				//��set polyline set������ 
				if(str_array[3]=="set")
				{
					for(pl=polyline_array.begin();pl<polyline_array.end();pl++)
					{
						//�ַ���תdouble 
						x = atof(str_split(str_array[5],comma_delim)[0].c_str());
						y = atof(str_split(str_array[5],comma_delim)[1].c_str());
						
						if((*pl).get_id() == str_array[2])
						{
							//��set polyline set������ 
							(*pl).set_set(*(str_array[4].c_str())-'0',x,y);
							break;
						}
					}
				}
				
				//��set polyline move������ 
				if(str_array[3]=="move")
				{
					for(pl=polyline_array.begin();pl<polyline_array.end();pl++)
					{
						//�ַ���תdouble 
						x = atof(str_split(str_array[5],comma_delim)[0].c_str());
						y = atof(str_split(str_array[5],comma_delim)[1].c_str());
						
						if((*pl).get_id() == str_array[2])
						{
							(*pl).set_move(*(str_array[4].c_str())-'0',x,y);
							break;
						}
					}
				}
				
				//��set polyline del������ 
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
				
				//��set polyline set_length������ 
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
				
				//��set polyline name������ 
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
		
		//���pointsԭ������ 
		points.clear();
		
		//��ring������ 
		if(str_array[1]=="ring")
		{
			//������rg 
			vector<Ring>::iterator rg;//rg is ring
			
			//��add ring������ 
			if(str_array[0]=="add")
			{
				//num_vector�洢��������� 
				vector<string> num_vector = str_split(str_array[3],comma_delim);
				
				for(int i=0;i<num_vector.size();i++)
				{
					x = atof(num_vector[i].c_str());
					y = atof(num_vector[++i].c_str());
					points.push_back(Point(x,y));
				}
				
				//ring�������ĵ�����ʼ����ͬ 
				x = atof(num_vector[0].c_str());
				y = atof(num_vector[1].c_str());
				points.push_back(Point(x,y));
				ring_array.push_back(Ring(str_array[2],points));
			}
			
			//��del ring������ 
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
			
			//��set ring������ 
			if(str_array[0]=="set")
			{
				//��set ring set������ 
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
				
				//��set ring move������ 
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
				
				//��set ring del������ 
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
				
				//��set ring set_length������ 
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
				
				//��set ring set_area������ 
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
				
				//��set ring name������ 
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
			
			//��judge������ 
			if(str_array[0]=="judge")
			{
				string flag;
				
				//�ҵ����жϵ� 
				vector<class Point>::iterator p1;
				for(p1=point_array.begin();p1<point_array.end();p1++)
				{
					if((*p1).get_id() == str_array[4])
						break;
				}
				
				//�ҵ�������ring 
				for(rg=ring_array.begin();rg<ring_array.end();rg++)
				{
					if((*rg).get_id() == str_array[2])
						break;
				}
				
				//���жϽ��д���ļ� 
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
		
		//���pointsԭ������ 
		points.clear();
		
		//��polygon������ 
		if(str_array[1]=="polygon")
		{
			//������pg 
			vector<class Polygon>::iterator pg;//pg is polygon
			
			//��add polygon������ 
			if(str_array[0]=="add")
			{
				
				vector<string> num_vector = str_split(str_array[4],comma_delim);
				
				for(int i=0;i<num_vector.size();i++)
				{
					x = atof(num_vector[i].c_str());
					y = atof(num_vector[++i].c_str());
					points.push_back(Point(x,y));
				}
				
				//polygonĩβ������ʼ����ͬ 
				x = atof(num_vector[0].c_str());
				y = atof(num_vector[1].c_str());
				
				//�����polygon���� 
				points.push_back(Point(x,y));
				Ring outer_ring(str_array[3],points);
				Polygon new_polygon(str_array[2],outer_ring);
				
				//����polygon_array�� 
				polygon_array.push_back(new_polygon);
			}
			
			//��del polygon������ 
			if(str_array[0]=="del")
			{
				for(pg=polygon_array.begin();pg<polygon_array.end();pg++)
				{
					if((*pg).get_id() == str_array[2])
					{
						//��polygon_array��ɾȥ������polygon 
						polygon_array.erase(pg);
						break;
					}
				}
			}
			
			//��set polygon������ 
			if(str_array[0]=="set")
			{
				//��set polygon inner������ 
				if(str_array[3]=="inner")
				{
					//points���ԭ���� 
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
							
							//inner ring��������ʼ����ͬ 
							x = atof(num_vector[0].c_str());
							y = atof(num_vector[1].c_str());
							
							points.push_back(Point(x,y));
							Ring inner_ring(str_array[3],points);
							(*pg).set_inner(inner_ring);
							break;
						}
					}
				}
				
				//��set polygon set������ 
				if(str_array[3]=="set")
				{
					//��set polygon set outer������ 
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
					
					//��set polygon set inner������ 
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
				
				//��set polygon move������ 
				if(str_array[3]=="move")
				{
					//��set polygon move outer������ 
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
					
					//��set polygon move inner������ 
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
				
				//��set polygon del������ 
				if(str_array[3]=="del")
				{
					//��set polygon del outer������ 
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
					
					//��set polygon del inner������ 
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
				
				//��set polygon set_length������ 
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
				
				//��set polygon set_area������ 
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
				
				//��set polygon name������ 
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
			
			//judge���� 
			if(str_array[0]=="judge")
			{
				string flag;
				
				//�ҵ����жϵ� 
				vector<Point>::iterator p1;
				for(p1=point_array.begin();p1<point_array.end();p1++)
				{
					if((*p1).get_id() == str_array[4])
						break;
				}
				
				//�ҵ����ж�polygon 
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
	
	//���������������Ϣ 
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
