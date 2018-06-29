// File: OGRSimpleCurve.h
// Author: yinganmin6837@163.com(Ganmin Yin)
// Date: 2018/06/21
// Description:
//    The declaration of the class OGRSimpleCurve.



#ifndef OGR_OGRSIMPLECURVE_H
#define OGR_OGRSIMPLECURVE_H

#include "OGRCurve.h"

using namespace std;

class OGRSimpleCurve;

class OGRSimpleCurve: public OGRCurve
{
	public:
		char* GetGeometryType() const;
};

#endif // OGR_OGRSIMPLECURVE_H
