



#include "OGRPolygon.h"

using namespace std;

OGRPolygon::OGRPolygon() = default;

OGRPolygon::OGRPolygon(const OGRPolygon &newPg): OGRCurvePolygon(newPg){}

OGRPolygon::~OGRPolygon() = default;

OGRLinearRing *OGRPolygon::GetOuterRing() const
{
	return (OGRLinearRing*)curve_list[0];
}

char* OGRPolygon::GetGeometryType() const
{
	char* p = "OGRPolygon";
	return p;
}

void OGRPolygon::Copy(const OGRGeometry &newGeo)
{
	OGRPolygon* newPg = (OGRPolygon*)(&newGeo);
	int size = newPg.get_curve_list().size();
	curve_list.clear();
	for(int i=0;i<size;i++)
	{
		curve_list.push_back(newPg.get_curve_list()[i]);
	}
}

bool OGRPolygon::Equals(const OGRPolygon &newPg) const
{
	return OGRCurvePolygon::Equals(&newPg);
}

// 待完成 
void OGRPolygon::ImportFromWkt(string path)
{
	
}

// 待完成 
void OGRPolygon::ExportToWkt(string path)
{
	
}



