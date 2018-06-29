// File: OGRSimpleCurve.cpp
// Author: yinganmin6837@163.com(Ganmin Yin)
// Date: 2018/06/21
// Description:
//    The implementation of the class OGRSimpleCurve.



#include "OGRSimpleCurve.h"

using namespace std;

char* OGRSimpleCurve::GetGeometryType() const
{
	char* p = "SimpleCurve";
	return p;
}
