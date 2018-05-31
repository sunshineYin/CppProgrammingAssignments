// File: ring.cpp
// Author: yinganmin6837@163.com
// Date: 2018/05/31
// Description:
//    The implementation of the class "Ring".



#include "ring.h"

using namespace std;




Ring::Ring() = default;

Ring::Ring(string id,vector<Point> &points):id(id),point_list(points),name("NULL"),length("NULL"),area("NULL"){
};

Ring::~Ring() = default;

string Ring::get_id()
{
	return id;
}

vector<Point> Ring::get_points()
{
	return point_list;
}

void Ring::set_set(int nPoint,double set_x,double set_y)
{
	if(nPoint==0||nPoint==point_list.size()-1)
	{
		point_list[0].set_set(set_x,set_y);
		point_list[point_list.size()-1].set_set(set_x,set_y);
	}
	else
		point_list[nPoint].set_set(set_x,set_y);
}

void Ring::set_move(int nPoint,double set_x,double set_y)
{
	if(nPoint==0||nPoint==point_list.size()-1)
	{
		point_list[0].set_move(set_x,set_y);
		point_list[point_list.size()-1].set_move(set_x,set_y);
	}
	else
		point_list[nPoint].set_move(set_x,set_y);
}

void Ring::set_del(int nPoint)
{
	vector<Point>::iterator p;
	if(nPoint==0)
	{
		p = point_list.begin();
		point_list.erase(p);
		p = point_list.begin()+point_list.size()-1;
		point_list.erase(p);
		point_list.push_back(point_list[0]);
	}
	else
	{
		p = point_list.begin();
		point_list.erase(p+nPoint);
	}
}

void Ring::set_set_length(string newLen)
{
	length = newLen;
}

void Ring::set_set_area(string newArea)
{
	area = newArea;
}

void Ring::set_name(string newName)
{
	name = newName;
}

bool Ring::judge(Point &p)
{
	bool flag=0;
	for(int i=0,j=point_list.size()-2;i<point_list.size()-1;j=i,i++)
	{
		double sx = point_list[i].get_x();
		double sy = point_list[i].get_y();
		double tx = point_list[j].get_x();
		double ty = point_list[j].get_y();
		double px = p.get_x();
		double py = p.get_y();
		if((sx==px&&sy==py)||(tx==px&&ty==py))
			return 1;
		if((sy<py&&ty>=py)||(sy>=py&&ty<py))
		{
			float x = sx+(py-sy)*(tx-sx)/(ty-sy);
			if(x==px)
				return 0;
			if(x>px)
				flag = !flag;
		}
	}
	return flag;
}

void Ring::printout()
{
	ofstream fout;
	fout.open("output.txt",ios_base::app);
	if(!fout)
	{
		cout<<"File open error!"<<endl;
		system("pause");
	}
	string ring_info = "ring "+id+" [";
	ostringstream oss;
	for(int i=0;i<point_list.size()-1;i++)
	{
		oss.str("");
		oss<<point_list[i].get_x()<<","<<point_list[i].get_y();
		ring_info += "["+oss.str()+"],";
	}
	oss.str("");
	oss<<point_list[point_list.size()-1].get_x()<<","<<point_list[point_list.size()-1].get_y();
	ring_info += "["+oss.str()+"]";
	ring_info += "], name="+name+", length="+length+", area="+area;
	fout<<ring_info<<endl;
	fout.close();
}


