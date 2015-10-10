本目录为gcd系列算法

1.普通gcd算法

gcd(a,b)=(b==0?a:gcd(b,a%b))

2.扩展gcd算法
解方程ax+by=gcd(a,b)的解
特解:根据x=y',y=x'-a/b*y'
x=x*+kb',y=y*+ka'

3.单元模线性方程
	ax=b(mod n)
	等价于求扩展gcd的一个特解,通过周期扩展求出所有解;b%d!=0,无解

4.中国剩余定理
	xi=ai (mod mi),mi互质.设M=product(mi),Mi=M/mi,PiMi+qmi=1的解Pi(extended(Mi,mi,x,y),解出x还需要将x乘以b/g
	设ei=PiMi,则ei模mi要么为1,要么为0,所以构造解 e1a1+...enan,解一定以M为周期,所以只需把结果变换到0,M中


5.辅助函数
	将数转换到正周期以内:x=x%M;x+=M;x%=M

