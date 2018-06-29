// File: place.h
// Author: yinganmin6837@163(gmail).com(Ganmin Yin)
// Date: 2018/06/29
// Description:
//    The declaration of the class "Place".
//    "Place" is the abstract class to implement the class "Headquarter" and "City".


#ifndef WARCRAFT_PLACE_H
#define WARCRAFT_PLACE_H


using namespace std;

class Place;

class Place
{
	public:
		int element;
		Place();
		Place(int elem_);
		virtual ~Place();
};

#endif // WARCRAFT_PLACE_H

