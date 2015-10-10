#include "extended_gcd.h"
#include<vector>
/**
*a,b,n are 3 integers
*find all x fitting 0<=x<n and (ax-b)%n=0
*(ax-b)%n=0,(ax-b+n)%n=0,ax1=ax0+n,x1=x0+n%a,
*solution:let ax-b=k*n,0<=x<n,-b<=k*n<an-b
*resolv: ax-kn=b,find its all solutions for every k
*x=(b+k*n)/a
*
*ax1-nk1=b,nx0-(a-a/n*n)k0=b,a(-k0)+n(x0+a/nk0)=b
*x1=-k0,k1=-(x0+a/n*k0)
*if k==0,x=b/a.0  (should be an integer)  if not,
*0 -b/a.0
*-b/a.0	-
*
*/
std::vector<long long> line_mod_equotion(const long long a,const long long b,const long long n)
{
	std::vector<long long> ret;
	long long x,y;
	long long d=extended_gcd(a,n,x,y,1);
	ret.clear();	
	if(b%d==0)
	{
		x%=n;x+=n;x%=n;
		x=x*b/d%n;
		ret.push_back(x);
		for(long long i=1;i<d;++i)
			ret.push_back((x+i*n/d)%n);
	}
	return ret;
}
