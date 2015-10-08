#include<cstdio>
#include "gcd.h"

/**
*problem: ax+by=gcd(a,b)
*solution: ax1+by1=c
*		bx2+(a-a/b*b)y2=c,then ay2+b(x2-a/by2)=c,x1=y2,y1=x2-a/b*y2
*		b=0,x0=ca.0
*/

void enhanced_gcd(int a,int b,const double &c,double &x,double &y,double start=-1)
{
	if(b==0){x=c/a;y=start;return;}
	else
	{
		enhanced_gcd(b,a%b,c,x,y,start);
		double x0=x,y0=y;
		x=y0;y=x0-a/b*y0;
		printf("a=%d,b=%d,c=%f,x=%f,y=%f,start=%f\n",a,b,c,x,y,start);
		return;
	}


}
