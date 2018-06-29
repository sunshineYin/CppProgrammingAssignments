// File: OGRMBR.h
// Author: yinganmin6837@163.com(Ganmin Yin)
// Date: 2018/06/21
// Description:
//    The declaration of the class OGRMBR.


#ifndef OGR_OGRMBR_H
#define OGR_OGRMBR_H

#include<string>

using namespace std;

class OGRMBR;

class OGRMBR
{
	public:
		OGRMBR();
		OGRMBR(double min_x, double max_x, double min_y, double max_y);
		
		double Xmin;
		double Xmax;
		double Ymin;
		double Ymax;
		
		string toString() const;
		void merge(const OGRMBR &newMBR);
};


#endif // OGR_OGRMGR_H



