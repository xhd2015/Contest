#include "make_prime_table.h"

#include<cstdio>
#include<cstdlib>
#include<vector>

std::vector<unsigned int> tbl;
std::vector<unsigned int>& make_new_table(unsigned int n)
{
	tbl.clear();
	std::vector<char> & visited=*(new std::vector<char>(n));
	for(size_t i=0;i<n;++i)visited[i]=0;
	visited[0]=1;
	for(unsigned int i=2;i<=n;++i)if(!visited[i-1])
	for(unsigned int k=i*2;k<=n;k+=i)visited[k-1]=1;
	

	for(unsigned int i=0;i<n;++i)if(!visited[i])tbl.push_back(i+1);
	delete &visited;

	return tbl;
}

void test_make_new_table()
{
	unsigned int n;
	scanf("%u",&n);
	make_new_table(n);
	for(std::vector<unsigned int>::const_iterator it=tbl.begin(),itend=tbl.end();it!=itend;++it)
	{
		printf("%u ",*it);
	}
}




