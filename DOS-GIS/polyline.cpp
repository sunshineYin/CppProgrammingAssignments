// File: polyline.cpp
// Author: yinganmin6837@163.com(Ganmin Yin)
// Date: 2018/05/31
// Description:
//    The implementation of the class "Polyline".


#include "polyline.h"

using namespace std;

Polyline::Polyline() = default;

Polyline::Polyline(string ID,vector<Point> &points):id(ID),point_list(points),name("NULL"),length("NULL"){
}

Polyline::~Polyline() = default;

string Polyline::get_id()
{
	return id;
}

void Polyline::set_set(int nPoint,double set_x,double set_y)
{
	point_list[nPoint].set_set(set_x,set_y);
} 

void Polyline::set_move(int nPoint,double set_x,double set_y)
{
	point_list[nPoint].set_move(set_x,set_y);
}

void Polyline::set_del(int nPoint)
{
	vector<Point>::iterator p;
	p = point_list.begin();
	point_list.erase(p+nPoint);
}

void Polyline::set_set_length(string newLen)
{
	length = newLen;
}

void Polyline::set_name(string newName)
{
	name = newName;
}

void Polyline::printout()
{
	ofstream fout;
	fout.open("output.txt",ios_base::app);
	if(!fout)
	{
		cout<<"File open error!"<<endl;
		system("pause");
	}
	string polyline_info = "polyline "+id+" [";
	ostringstream oss;
	for(int i=0;i<point_list.size()-1;i++)
	{
		oss.str("");
		oss<<point_list[i].get_x()<<","<<point_list[i].get_y();
		polyline_info += "["+oss.str()+"],";
	}
	oss.str("");
	oss<<point_list[point_list.size()-1].get_x()<<","<<point_list[point_list.size()-1].get_y();
	polyline_info += "["+oss.str()+"]";
	polyline_info += "], name="+name+", length="+length;
	fout<<polyline_info<<endl;
	fout.close();
}


