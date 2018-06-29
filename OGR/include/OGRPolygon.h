


#ifndef OGR_OGRPOLYGON_H
#define OGR_OGRPOLYGON_H

#include "OGRCurvePolygon.h"
#include "OGRLinearRing.h"

using namespace std;

class OGRPolygon;

class OGRPolygon: public OGRCurvePolygon
{
	public:
		OGRPolygon();
		OGRPolygon(const OGRPolygon &);
		~OGRPolygon();
		
		OGRLinearRing *GetOuterRing() const;
		
		char* GetGeometryType() const;
		void Copy(const OGRGeometry &);
		bool Equals(const OGRPolygon &) const;
		void ImportFromWkt(string path);
		void ExportToWkt(string path);
		
		double GetArea() const;
		
		bool Contains(const OGRGeometry *) const;
};

#endif // OGR_OGRPOLYGON_H 
