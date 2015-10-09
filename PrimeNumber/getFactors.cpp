#include<cmath>
#include<cstdio>
#include<map>
#include "getFactors.h"
/*
std::map<int,int> getByPrimeTable(){

}
*/
int
getOrders(
	int &a,
	int i
	);
void
getBySqrt_enhance_help(
	int a,
	std::map<int, int>& stores,
	int ordr
	);

int show_iterator(std::map<int, int>::const_iterator it)
{
	return it->second;

}
int show_at(std::map<int, int>& mp, int a)
{

	return mp[a];
}


void test_getBySqrt_ori()
{
	int a;
	scanf("%d", &a);
	std::map<int, int> ret;getBySqrt_ori(a, ret);
	printf("%d=", a);
	for (std::map<int, int>::iterator it = ret.begin(), itend = ret.end();
	it != itend;++it)
		printf("%d^%d * ", it->first, it->second);
	printf("\b\b \n");


}
void
getBySqrt_ori(
	int a,
	std::map<int, int>& stores
	) {
	if (a == 2) { ++stores[a];return; }
	else
	{
		int i;
		for (i = sqrt(a);i >= 2;--i)
		{
			if (a%i == 0)
			{
				++stores[a / i];
				getBySqrt_ori(i, stores);
				break;
			}
		}
		if (i<2)++stores[a];
	}
}

void test_getBySqrtEnhance()
{
	int a;

	scanf("%d", &a);

	std::map<int, int> ret;getBySqrt_enhance(a, ret);

	printf("%d=", a);
	for (std::map<int, int>::iterator it = ret.begin(), itend = ret.end();
	it != itend;++it)
		printf("%d^%d * ", it->first, it->second);
	printf("\b\b \n");

}
void
getBySqrt_enhance(
	int a,
	std::map<int, int>& stores
	) {
	getBySqrt_enhance_help(a, stores, 1);
}

void
getBySqrt_enhance_help(
	int a,
	std::map<int, int>& stores,
	int ordr
	) {

	if (a == 1) { return; }
	if (a == 2) { stores[a] += ordr;return; }
	else {
		int i;
		for (i = sqrt(a);i >= 2;--i)
		{
			if (a%i == 0) {
				int rsrv = a;
				int k = getOrders(rsrv, i);
				getBySqrt_enhance_help(i, stores, k*ordr);
				if(rsrv!=1)
				getBySqrt_enhance_help(rsrv, stores, ordr);

					break;
			}
		}
		if (i<2)stores[a] += ordr;
	}


}

int
getOrders(
	int &a,
	int i
	) {
	int cnt = 0;
	while (a%i == 0) { ++cnt;a /= i; }
	return cnt;
}








