// File: polygon.cpp
// Author: yinganmin6837@163.com(Ganmin Yin)
// Date: 2018/05/31
// Description:
//    The implementation of the class "Polygon".



#include "polygon.h"

using namespace std;



Polygon::Polygon() = default;

Polygon::Polygon(string ID,Ring &outer_ring)
{
	id = ID;
	outer = outer_ring;
	vector<Point> inner_points;
	inner = Ring("inner",inner_points);
	name = "NULL";
	length = "NULL";
	area = "NULL";
}

Polygon::~Polygon() = default;

string Polygon::get_id()
{
	return id;
}

void Polygon::set_inner(Ring &inner_ring)
{
	inner = inner_ring;
}

void Polygon::set_set_outer(int nPoint,double set_x,double set_y)
{
	outer.set_set(nPoint,set_x,set_y);
}

void Polygon::set_move_outer(int nPoint,double set_x,double set_y)
{
	outer.set_move(nPoint,set_x,set_y);
}

void Polygon::set_del_outer(int nPoint)
{
	outer.set_del(nPoint);
}

void Polygon::set_set_inner(int nPoint,double set_x,double set_y)
{
	inner.set_set(nPoint,set_x,set_y);
}

void Polygon::set_move_inner(int nPoint,double set_x,double set_y)
{
	inner.set_move(nPoint,set_x,set_y);
}

void Polygon::set_del_inner(int nPoint)
{
	inner.set_del(nPoint);
}

void Polygon::set_set_length(string newLen)
{
	length = newLen;
}

void Polygon::set_set_area(string newArea)
{
	area = newArea;
}

void Polygon::set_name(string newName)
{
	name = newName;
}

bool Polygon::judge(Point &p)
{
	return(outer.judge(p)&&!inner.judge(p));
}

void Polygon::printout()
{
	ofstream fout;
	fout.open("output.txt",ios_base::app);
	if(!fout)
	{
		cout<<"File open error!"<<endl;
		system("pause");
	}
	string polygon_info = "polygon "+id+" outer=[";
	ostringstream oss;
	for(int i=0;i<outer.get_points().size()-1;i++)
	{
		oss.str("");
		oss<<outer.get_points()[i].get_x()<<","<<outer.get_points()[i].get_y();
		polygon_info += "["+oss.str()+"],";
	}
	oss.str("");
	oss<<outer.get_points()[outer.get_points().size()-1].get_x()<<","<<outer.get_points()[outer.get_points().size()-1].get_y();
	polygon_info += "["+oss.str()+"]";
	polygon_info += "], inner=[";
	for(int i=0;i<inner.get_points().size()-1;i++)
	{
		oss.str("");
		oss<<inner.get_points()[i].get_x()<<","<<inner.get_points()[i].get_y();
		polygon_info += "["+oss.str()+"],";
	}
	oss.str("");
	oss<<inner.get_points()[inner.get_points().size()-1].get_x()<<","<<inner.get_points()[inner.get_points().size()-1].get_y();
	polygon_info += "["+oss.str()+"]";
	polygon_info += "], name="+name+", length="+length+", area="+area;
	fout<<polygon_info<<endl;
	fout.close();
}

