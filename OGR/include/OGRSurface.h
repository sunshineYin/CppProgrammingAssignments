


#ifndef OGR_OGRSURFACE_H
#define OGR_OGRSURFACE_H

#include "OGRGeometry.h"

using namespace std;

class OGRSurface;

class OGRSurface: public OGRGeometry
{
	public:
		char* GetGeometryType() const;
		virtual double GetArea() const = 0;
		
};

#endif // OGR_OGRSURFACE_H
