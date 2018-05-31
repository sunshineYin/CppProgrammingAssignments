// File: point.h
// Author: yinganmin6837@163.com(Ganmin Yin)
// Date: 2018/05/31
// Description:
//    The declaration of the class "Point".


#ifndef DOS_GIS_POINT_H
#define DOS_GIS_POINT_H

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<string.h>
#include<stdlib.h>

using namespace std;

class Point;

class Point
{
	public:
		Point();
		Point(double X,double Y);
		Point(string ID,double X,double Y);
		~Point();
		
		string get_id(); 
		double get_x();
		double get_y();

		void set_set(double set_x,double set_y);
		void set_move(double set_x,double set_y);
		void set_name(string newName);
		bool judge(Point &p);
		
		void printout();
		
	private:
		string id;
		double x;
		double y;
		string name;
};

#endif //DOS_GIS_POINT_H
