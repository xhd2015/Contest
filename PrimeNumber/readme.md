本目录素数相关

1.素数判定
	只需判断0,sqrt(n)即可检验m是否为素数

2.素数筛
	对于2,n的数,每次遍历i是,将2*i,3*i,4*i,....划掉,最后得到一些从未划过的数,即可得到素数表,复杂度O(nlogn)

3.分解质因数(独立发现于2015-10-09)
	对于a,先将a分解成l^k*r的形式,再求l,r的分解式,合起来就是a的分解式子.复杂度,设a有n个质因数,则,最坏情况下n=1,复杂度为sqrt(n),一般地,f(a)=
	算法描述:
		defactor(long long a,int k,&store)
			if a==2  store[a]+=k;
			else 
				for i 从 sqrt(n)到2
					如果i整除a,则找到a中i的次数k
						递归求defactor(i,k,resetore),defactor(a/i^k,1,restore)
						break;
				如果 i小于2 (没有进入过break):store[a]+=k;

4.分解质因数
	给定一个素数表,先寻找a最大的一个因数,用二分法,不在一个值得左边 0-sqrt  sqrt-a

5.费马小定理与素性测试
