#include<cstdio>
#include "extended_gcd.h"
#include "gcd.h"
#include "enhanced_gcd.h"
#include "line_mod_equotion.h"
#include "gcd_by_ljr.h"
#include<vector>
int test_enhanced_gcd();
int test_extended_gcd();
int test_line_mod_equotion();
int test_gcd();
int test_gcd_by_ljr();
int main()
{
	//test_gcd();
//	test_enhanced_gcd();
	//test_extended_gcd();
	//test_line_mod_equotion();
	test_gcd_by_ljr();
	return 0;

}
int test_gcd_by_ljr()
{
	int T;
	scanf("%d",&T);
	std::vector<int> data(T);
	for(int i=0;i<T;++i)scanf("%d",&data[i]);
	std::vector<int> reta=geta(data[0],data[1],data[2]);
	for(size_t i=0;i<reta.size();++i){
		printf("%d ::",reta[i]);
		std::vector<int> retb=getb(data[0],data[1],reta[i]);
		for(size_t j=0;j<retb.size();++j)
			printf("%d ",retb[j]);
		printf("\n");
	}
	return 0;
}
int test_line_mod_equotion()
{
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	std::vector<int> ret=line_mod_equotion(a,b,n);
	for(std::vector<int>::iterator it=ret.begin();it!=ret.end();++it)
		printf("%d ",*it);
	printf("\na=%d,b=%d,n=%d\n",a,b,n);

return 0;
}
int test_extended_gcd()
{
	int a,b;
	int d,x,y;
	int start;
	scanf("%d%d%d",&a,&b,&start);
	
	d=extended_gcd(a,b,x,y,start);
	printf("a=%d,b=%d,start=%d,x=%d,y=%d\n",a,b,start,x,y);
	printf("gcd=%d\n",d);
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
