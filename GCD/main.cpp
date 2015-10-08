#include<cstdio>
#include "gcd.h"
#include "enhanced_gcd.h"
int test_enhanced_gcd();
int test_gcd();
int main()
{
	//test_gcd();
	test_enhanced_gcd();

	return 0;

}
int test_enhanced_gcd()
{
	int a,b;
	double c,x,y;
	scanf("%d%d%lf",&a,&b,&c);
	double start;
	if(scanf("%lf",&start)!=1)start=-1;
	enhanced_gcd(a,b,c,x,y,start);
	printf("x=%f,y=%f\n",x,y);
	
	return 0;

}
int test_gcd()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int ret=gcd(a,b);
	printf("%d\n",ret);
	return 0;


}
