
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int dpa(int x);
int dp(int x);

int n,T;
int *p;
int minpos,minnums;


int main()
{
	cin>>n>>T;
	p=(int*)malloc(sizeof(int)*n);
	minpos=0;minnums=0;
	for(int i=0;i<n;++i)
	{
		scanf("%d",p+i);
		if(p[minpos]>=p[i])minpos=i;
	}
	for(int i=minpos;i>=0;--i)
	{
		if(p[i]==p[minpos])
		{
			++minnums;
			minpos=i;
		}
	}
	int x=n*T-1;
	cout<<dp(x)<<endl;
	
	free(p);
	return 0;

}



int dpa(int x)
{
	if(x==0)return 1;
	else if(x%n==minpos)return x/n*minnums+1;
	else
	{
		int pos=x%n;
		int i=pos-1;
		while(1)
		{
			while(i>=0&&p[i]<p[pos]){--i;--x;}
			if(i<0)
			{
				i+=n;
				continue;
			}
			return dpa(x);
		}
	}

}

int dp(int x)
{
	if(x==0)return 1;
	int lastdp=dp(x-1),lastdpa=dpa(x);
	return lastdp>lastdpa?lastdp:lastdpa;
}

