


#include "OGRCurvePolygon.h"
#include<vector>

using namespace std;

vector<OGRCurve *> OGRCurvePolygon::get_curve_list() const
{
	return curve_list;
}

OGRCurvePolygon::OGRCurvePolygon() = default;

OGRCurvePolygon::OGRCurvePolygon(const OGRCurvePolygon &newCP)
{
	int size = newCP.get_curve_list().size();
	curve_list.clear();
	for(int i=0;i<size;i++)
	{
		curve_list.push_back(newCP.get_curve_list()[i]);
	}
}

OGRCurvePolygon::~OGRCurvePolygon() = default;

char* OGRCurvePolygon::GetGeometryType() const
{
	char* p = "OGRCurvePolygon";
	return p;
}

OGRMBR OGRCurvePolygon::GetMBR() const
{
	OGRMBR mbr;
	for(int i=0;i<curve_list.size();i++)
	{
		mbr.merge(curve_list[i]->GetMBR());
	}
	return mbr;
}

bool OGRCurvePolygon::Equals(const OGRGeometry *newGeo) const
{
	OGRCurvePolygon* newCP = (OGRLinearRing*)newGeo;
	bool flag = true;
	int size1 = curve_list.size();
	int size2 = newCP->get_curve_list().size();
	if(size1 != size2)
		flag = false;
	else
	{
		for(int i=0;i<size1;i++)
		{
			if(!(*curve_list[i]).Equals(*(newCP->get_curve_list()[i])))
			{
				flag = false;
				break;
			}
		}
	}
	return flag;
}

double OGRCurvePolygon::GetPerimeter() const
{
	double perim = 0;
	int size = curve_list.size();
	for(int i=0;i<size;i++)
	{
		perim += curve_list[i]->GetLength();
	}
	return perim;
}


