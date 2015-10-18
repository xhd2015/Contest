#include "make_next_prime.h"
#include<cstdio>
#include<vector>

std::vector<unsigned int> primz = { 2,3 };
unsigned int make_next_prime(std::vector<unsigned int> &oldtable)
{
	size_t sz = oldtable.size();
	unsigned int next = oldtable.back() + 2;
	for (size_t i = 0;i < sz;)
	{
		if (next%oldtable[i] == 0)
		{
			next += 2;i = 0;continue;
		}
		++i;
	}
	oldtable.push_back(next);
	return next;
}
void test_make_next_prime()
{
	unsigned int cnt;
	printf("2 3 ");
	scanf("%u", &cnt);
	unsigned int p;
	while (cnt--)
	{
		p = make_next_prime(primz);
		printf("%u ", p);
	}
}
