


#include "OGRLinearRing.h"
#include<cmath>

using namespace std;


OGRLinearRing::OGRLinearRing() = default;

OGRLinearRing::OGRLinearRing(const vector<OGRPoint> points)
{
	for(int i=0;i<points.size();i++)
	{
		point_list.push_back(points[i]);
	}
}

OGRLinearRing::OGRLinearRing(const OGRLinearRing &newLR)
{
	vector<OGRPoint>::iterator p;
	for(p=newLR.get_point_list().begin();p<newLR.get_point_list().end();p++)
	{
		point_list.push_back(OGRPoint(p->get_x(),p->get_y()));
	}
}

OGRLinearRing::~OGRLinearRing() = default;

char* OGRLinearRing::GetGeometryType() const
{
	char* p = "OGRLinearRing";
	return p;
}

void OGRLinearRing::Copy(const OGRGeometry &newGeo)
{
	OGRLinearRing* newLR = (OGRLinearRing*)(&newGeo);
	vector<OGRPoint>::iterator p;
	point_list.clear();
	for(p=newLR->get_point_list().begin();p<newLR->get_point_list().end();p++)
	{
		point_list.push_back(OGRPoint(p->get_x(),p->get_y()));
	}
}

bool OGRLinearRing::Equals(const OGRGeometry &newGeo) const
{
	OGRLinearRing* newLR = (OGRLinearRing*)(&newGeo);
	bool flag = true;
	int size1 = point_list.size();
	int size2 = newLR->get_point_list().size();
	if(size1 != size2)
		flag = false;
	else
	{
		for(int i=0;i<size1;i++)
		{
			if(!point_list[i].Equals(newLR->get_point_list()[i]))
			{
				flag = false;
				break;
			}
		}
	}
	return flag;
}

void OGRLinearRing::ImportFromWkt(string path){}

void OGRLinearRing::ExportToWkt(string path){}

void OGRLinearRing::to_close_ring()
{
	int size = point_list.size();
	if(!point_list[0].Equals(point_list[size-1]))
		point_list.push_back(point_list[0]);
}

double OGRLinearRing::GetArea() const
{
	double area = 0;
	int size = point_list.size();
	for(int i=0;i<size;i++)
	{
		result += point_list[i].get_x()*point_list[(i+1)%size].get_y() - point_list[i].get_y()*point_list[(i+1)%size].get_x();
	}
	return abs(result/2);
}

bool OGRLinearRing::Contains(const OGRGeometry *newGeo) const
{
	bool flag = true;
	if(strcmp(newGeo->GetGeometryType(),"OGRPoint") == 0)
		return Contains((OGRPoint*)newGeo);
	else if(strcmp(newGeo->GetGeometryType(),"OGRLineString") == 0)
	{
		OGRLineString* ls = (OGRLineString*)newGeo;
		for(int i=0;i<ls.get_point_list().size();i++)
		{
			if(!Contains(&ls.get_point_list()[i]))
			{
				flag = false;
				break;
			}
		}
		return flag;
	}
	else if(strcmp(newGeo->GetGeometryType(),"OGRPolygon") == 0)
	{
		OGRLinearRing lr = ((OGRPolygon*)newGeo)->GetOuterRing();
		for(int i=0;i<lr.get_point_list().size();i++)
		{
			if(!Contains(&lr.get_point_list()[i]))
			{
				flag = false;
				break;
			}
		}
		return flag;
	}
}

bool OGRLinearRing(const OGRPoint *newPt) const
{
	double px = newPt.get_x();
	double py = newPt.get_y();
	bool flag = true;
	int size = point_list.size();
	for(int i=0,j=size-1;i<size;j=i,i++)
	{
		double sx = point_list[i].x;
		double sy = point_list[i].y;
		double tx = point_list[j].x;
		double ty = point_list[j].y;
		// on is in(contains) ?
		if((sx==px&&sy==py)||tx==px&&ty==py)
			return false;
		if((sy<py&&ty>=py)||(sy>=py&&ty<py))
		{
			double x = sx+(py-sy)*(tx-sx)/(ty-sy);
			if(x==px)
				return false; // on is in(contains) ?
			if(x>px)
				flag = !flag;
		}
	}
	return flag;
}
