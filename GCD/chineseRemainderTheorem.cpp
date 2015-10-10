#include<vector>
#include "extended_gcd.h"
#include<cstdio>
#include "chineseRemainderTheorem.h"
#include "line_mod_equotion.h"

#define LL long long


void
testEquotion(){
	int n;
	printf("Please input equotion numbers n:");scanf("%d",&n);
	printf("Please input %d numbers of a",n);
	std::vector<long long> arr(n);
	for(int i=0;i<n;++i)scanf("%lld",&arr[i]);
	printf("Please input %d numbers of m",n);
	std::vector<long long> marr(n);

	for(int i=0;i<n;++i)scanf("%lld",&marr[i]);

	long long solu=equotion(arr,marr);
	printf("solution is: %lld\n",solu);
}

LL
equotion(
const std::vector<LL>& arr,
const std::vector<LL>& marr
){
	LL ret=0;
	LL Mi,Pi;
	LL M=1;
	for(size_t i=0;i<marr.size();++i)
	{
		M*=marr[i];	
	}
	long long x,y;	
	for(size_t i=0;i<marr.size();++i)
	{
		Mi=M/marr[i];	
		extended_gcd(Mi,marr[i],x,y);
		ret+=x*Mi*arr[i];
	}
	ret%=M;ret+=M;ret%=M;
	return ret;


}


#undef LL

