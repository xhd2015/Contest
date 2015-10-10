

/**
*problem:  ax+by=gcd(a,b)  all (x,y),x ,y ,a>=0,b>=0,are intergers
*solution:	bx'+(a%b)y'=gcd(b,a%b)=gcd(a,b),got ay'+b(x'-a/by')=gcd(a,b)*y'=x,x'=y+a/bx  or    x=y',y=x'-a/by'
*same solution with    a`x=gcd(a,b) ,it has the same solution with ax+by=gcd(a,b). If a group of solution is given to fit a`x=gcd(a,b)=a`,stop at x=1,y=Y.if a y2=Y+dY,
*if x0,y0 is a solution for the original form,a(x-x0)+b(y-y0)=0,y
*
*/


long long extended_gcd(long long a,long long b,long long &x,long long &y,const long long &start=1)
{
	if(b==0){x=1;y=start;return a;}
	else {
		long long ret=extended_gcd(b,a%b,y,x,start);
		y-=a/b*x;
		return ret;
	}
	
}
