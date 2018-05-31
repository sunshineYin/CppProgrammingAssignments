// File: ring.h
// Author: yinganmin6837@163.com(Ganmin Yin)
// Date: 2018/05/31
// Description:
//    The declaration of the class "Ring".


#ifndef DOS_GIS_RING_H
#define DOS_GIS_RING_H

#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include "point.h"

using namespace std;

class Ring;

class Ring
{
	public:
		Ring();
		Ring(string id,vector<Point> &points);
		~Ring();
		
		string get_id();
		vector<Point> get_points();
		
		void set_set(int nPoint,double set_x,double set_y);
		void set_move(int nPoint,double set_x,double set_y);
		void set_del(int nPoint);
		void set_set_length(string newLen);
		void set_set_area(string newArea);
		void set_name(string newName);
		bool judge(Point &p);//if the ring covers the point.
		
		void printout();
	private:
		string id;
		vector<Point> point_list;
		string name;
		string length;
		string area;
};

#endif //DOS_GIS_RING_H
