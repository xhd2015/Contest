#ifndef _GET_FACTORS_H_
#define _GET_FACTORS_H_

#include<cmath>
#include<cstdio>
#include<map>
#include "getFactors.h"

std::map<int,int> getByPrimeTable();
int
getOrders(
	long long &a,
	int i
	);
void
getBySqrt_enhance_help(
	long long a,
	std::map<long long, int>& stores,
	int ordr
	);

int show_iterator(std::map<int, int>::const_iterator it);
int show_at(std::map<int, int>& mp, int a);
void test_getBySqrt_ori();
void
getBySqrt_ori(
	int a,
	std::map<int, int>& stores
	);
void test_getBySqrtEnhance();
void
getBySqrt_enhance(
long long a,
std::map<long long, int>& stores
);
void
getBySqrt_enhance_help(
long long a,
std::map<long long, int>& stores,
int ordr
);
int
getOrders(
	long long &a,
	int i
	);

#endif