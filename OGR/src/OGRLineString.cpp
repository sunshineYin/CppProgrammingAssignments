



#include "OGRLineString.h"
#include<cmath>

using namespace std;

OGRLineString::OGRLineString() = default;

OGRLineString::OGRLineString(const vector<OGRPoint> points)
{
	for(int i=0;i<points.size();i++)
	{
		point_list.push_back(points[i]);
	}
}

OGRLineString::OGRLineString(const OGRLineString &newLS)
{
	vector<OGRPoint>::iterator p;
	for(p=newLS.get_point_list().begin();p<newLS.get_point_list().end();p++)
	{
		point_list.push_back(OGRPoint(p->get_x(),p->get_y()));
	}
}

OGRLineString::~OGRLineString() = default;

char* OGRLineString::GetGeometryType() const
{
	char* p = "OGRLineString";
	return p;
}

OGRMBR OGRLineString::GetMBR() const
{
	OGRMBR mbr;
	//vector<OGRPoint>::iterator p;
	//double xmin,xmax,ymin,ymax;
	int size = point_list.size();
	//for(p=point_list.begin();p<point_list.end();p++)
	for(int i=0;i<size;i++)
	{
		mbr.Xmin = min(mbr.Xmin,point_list[i].get_x());
		mbr.Xmax = max(mbr.Xmax,point_list[i].get_x());
		mbr.Ymin = min(mbr.Ymin,point_list[i].get_y());
		mbr.Ymax = max(mbr.Ymax,point_list[i].get_y());
	}
	return mbr;
}

void OGRLineString::Copy(const OGRGeometry &newGeo)
{
	OGRLineString* newLS = (OGRLineString*)(&newGeo);
	vector<OGRPoint>::iterator p;
	point_list.clear();
	for(p=newLS->get_point_list().begin();p<newLS->get_point_list().end();p++)
	{
		point_list.push_back(OGRPoint(p->get_x(),p->get_y()));
	}
}

bool OGRLineString::Equals(const OGRGeometry &newGeo) const
{
	OGRLineString* newLS = (OGRLineString*)(&newGeo);
	bool flag = true;
	int size1 = point_list.size();
	int size2 = newLS->get_point_list().size();
	if(size1 != size2)
		flag = false;
	else
	{
		for(int i=0;i<size1;i++)
		{
			if(!point_list[i].Equals(newLS->get_point_list()[i]))
			{
				flag = false;
				break;
			}
		}
	}
	return flag;
}

void OGRLineString::ImportFromWkt(string path){}

void OGRLineString::ExportToWkt(string path){}


double OGRLineString::GetLength() const
{
	double length = 0;
	int size = point_list.size();
	for(int i=1;i<size;i++)
	{
		length += sqrt(pow(point_list[i].get_x()-point_list[i-1].get_x(),2)+pow(point_list[i].get_y()-point_list[i-1].get_y(),2));
	}
	return length;
}

