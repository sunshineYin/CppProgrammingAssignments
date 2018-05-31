// File: polygon.h
// Author: yinganmin6837@163.com(Ganmin Yin)
// Date: 2018/05/31
// Description:
//    The declaration of the class "Polygon".



#ifndef DOS_GIS_POLYGON_H
#define DOS_GIS_POLYGON_H

#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include "point.h"
#include "ring.h"

using namespace std;


class Polygon;

class Polygon
{
	public:
		Polygon();
		Polygon(string ID,Ring &outer_ring); 
		~Polygon();
		
		string get_id();
		
		void set_inner(Ring &inner_ring);
		void set_set_outer(int nPoint,double set_x,double set_y);
		void set_move_outer(int nPoint,double set_x,double set_y);
		void set_del_outer(int nPoint);
		void set_set_inner(int nPoint,double set_x,double set_y);
		void set_move_inner(int nPoint,double set_x,double set_y);
		void set_del_inner(int nPoint);
		void set_set_length(string newLen);
		void set_set_area(string newArea);
		void set_name(string newName);
		bool judge(Point &p);
		
		void printout();
	private:
		string id;
		Ring outer;
		Ring inner;
		string name;
		string length;
		string area;
};

#endif //DOS_GIS_POLYGON_H
