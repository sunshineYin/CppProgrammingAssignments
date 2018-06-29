



#ifndef OGR_OGRLINEARRING_H
#define OGR_OGRLINEARRING_H

#include "OGRLineString.h"

using namespace std;

class OGRLinearRing;

class OGRLinearRing: public OGRLineString
{
	public:
		OGRLinearRing();
		OGRLinearRing(const vector<OGRPoint> points);
		OGRLinearRing(const OGRLinearRing &);
		~OGRLinearRing();
		
		char* GetGeometryType() const;
		
		void Copy(const OGRGeometry &newGeo);
		bool Equals(const OGRGeometry &newGeo) const;
		
		void ImportFromWkt(string path);
		void ExportToWkt(string path);
		
		void to_close_ring();
		
		double GetArea() const;
		bool Contains(const OGRGeometry *) const; 
		bool Contains(const OGRPoint *) const;
		
};

#endif // OGR_OGRLINEARRING_H
