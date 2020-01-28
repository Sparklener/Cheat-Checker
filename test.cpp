#include<cctype>
#include<cstdio>
#include<cmath>
using namespace std;

#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %lld\n ",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %lld\n ",__FUNCTION__,__LINE__)
#define file(FILENAME) freopen(FILENAME".in","r",stdin),freopen(FILENAME".out","w",stdout)
#define file_close fclose(stdin),fclose(stdout)

typedef long long ll;
typedef long double ldb;

#define MAXBUF 2097152
#define FLUSHSIZE 1966080
#define Finline __inline__ __attribute__ ((always_inline))
char READ_BUF[MAXBUF],*READ_P1=READ_BUF,*READ_P2=READ_BUF;
Finline int getc(){return READ_P1==READ_P2&&(READ_P2=(READ_P1=READ_BUF)+fread(READ_BUF,1,MAXBUF,stdin),READ_P1==READ_P2)?EOF:*READ_P1++;}
static inline ll read()
{
    ll num=0;char c,sf=1;
    while(isspace(c=getc()));if(c=='-') sf=-1,c=getc();
    while(num=num*10+c-48,isdigit(c=getc()));
    return num*sf;
}
static inline ldb read_dec()
{
    ldb num=0,decs=1;char c,sf=1;
    while(isspace(c=getc()));if(c=='-') sf=-1,c=getc();
    while(num=num*10+c-48,isdigit(c = getc()));
    if(c!='.') return num*sf;c=getc();
    while(num+=(decs*=0.1)*(c-48),isdigit(c=getc()));
    return num*sf;
}
char WRITE_BUF[MAXBUF],WRITE_BUFFER[20];int WRITE_P1,WRITE_P2=-1;
static inline void flush(){fwrite(WRITE_BUF,1,WRITE_P2+1,stdout),WRITE_P2=-1;}
static inline void check(){if(WRITE_P2>FLUSHSIZE) flush();return ;}
static inline void write(ll x)
{
    if(x<0) WRITE_BUF[++WRITE_P2]=45,x=-x;
    do{WRITE_BUFFER[++WRITE_P1]=x%10+48;}while(x/=10);
    do{WRITE_BUF[++WRITE_P2]=WRITE_BUFFER[WRITE_P1];}while(--WRITE_P1);
    WRITE_BUF[++WRITE_P2]='\n';
}
static inline void write_dec(ldb x,int len)
{
    if(x<0) WRITE_BUF[++WRITE_P2]=45,x=-x;ll integral=floor(x);x-=integral;
    do{WRITE_BUFFER[++WRITE_P1]=integral%10+48;}while(integral/=10);
    do{WRITE_BUF[++WRITE_P2]=WRITE_BUFFER[WRITE_P1];}while(--WRITE_P1);
    WRITE_BUF[++WRITE_P2]='.';
    do{x*=10,integral=floor(x),x-=integral,WRITE_BUF[++WRITE_P2]=integral+48;}while(--len);
    WRITE_BUF[++WRITE_P2]='\n';
}
const int MAXN = 105;
const int MAXM = 105;
const int MOD = 9999973;
ll n,m,f[MAXN][MAXM][MAXM],c[MAXM];
int main()
{
#ifndef ONLINE_JUDGE
    file("main");
#endif

    n = read(),m = read();
    c[0] = 0;
    for(int i = 0;i <= m;i ++)
        c[i] = ((i * (i - 1)) >> 1) % MOD;
    f[0][0][0] = 1;
    for(int i = 1;i <= n;i ++)
    for(int j = 0;j <= m;j ++)
    for(int k = 0;k <= m - j;k ++)
    {
        f[i][j][k] = f[i - 1][j][k];
        if(k > 0) f[i][j][k] += f[i - 1][j + 1][k - 1] * (j + 1);
        if(j > 0) f[i][j][k] += f[i - 1][j - 1][k] * (m - j - k + 1);
        if(k > 0) f[i][j][k] += f[i - 1][j][k - 1] * j * (m - j - k + 1);
        if(j > 1) f[i][j][k] += f[i - 1][j - 2][k]* c[m - j - k + 2];
        if(k > 1) f[i][j][k] += f[i - 1][j + 2][k - 2] * c[j + 2];
        f[i][j][k] %= MOD;
    }
    ll ans = 0;
    for(int i = 0;i <= m;i ++)
        for(int j = 0;j <= m;j ++)
            ans = (ans + f[n][i][j]) % MOD;
    write(ans),flush();

#ifndef ONLINE_JUDGE
    file_close;
#endif
    return 0;
}