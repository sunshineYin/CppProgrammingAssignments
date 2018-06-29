// File: OGRPoint.cpp
// Author: yinganmin6837@163.com(Ganmin Yin)
// Date: 2018/06/21
// Description:
//    The implementation of the class OGRPoint.


#include "OGRPoint.h"
#include<iostream>
#include<stdio.h>
#include<sstream>

using namespace std;

OGRPoint::OGRPoint() = default;

OGRPoint::OGRPoint(double set_x, double set_y): x(set_x),y(set_y) {}

OGRPoint::OGRPoint(const OGRPoint &newPoint)
{
	x = newPoint.get_x();
	y = newPoint.get_y();
}

OGRPoint::~OGRPoint() = default;

double OGRPoint::get_x() const
{
	return x;
}

double OGRPoint::get_y() const
{
	return y;
}

char* OGRPoint::GetGeometryType() const
{
	char *p = "OGRPoint";
	return p;
}

OGRMBR OGRPoint::GetMBR() const
{
	OGRMBR mbr(x,x,y,y);
	return mbr;
}

void OGRPoint::Copy(const OGRGeometry &newGeo)
{
	OGRPoint* newPoint = (OGRPoint*)(&newGeo);
	x = newPoint->get_x();
	y = newPoint->get_y();
}

bool OGRPoint::Equals(const OGRGeometry &newGeo) const
{
	OGRPoint* newPoint = (OGRPoint*)(&newGeo);
	return x==newPoint->get_x() && y==newPoint->get_y();
}

void OGRPoint::ImportFromWkt(string path)
{
	FILE* pFile = fopen(path.c_str(),"r");
	fscanf(pFile,"Point (%lf %lf)",&x,&y);
}

void OGRPoint::ExportToWkt(string path)
{
	FILE* pFile = fopen(path.c_str(),"w");
	ostringstream oss;
	oss<<"Point ("<<x<<" "<<y<<")";
	fprintf(pFile,"%s",oss.str().c_str());
}


