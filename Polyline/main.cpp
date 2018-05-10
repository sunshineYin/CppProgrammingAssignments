/*************************
* File:main.cpp

* Author:yinganmin6837@163.com(Ganmin Yin)

* Time:2018/05/08

* Information:
*** This file mainly calculates the coordinate of the marked points of the polyline,
*** the number of segments, the total length,the degree of tortuosity and other information
*** based on the data input from the file "input.txt".

**************************/


#include<iostream>
#include<math.h>
#include "point_vector.h"

const int MAX_POINTNUM = 20;

using namespace std;

/**************the basic information of this project*************/
void title()
{
	cout<<"\n\t\t=======================";
	cout<<"\n\n\t\t*折线标注问题";
	cout<<"\n\n\t\t*作者：尹赣闽（1600012436）";
	cout<<"\n\n\t\t*时间：2018/05/08";
	cout<<"\n\n\t\t=======================";
	cout<<"\n";
	system("pause"); 
}

/*******************
* Information: 
*** This function is to calculate the length of the polyline.
*** And "count" means the number of segments of the polyline to be calculated.
*** The "p" is the pointer of an array of floats, representing the list of lines(vectors).
********************/
float polyline_len(int count,float *p)
{
    float len = 0;
    for(int i=0;i<count;i++)
        len += *(p+i);
    return len;
}

/********************
* Information: 
*** This function is to get a list of the required marked points.
*** And "n" means the number of marked points(referenced the file "input.txt").
*** "point_step" is the average distance between the marked points.
*** "vec_list" is the list of vectors represented by the segments of the polyline.
*** "vec_len_list" is the list of the lengths of each member in "vec_list".
*** "output_point_list" is the list of the required marked points.
********************/
void find_point_list(int n,float point_step,Vector *vec_list,float *vec_len_list,Point *output_point_list)//Point point_list[n];
{
    int i;
    int j=1;
    for(i=1;i<=n;i++)
    {
    	//find each marked point.
        while(polyline_len(j,vec_len_list)<i*point_step)
            j++;
        output_point_list[i-1].x = vec_list[j-1].get_start_point().x + (i*point_step-polyline_len(j-1,vec_len_list))/vec_len_list[j-1]*(vec_list[j-1].get_end_point().x-vec_list[j-1].get_start_point().x);
        output_point_list[i-1].y = vec_list[j-1].get_start_point().y + (i*point_step-polyline_len(j-1,vec_len_list))/vec_len_list[j-1]*(vec_list[j-1].get_end_point().y-vec_list[j-1].get_start_point().y);
    }
    return ;
}

/***********************
* Information:
*** This function is to print the coordinates of the marked points.
*** "n" is the number of marked points.
*** "output_point_list" is the list of marked points.
************************/
void print_point_coordinate(int n,Point *output_point_list)
{
	cout<<"注记坐标："<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<output_point_list[i].x<<' '<<output_point_list[i].y<<endl;//setwidth?(.6f)
    }
    return ;
}

/************************
* Information:
*** This function is to calculate the tortuosity of the polyline.
*** "first_point" is the first point of the polyline.
*** "last_point" is the last point of the polyline.
*** "m" and "vec_len_list" refers to the function "polyline_len".
*************************/
float calc_polyline_tortuosity(Point first_point,Point last_point,int m,float *vec_len_list)
{
	float tortuosity,distance,length;
	distance = sqrt(pow(last_point.x-first_point.x,2)+pow(last_point.y-first_point.y,2));
	length = polyline_len(m-1,vec_len_list);
	tortuosity = distance/length;
	return tortuosity;
}

int main()
{
	title();
	system("cls");
    int N,m,n;
    float x,y;
    //initialize the list of points input by file "input.txt".
    Point input_point_list[MAX_POINTNUM];
    //initialize the list of marked points to be print.
    Point output_point_list[MAX_POINTNUM];
    //initialize the list of vectors.
    Vector vec_list[MAX_POINTNUM-1];
    //initialize the list of lengths of each members of "vec_list".
    float vec_len_list[MAX_POINTNUM-1];
    FILE *pFile;
    pFile = fopen("input.txt","r");
    if(pFile == NULL)
    {
    	cout<<"File open error!"<<endl;
    	system("pause");
    	//return 0;
	}
	//"N" is the number of examples.
	//"N" is also the number of the first circle.
	fscanf(pFile,"%d",&N);
	float point_step;
	for(int i=0;i<N;i++)
	{
		cout<<"===================="<<endl;
		cout<<"Polyline "<<(i+1)<<":"<<endl;
		fscanf(pFile,"%d %d",&m,&n);
		//assign values to the list "input_point_list" based on the file "input.txt".
		for(int j=0;j<m;j++)
		{
			fscanf(pFile,"%f %f",&x,&y);
			input_point_list[j].x = x;
			input_point_list[j].y = y;
		}
		//assign values to "vec_list" and "vec_len_list" based on the "input_point_list".
		for(int j=0;j<m-1;j++)
		{
			vec_list[j] = Vector(input_point_list[j],input_point_list[j+1]);
			vec_len_list[j] = vec_list[j].len();
		}
		//the average distance between the marked points.
		point_step = polyline_len(m-1,vec_len_list)/(n+1);
		find_point_list(n,point_step,vec_list,vec_len_list,output_point_list);
		print_point_coordinate(n,output_point_list);
		cout<<"线段数量："<<m-1<<endl;
		cout<<"总长度："<<polyline_len(m-1,vec_len_list)<<endl;
		cout<<"曲折度："<<calc_polyline_tortuosity(input_point_list[0],input_point_list[m-1],m,vec_len_list)<<endl;
	} 
	fclose(pFile);
	pFile = NULL;
	cout<<"===================="<<endl;
	system("pause");
    return 0;
}
