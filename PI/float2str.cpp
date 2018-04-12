#include<iostream>
#include<stdlib.h>

using namespace std;

/*************浮点数转化成字符串函数***************/ 
char *float2str(double d,char *str)
{
	char str1[20];
	int j = 0,k,i;
	i = (int)d;
	while(i>0)
	{
		str1[j] = i%10 + '0';
		j++;
		i = i/10;
	}
	for(k=0;k<j;k++)
	{
		str[k] = str1[j-1-k];
	}
	str[j] = '.';
	j++;
	d = d-(int)d;
	for(i=0;i<10;i++)
	{
		d*=10;
		str[j] = (int)d+'0';
		j++;
		d = d-(int)d;
	}
	while(str[--j] == '0');
	j++;
	str[j] = '\0';
	return str;
}
