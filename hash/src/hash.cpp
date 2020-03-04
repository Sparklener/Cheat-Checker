#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
typedef long double ldb;
typedef double db;

namespace char_seq
{
	const int MAXCALC = 1000;
	const int BUFSIZE = (1 << 18);
	ldb base = 1.0,A = 1.0;
	int tim;
	inline void CALC()
	{
		while(tim <= MAXCALC)
		    A += base,
		    A = base / A,
		    tim ++;
		return ;
	}
	inline int hash(int Key)
	{
		ldb least = (((ldb)Key) * A);
		least -= floor(least);
		return floor(least * ((ldb)BUFSIZE));
	}
	inline int CRC(char k[],int len)
	{
		int highorder,h = 0;
		for(int i = 0;i < len;i ++)
		{
			highorder = h & 0xf8000000;
			h <<= 5;
			h ^= (highorder >> 27);
			h ^= k[i];
		}
		return h;
	}
	inline int PJW(char k[],int len)
	{
		int h = 0,g;
		for(int i = 0;i < len;i ++)
		{
			h = (h << 4) + k[i];
			g = h & 0xf0000000;
			if(g)
				h ^= (g >> 24),
				h ^= g;
		}
		return h;
	}
	inline int BUZ(char k[],int len)
	{
		int h = 0,highorder;
		for(int i = 0;i < len;i ++)
		{
			highorder = h & 0x80000000;
			h <<= 1;
			h ^= (highorder >> 31);
			h ^= hash(k[i]);
		}
		return h;
	}
}

using namespace char_seq;
const int MAXN = 1e7 + 5;
char s[MAXN];
int main(int argc,char* argv[])
{
	if(argc > 2) 
    {
		puts("Use ./hash [FILENAME] to get the key.");
        return 0;
    }
    freopen(argv[1],"r",stdin);
	CALC();
	int len = 0;char c = getchar();
	while(c != EOF)
		s[len ++] = c,
		c = getchar();
	printf("%d\n%d\n%d\n",CRC(s,len),PJW(s,len),BUZ(s,len));
    fclose(stdin);
    return 0;
}
