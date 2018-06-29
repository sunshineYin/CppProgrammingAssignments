// File: OGRMBR.cpp
// Author: yinganmin6837@163.com(Ganmin Yin)
// Date: 2018/06/21
// Description:
//    The implementation of the class OGRMBR.




#include "OGRMBR.h"
#include<cfloat>
#include<string>
#include<sstream>


using namespace std;

OGRMBR::OGRMBR(): Xmin(DBL_MAX), Xmax(-DBL_MAX), Ymin(DBL_MAX), Ymax(-DBL_MAX){}

OGRMBR::OGRMBR(double min_x, double max_x, double min_y, double max_y):
	Xmin(min_x), Xmax(max_x), Ymin(min_y), Ymax(max_y){}

string OGRMBR::toString() const
{
	ostringstream oss;
	oss<<"MBR (("<<Xmin<<" "<<Ymin<<"), "<<"("<<Xmax<<" "<<Ymax<<"))";
	return oss.str(); 
}

void OGRMBR::merge(const OGRMBR &newMBR)
{
	Xmin = min(Xmin,newMBR.Xmin);
	Xmax = max(Xmax,newMBR.Xmax);
	Ymin = min(Ymin,newMBR.Ymin);
	Ymax = max(Ymax,newMBR.Ymax);
}

