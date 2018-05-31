// File: polyline.h
// Author: yinganmin6837@163.com(Ganmin Yin)
// Date: 2018/05/31
// Description:
//    The declaration of the class "Polyline".



#ifndef DOS_GIS_POLYLINE_H
#define DOS_GIS_POLYLINE_H

#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include "point.h"


using namespace std;

class Polyline;

class Polyline
{
	public:
		Polyline();
		Polyline(string ID,vector<Point> &points);
		~Polyline();
		
		string get_id();
		
		void set_set(int nPoint,double set_x,double set_y);
		void set_move(int nPoint,double set_x,double set_y);
		void set_del(int nPoint);
		void set_set_length(string newLen);
		void set_name(string newName);
		
		void printout();
	private:
		string id;
		vector<Point> point_list;
		string name;
		string length;
};

#endif //DOS_GIS_POLYLINE_H
