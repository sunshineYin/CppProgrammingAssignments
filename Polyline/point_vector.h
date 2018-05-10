/**************************
* File: point_vector.h
* Author: yinganmin6837@163.com(Ganmin Yin)
* Time: 2018/05/08
* Information:
*** The declaration of structure(Point) and class(Vector)
*** used in main.cpp.
**************************/

#ifndef POLYLINE_POINT_VECTOR_H
#define POLYLINE_POINT_VECTOR_H

#include<iostream>

struct Point;

struct Point
{
	float x;
	float y;	
};

class Vector;

class Vector
{
    //public:Point start_point;
    //public:Point end_point;
    public:
    	Vector(Point p1={0,0},Point p2={0,0}):start_point(p1),end_point(p2){}
    	float len()
    	{
    		float l;
    		l = sqrt(pow((end_point.x-start_point.x),2)+pow((end_point.y-start_point.y),2));
			return l;
    	}
    	Point get_start_point();
    	Point get_end_point();
    private:
    	Point start_point;
    	Point end_point;
}; 
Point Vector::get_start_point()
{
	return start_point;
}
Point Vector::get_end_point()
{
	return end_point;
}
#endif //POLYLINE_POINT_VECTOR_H
