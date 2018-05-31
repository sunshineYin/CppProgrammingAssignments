// File: point.cpp
// Author: yinganmin6837@163.com(Ganmin Yin)
// Date: 2018/05/31
// Description:
//    The implementation of the class "Point".



#include "point.h"

using namespace std;

Point::Point() = default;

Point::Point(double X,double Y):id("NULL"),x(X),y(Y),name("NULL"){
}

Point::Point(string ID,double X,double Y):id(ID),x(X),y(Y),name("NULL"){
}

Point::~Point() = default;

string Point::get_id()
{
	return id;
}

double Point::get_x()
{
	return x;
}

double Point::get_y()
{
	return y;
}

void Point::set_set(double set_x,double set_y)
{
	x = set_x;
	y = set_y;
}

void Point::set_move(double set_x,double set_y)
{
	x += set_x;
	y += set_y;
}

void Point::set_name(string newName)
{
	name = newName;
}

bool Point::judge(Point &p)
{
	return(x==p.get_x()&&y==p.get_y());
}

void Point::printout()
{
	ofstream fout;
	fout.open("output.txt",ios_base::app);
	if(!fout)
	{
		cout<<"File open error!"<<endl;
		system("pause");
	}
	string point_info;
	ostringstream oss;
	oss<<x<<","<<y;
	point_info = "point "+id+" ["+oss.str()+"], "+"name="+name;
	fout<<point_info<<endl;
	fout.close();
}

