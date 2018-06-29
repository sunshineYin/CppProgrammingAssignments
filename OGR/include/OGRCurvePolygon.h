


#ifndef OGR_OGRCURVEPOLYGON_H
#define OGR_OGRCURVEPOLYGON_H

#include "OGRSurface.h"
#include "OGRCurve.h"
#include<vector>

using namespace std;

class OGRCurvePolygon;

class OGRCurvePolygon: public OGRSurface
{
	public:
		vector<OGRCurve *> get_curve_list() const;
		
		OGRCurvePolygon();
		OGRCurvePolygon(const OGRCurvePolygon &);
		~OGRCurvePolygon();
		
		char* GetGeometryType() const;
		OGRMBR GetMBR() const;
		bool Equals(const OGRGeometry *) const;
		
		double GetPerimeter() const;
		
		
	protected:
		vector<OGRCurve *> curve_list;
};

#endif // OGR_OGRCURVEPOLYGON_H
