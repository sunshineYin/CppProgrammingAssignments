// File: OGRGeometry.cpp
// Author: yinganmin6837@163.com(Ganmin Yin)
// Date: 2018/06/21
// Description:
//    The implementation of the class OGRGeometry.


#include "OGRGeometry.h"
#include<stdio.h>

using namespace std;

int OGRGeometry::global_id = 0;

OGRGeometry::OGRGeometry(): id(global_id++){}

OGRGeometry::~OGRGeometry() = default;

int OGRGeometry::GetID() const
{
	return id;
}

/*
void OGRGeometry::ExportToWkt(string path)
{
	FILE* pFile = fopen(path.c_str(),"w");
	fprintf(pFile,"%s",toString().c_str());
}
*/

