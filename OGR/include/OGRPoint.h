





#ifndef OGR_OGRPOINT_H
#define OGR_OGRPOINT_H

#include "OGRGeometry.h"
//#include<>

// File: OGRPoint.h
// Author: yinganmin6837@163.com(Ganmin Yin)
// Date: 2018/06/21
// Description:
//    The declaration of the class OGRPoint.


using namespace std;

class OGRPoint;

class OGRPoint: public OGRGeometry
{
	public:
		OGRPoint();
		OGRPoint(double set_x, double set_y);
		OGRPoint(const OGRPoint &newPoint);
		~OGRPoint();
		
		double get_x() const;
		double get_y() const;
		
		char* GetGeometryType() const;
		OGRMBR GetMBR() const;
		void Copy(const OGRGeometry &);
		bool Equals(const OGRGeometry &) const;
		
		void ImportFromWkt(string path);
		void ExportToWkt(string path);
		
		
	private:
		double x;
		double y;	
};

#endif // OGR_OGRPOINT_H

