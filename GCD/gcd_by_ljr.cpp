#include<cmath>
#include "line_mod_equotion.h"
#include<vector>

std::vector<int> geta(int x1,int x3,int x5)
{
	std::vector<int> ret=line_mod_equotion(x3-x1,x5-x3,10001);
	for(std::vector<int>::size_type i=0;i<ret.size();++i)ret[i]=sqrt(ret[i]);
	return ret;
}

std::vector<int> getb(int x1,int x3,int a)
{

	std::vector<int> ret=line_mod_equotion(1+a,x3-a*a*x1,10001);
	return ret;


}

