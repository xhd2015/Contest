#ifndef _VERIFY_GUESS_H_
#define _VERIFY_GUESS_H_

#include<cstdio>
#include<cstdlib>
#include<set>
#include<utility>

void test_get_decompress();
void init_table(unsigned int n);
int is_prime(unsigned int n);
std::pair<unsigned int,unsigned int> get_decompress(unsigned int this_prm);

#endif
