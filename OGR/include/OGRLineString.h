


#ifndef OGR_OGRLINESTRING_H
#define OGR_OGRLINESTRING_H

#include "OGRSimpleCurve.h"
#include<string>

using namespace std;


class OGRLineString;

class OGRLineString: public OGRSimpleCurve
{
	public:
		OGRLineString();
		OGRLineString(const vector<OGRPoint> points);
		OGRLineString(const OGRLineString &);
		~OGRLineString();
		
		char* GetGeometryType() const;
		OGRMBR GetMBR() const;
		void Copy(const OGRGeometry &newGeo);
		bool Equals(const OGRGeometry &newGeo) const;
		
		void ImportFromWkt(string path);
		void ExportToWkt(string path);
		
		double GetLength() const;

};

#endif // OGR_OGRLINESTRING_H
