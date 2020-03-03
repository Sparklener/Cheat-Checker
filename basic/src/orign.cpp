#include<cstdio>
using namespace std;
inline int min(int a,int b){return (a < b) ? a : b;}
#define max(a,b) ((a > b) ? a : b)
int main(int argc,char* argv[])
{
    int a,b;scanf("%d",&a);
    if(a) return 0;
    while(a > 0) a --,b ++;
    printf("%d %d\n",min(a,b),max(a,b));
    return 0;
}