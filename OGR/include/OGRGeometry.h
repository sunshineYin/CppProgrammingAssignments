// File: OGRGeometry.h
// Author: yinganmin6837@163.com(Ganmin Yin)
// Date: 2018/06/21
// Description:
//    The declaration of the class OGRGeometry.



#ifndef OGR_OGRGEOMETRY_H
#define OGR_OGRGEOMETRY_H

#include "OGRMBR.h"
#include<string>


using namespace std;

class OGRGeometry;

class OGRGeometry
{
	public:
		OGRGeometry();
		virtual ~OGRGeometry();
		
		virtual char* GetGeometryType() const = 0;
		virtual OGRMBR GetMBR() const = 0;

		virtual void Copy(const OGRGeometry &) = 0;
		virtual bool Equals(const OGRGeometry &) const = 0;
		
		int GetID() const;
		
		virtual void ImportFromWkt(string path) = 0;
		virtual void ExportToWkt(string path) = 0;
		//virtual string toString() const;
	
	protected:
		 static int global_id;	
		
	private:
		int id;
};

#endif // OGR_OGRGEOMETRY_H

