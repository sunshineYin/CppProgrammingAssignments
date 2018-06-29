// File: OGRCurve.h
// Author: yinganmin6837@163.com(Ganmin Yin)
// Date: 2018/06/21
// Description:
//    The declaration of the class OGRCurve.




#ifndef OGR_OGRCURVE_H
#define OGR_OGRCURVE_H

#include "OGRGeometry.h"
#include "OGRPoint.h"
#include<vector>


using namespace std;


class OGRCurve;

class OGRCurve: public OGRGeometry
{
	public:
		char* GetGeometryType() const;
		virtual double GetLength() const = 0;
		vector<OGRPoint> get_point_list() const;
		
	protected:
		vector<OGRPoint> point_list;
};

#endif // OGR_OGRCURVE_H

