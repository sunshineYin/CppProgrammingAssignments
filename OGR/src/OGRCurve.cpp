// File: OGRCurve.cpp
// Author: yinganmin6837@163.com(Ganmin Yin)
// Date: 2018/06/21
// Description:
//    The implementation of the class OGRCurve.


#include "OGRCurve.h"


using namespace std;


char* OGRCurve::GetGeometryType() const
{
	char* p = "Curve";
	return p;
}

vector<OGRPoint> OGRCurve::get_point_list() const
{
	return point_list;
}
