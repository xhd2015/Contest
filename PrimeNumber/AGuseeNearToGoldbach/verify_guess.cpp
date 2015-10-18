#include "verify_guess.h"
#include<cstdio>
#include<cstdlib>
#include<set>
#include<utility>
#define FILE_RC "prime_table.record"

std::set<unsigned int> prime_table;

void test_get_decompress()
{
	unsigned int n,m;
	scanf("%u%u",&m,&n);
	unsigned int max=m>n?m:n;
	unsigned int min=m-max+n;
	init_table(max);

	for(std::set<unsigned int>::const_iterator it=prime_table.begin(),itend=prime_table.end();
	it!=itend&&*it<=max;++it)
	{
		if(*it<min)continue;
		std::pair<unsigned int,unsigned int> pr=get_decompress(*it);
		if(pr.first!=0||pr.second!=0)printf("%u=2*%u+%u\n",*it,pr.first,pr.second);
		else fprintf(stderr,"wrong in %u\n",*it);
	}
}

void init_table(unsigned int n)
{
	FILE *fp;
	if((fp=fopen(FILE_RC,"r"))==NULL)
	{
		fprintf(stderr,"wrong open file");
		exit(1);
	}
	unsigned int i=0,k=0;
	while(i++<n&&fscanf(fp,"%d",&k)==1)
	{
		//printf("in init  %d=\n",k);
		prime_table.insert(k);
	}
	fclose(fp);

}


int is_prime(unsigned int n)
{
	return prime_table.count(n);
}

std::pair<unsigned int,unsigned int> get_decompress(unsigned int this_prm)
{
	std::pair<unsigned int,unsigned int> ret={0,0};
	/*
	*it starts from 3,not 2,so it=++itbeg
	*/

	for(std::set<unsigned int>::const_iterator itbeg=prime_table.begin(),itend=prime_table.end(),it=++itbeg;
	it!=itend&&*it<this_prm;++it)
	{
		if(is_prime((this_prm-*it)/2)&&*it!=(this_prm-*it)/2)
		{
			ret.second=*it;
			ret.first=(this_prm-*it)/2;
//			printf("in decompress :%d=2*%d+%d\n",this_prm,ret.second,ret.first);
			break;
		}

	}

	return ret;

}
