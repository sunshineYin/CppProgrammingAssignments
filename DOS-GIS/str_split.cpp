// File: str_split.cpp
// Author: yinganmin6837@163.com(Ganmin Yin)
// Date: 2018/05/31
// Description:
//    This function is to accept an original string and a seperator string,
//    and return a string vector after spliting.
// Sample in: str = "1,2,3,4" , delim = ","
// Sample out: ["1","2","3","4"]

#include "str_split.h"

using namespace std;


vector<string> str_split(const string &str,const string &delim)
{
	vector<string> str_vec;
	string::size_type pos1,pos2;
	pos2 = str.find(delim);
	pos1 = 0;
	while(pos2!=string::npos)
	{
		str_vec.push_back(str.substr(pos1,pos2-pos1));
		pos1 = pos2+delim.size();
		pos2 = str.find(delim,pos1);
	}
	if(pos1!=str.length())
		str_vec.push_back(str.substr(pos1));
	return str_vec;
}
