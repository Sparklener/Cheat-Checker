#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
long long prime[150];
int cnt,ch[111];
const int Base = 10000; 
struct BigNumber
{
enum {MAXSIZE = 700,Base = 10000,Bits = 4};
int IOI[MAXSIZE];
int len,flag;
BigNumber():len(0){memset(IOI,0,sizeof(IOI));}
BigNumber(int x){memset(IOI,0,sizeof(IOI));IOI[0]=x,len=x>0?1:0;}
int InPut(char *ch)
{
int ok=strlen(ch),num,i,k;
if (ok>4*MAXSIZE){return 0;}
if(ch[0] == '-'){ok--,flag=-1;for(i=1;i<=ok;i++) ch[i-1]=ch[i];}
else flag=0;len=(ok+3)/4,k=len;bool zero=true;
for(i=num=0;i<ok%Bits;++i) num=num*10+ch[i]-'0';
if(num>0) IOI[--k]=num,zero=false;if(flag==0) flag=1;
for (num=0;i<ok;i+=Bits) 
{
IOI[--k]=1000*ch[i]+100*ch[i+1]+10*ch[i+2]+ch[i+3]-1111*'0';
if(IOI[k]!=0) zero=false;if(IOI[k]!=0&&flag==0) flag=1;
}
for(k--;k>=0;k--) IOI[k]=0; return 1;
}
bool operator <(const BigNumber &temp)const
{
int mf=0,i,fg[2];
bool zero[2];
zero[0]=zero[1]=true,fg[0]=flag,fg[1]=temp.flag;
for(i=len-1;i>=0;i--) if(IOI[i]!=0) zero[0]=false;
for(i=temp.len-1;i>=0;i--) if(temp.IOI[i]!=0) zero[1]=false;
if(zero[0]) fg[0]=0;if(zero[1]) fg[1]=0;
if(fg[0]!=fg[1]) return fg[0]<fg[1];
if(len<temp.len) mf=-1;
else if(len>temp.len) mf=1;
else for(i=len-1;i>=0;i--)
{
if(IOI[i]<temp.IOI[i]){mf=-1;break;}
if(IOI[i]>temp.IOI[i]){mf=1;break;}
}
if(fg[0]<0) mf*=-1;return mf<0;
}
BigNumber operator*(const BigNumber &r)
{
int res[MAXSIZE]={0},i,j,t;
for (i=0;i<len;++i)  
{
if(IOI[i]==0) continue;
for(j=0;j<r.len;j++) t=res[i+j]+IOI[i]*r.IOI[j],res[i+j]=t%Base,res[i+j+1]+=t/Base;
while(res[i+j]>=Base) res[i+j+1]+=res[i+j]/Base,res[i+j]%=Base;
}
for (i=MAXSIZE-1;i>=0;i--) if(res[i]!=0) break; 
BigNumber mf;mf.flag=flag*r.flag,mf.len=max(i+1,1);
for(i=0;i<mf.len;i++)mf.IOI[i]=res[i];return mf;
}
BigNumber operator -(const BigNumber &r)const
{
int i,j,s,p,q;
BigNumber mf,a,b;
a=*this,b=r;
if(a.flag) a.flag=1;
if(b.flag) b.flag=1;
mf.IOI[0]=0; 
if(this->flag==r.flag)
{
if(a<b)
{
mf.flag=-this->flag;
for(i=0;i<b.len;i++)
{
if(i<a.len) mf.IOI[i]-=a.IOI[i];
mf.IOI[i]+=b.IOI[i];
if(mf.IOI[i]<0) mf.IOI[i+1]=mf.IOI[i]/Base-(mf.IOI[i]%Base!=0),mf.IOI[i]=(mf.IOI[i]%Base+Base)%Base;
else mf.IOI[i+1]=0;
}
mf.len=b.len;
while(mf.len>1&&mf.IOI[mf.len-1]==0) mf.len--;
}
else if(b<a)
{
mf.flag=this->flag;
for(i=0;i<a.len;i++)
{
if(i<b.len) mf.IOI[i]-=b.IOI[i];
mf.IOI[i]+=a.IOI[i];
if(mf.IOI[i]<0) mf.IOI[i+1]=mf.IOI[i]/Base-(mf.IOI[i]%Base!=0),mf.IOI[i]=(mf.IOI[i]%Base+Base)%Base;
else mf.IOI[i+1]=0;
}
mf.len=a.len;
while(mf.len>1&&mf.IOI[mf.len-1]==0) mf.len--;
}
else
{
mf.len=1,mf.flag=0;
for(i=0;i<mf.len;i++) mf.IOI[i]=0;
}
}
else
{
mf.flag=this->flag;
if(this->flag==0) mf.flag=-r.flag;
for(i=0;i<a.len||i<b.len;i++)
{
if(i<a.len) mf.IOI[i]+=a.IOI[i];
if(i<b.len) mf.IOI[i]+=b.IOI[i];
mf.IOI[i+1]=mf.IOI[i]/Base,mf.IOI[i]%=Base;
}
while(mf.IOI[i]>0) i++;mf.len=i;
}
return mf;
}
BigNumber operator +(const BigNumber &r)const
{
int i,j,s,p,q;
BigNumber mf,a,b;
a=*this,b=r;
if(a.flag) a.flag=1;
if(b.flag) b.flag=1;
mf.IOI[0]=0;
if(this->flag!=r.flag)
{
if(a<b)
{
mf.flag=r.flag;
for(i=0;i<b.len;i++)
{
if(i<a.len) mf.IOI[i]-=a.IOI[i];
if(i<b.len) mf.IOI[i]+=b.IOI[i];
if(mf.IOI[i]<0)
{
mf.IOI[i+1]=mf.IOI[i]/Base-(mf.IOI[i]%Base!=0);
mf.IOI[i]=(mf.IOI[i]%Base+Base)%Base;
}
else mf.IOI[i+1]=0;
}
mf.len=b.len;
while(mf.len>1&&mf.IOI[mf.len-1]==0) mf.len--;
}
else if(b<a)
{
mf.flag=this->flag;
for(i=0;i<a.len;i++)
{
if(i<a.len) mf.IOI[i]+=a.IOI[i];
if(i<b.len) mf.IOI[i]-=b.IOI[i];
if(mf.IOI[i]<0)
mf.IOI[i+1]=mf.IOI[i]/Base-(mf.IOI[i]%Base!=0),
mf.IOI[i]=(mf.IOI[i]%Base+Base)%Base;
else mf.IOI[i+1]=0;
}
mf.len=a.len;
while(mf.len>1&&mf.IOI[mf.len-1]==0) mf.len--;
}
else mf.len=1,mf.flag=0,mf.IOI[0]=0;
}
else
{
mf.flag=this->flag;
for(i=0;i<a.len||i<b.len;i++)
{
if(i<a.len) mf.IOI[i]+=a.IOI[i];
if(i<b.len) mf.IOI[i]+=b.IOI[i];
mf.IOI[i+1]=mf.IOI[i]/Base,mf.IOI[i]%=Base;
}
while(mf.IOI[i]>0) i++; mf.len=i;
}
return mf;
}
bool Biger(const BigNumber &r,int k) 
{
if (k<r.len-1) return false;
for (int i=r.len-1;i>=0;--i,--k) 
{
if (IOI[k]>r.IOI[i]) return true;
if (IOI[k]<r.IOI[i]) return false;
} 
return true;
}
BigNumber operator/(int v)
{
int cs=0,i;
BigNumber mf=*this;
if(v<0) mf.flag*=-1,v=-v;
for (i=len-1;i>=0;--i) mf.IOI[i]+=cs,cs=mf.IOI[i]%v*Base,mf.IOI[i]=mf.IOI[i]/v;
for (i=len-1;i>=0;--i) if (mf.IOI[i]!=0) break;
mf.len=i+1;return mf;
}
BigNumber operator/(const BigNumber &r)
{
BigNumber q,l=*this,m;
if (r.len==0) return q;
int i,j,k,cs,t;
while(l.len>0&&l.IOI[l.len-1]==0)l.len--;m=r;
while(m.len>0&&m.IOI[m.len-1]==0)m.len--;k=0; 
for (i=l.len-1;i>=m.len-1;--i) 
{
if (q.IOI[0]!=0) q.len++;
while (l.Biger(m,i)) 
{
cs=0;
if (l.IOI[i]>m.IOI[m.len-1]) t=l.IOI[i]/(m.IOI[m.len-1]+1);
else t=1;
for (j=i-m.len+1,k=0;k<m.len;++k,++j) 
{
l.IOI[j]-=m.IOI[k]*t+cs,cs=0;
if (l.IOI[j]<0) cs=-(l.IOI[j]+1)/Base+1,l.IOI[j]+=cs*Base;
}
q.IOI[q.len]+=t;
}
if (i>0) l.IOI[i-1]+=l.IOI[i]*Base,l.IOI[i]=0;
}
q.flag=flag*r.flag;
if (q.IOI[0]) q.len++,reverse(q.IOI,q.IOI+q.len);
return q;
}
BigNumber operator%(const BigNumber &r)
{
BigNumber mf,l=*this;
mf=l-l/r*r;
if(mf.flag<0) mf=mf+r;
return mf;  
}  
}_ANS_,dddddd,a,b,c,d,e,f,px,py,R,zero,dist,sq,one,two,three,four;
char str[33];
double con(BigNumber x)
{
double res=0;
for(int i=x.len-1;i>=0;i--) res=res*Base+x.IOI[i];
if(x.flag<0) res*=-1;
return res;
}
BigNumber convert(long long x)
{
BigNumber mf;
mf.flag=0;
if(x<0) mf.flag=-1;
else if(x>0) mf.flag=1;
x=abs(x),mf.len=0;
while(x) mf.IOI[mf.len++]=x%Base,x/=Base;
return mf;
}
bool operator == (BigNumber x,BigNumber y){return !(x<y)&&!(y<x);}
const long double pi=acos(-1.);
long double awp;
int n,m,l;
bool is[10000];
long long mod,LQS[155];
int work(int o,char *O,int I)  
{  
char c, *D=O ; 
if(o>0)  
{
for(l=0;D[l];D[l++]-=10)  
{  
D[l++]-=120,D[l]-=110;  
while(!work(0,O,l)) D[l]+=20;  
putchar((D[l]+1032)/20);  
}  
putchar(10);  
}  
else  
{  
c=o+(D[I]+82)%10-(I>l/2)*(D[I-l+I]+72)/10-9;  
D[I]+=I<0 ? 0 : !(o=work(c/10,O,I-1))*((c+999)%10-(D[I]+92)%10);  
}  
return o;  
}
struct com{long double r,i;};
com operator +(com a,com b){com mf;mf.r=a.r+b.r,mf.i=a.i+b.i;return mf;}
com operator -(com a,com b){com mf;mf.r=a.r-b.r,mf.i=a.i-b.i;return mf;}
com operator *(com a,com b){com mf;mf.r=a.r*b.r-a.i*b.i,mf.i=(a.r*b.i+a.i*b.r);return mf;}
com operator /(com a,com b){com mf;mf.r=(a.r*b.r+a.i*b.i)/(b.r*b.r+b.i*b.i),mf.i=(-a.r*b.i+a.i*b.r)/(b.r*b.r+b.i*b.i);return mf;}
com operator *(com a,double b){com mf;mf.r=a.r*b,mf.i=a.i*b;return mf;}
com operator /(com a,double b){com mf;mf.r=a.r/b,mf.i=a.i/b;return mf;}
struct complex{ __int128  r,i;}bb[101][101][101];
com mm[101][101][101];long long up=(1LL<<62)-1+(1LL<<62);
void find(int x){if(!x) return x;else return find(x - 1);}
long long mul(__int128 a,long long b,long long mod){return a*b%mod;}
long long qpow(long long a,long long n,long long mod)
{
long long mf = 1,CNT = a;
while(n)
{
if(n & 1) mf = mul(mf,CNT,mod);
CNT = mul(CNT,CNT,mod),n /= 2;
}
return mf;
}
complex operator +(complex a,complex b){complex mf;mf.r=(a.r+b.r),mf.i=(a.i+b.i);return mf;}
complex operator -(complex a,complex b){complex mf;mf.r=(a.r-b.r),mf.i=(a.i-b.i);return mf;}
complex operator *(complex a,complex b){complex mf;mf.r=a.r*b.r-a.i*b.i,mf.i=a.r*b.i+a.i*b.r;return mf;}
complex operator *(complex a,int b){complex mf;mf.r=a.r*b,mf.i=a.i*b;return mf;}
complex un;
long long mat[101][101];
void init()
{
long long it;
cnt=0;
int i,j,s,p,q;
long long a;
for(it=up;cnt<67;it--)
{
for(i=0;i<2;i++)
{
a = rand();
long long test = qpow(a,it-1,it);
if(test != 1) break;
}
if(i>=2) prime[cnt++]=it;
}
}
int main()
{
#ifndef ONLINE_JUDGE
freopen("main.in","r",stdin);
freopen("main.out","w",stdout);
#endif
int i,j,s,p,q; 
long double mu=1; 
init(),scanf("%d%d",&n,&m);
if(m%2&&n%2==0) swap(n,m);
if(n%2&&m%2){putchar('0');return 0;}
one.flag=1,one.len=1,one.IOI[0]=1,zero.flag=0,zero.len=0,un.r=0,un.i=1; 
for(i=0;i<n;i++)bb[0][i][i].r=1,mm[0][i][i].r=1;
for(i=1;i<=m;i++)
{ 
for(j=0;j<n;j++)
{
complex tmp;
for(s=j+(m-i+1)%2;s<n;s+=2)
for(int ii=-1;ii<=1;ii++)
{ 
if(ii==0||j+ii<0||j+ii>s) continue;
com te=mm[i-1][j][s];
tmp=bb[i-1][j][s],swap(tmp.r,tmp.i),swap(te.r,te.i),te.r*=-1,tmp.r=mod-tmp.r,mm[i][j+ii][s]=mm[i][j+ii][s]+te,bb[i][j+ii][s]=bb[i][j+ii][s]+tmp; 
}
if(j&&(m-i)%2==0)
{
tmp=bb[i-1][j-1][j];  
com te=mm[i-1][j-1][j];
swap(tmp.r,tmp.i),swap(te.r,te.i),tmp.r=mod-tmp.r,te.r*=-1,bb[i][j-1][j-1]=bb[i][j-1][j-1]+tmp,mm[i][j-1][j-1]=mm[i][j-1][j-1]+te;
}
}
if(i>=2)
{
for(j=0;j<n;j++)
for(s=j+(m-i)%2;s<n;s+=2)
bb[i][j][s]=(bb[i][j][s]-bb[i-2][j][s]),mm[i][j][s]=(mm[i][j][s]-mm[i-2][j][s]);
}
for(j=0;j<n;j++) for(s=j+(m-i)%2;s<n;s+=2)
mm[i][j][s].r/=10.,mm[i][j][s].i/=10.;
}
for(i=0;i<n;i++) for(j=i+1;j<n;j++)
bb[m][j][i].r=bb[m][i][j].r,mm[m][j][i].r=mm[m][i][j].r;
for(i=0;i<n;i++)
{
long double ax=0;
ch[i]=i;
if(ch[i]!=i) for(j=i;j<n;j+=2) swap(mm[m][i][j].r,mm[m][ch[i]][j].r);
for(j=i+2;j<n;j+=2) for(s=i+2;s<n;s++)
mm[m][j][s].r-=mm[m][i][s].r/mm[m][i][i].r*mm[m][j][i].r;
}
for(q=0;q<cnt;q++)
{ 
int sign=1;
mod=prime[q];
for(i=0;i<n;i++) for(j=i%2;j<n;j+=2)
mat[j][i]=bb[m][i][j].r%mod;
for(i=0;i<n;i++)
{
if(ch[i]!=i) for(j=i;j<n;j+=2) swap(mat[i][j],mat[ch[i]][j]);
  __int128 mu=qpow(mat[i][i],mod-2,mod); 
for(j=i+2;j<n;j+=2)
{
__int128 ts=mat[j][i]*mu%mod;
for(s=i+2;s<n;s+=2) mat[j][s]=(mat[j][s]-ts*mat[i][s])%mod;
}
}
LQS[q]=1;
for(i=0;i<n;i+=2)
{
if(mat[i][i]<0) mat[i][i]+=mod;
LQS[q] = mul(LQS[q],mat[i][i],mod);
if(mm[m][i][i].r<0) LQS[q]=mod-LQS[q];
}
}
int YM_IS_A_VEGETABLE = one;
int LQS_TXDY = YM_IS_A_VEGETABLE;
dddddd=LQS_TXDY,_ANS_=zero;
for(q=0;q<cnt;q++)
{ 
__int128 k,bos=0,tos=0;
mod = prime[q]; 
for(i = dddddd.len - 1;i >= 0;i --) tos=(mul(tos,Base,prime[q])+dddddd.IOI[i])%prime[q];
for(i = _ANS_.len - 1;i >= 0;i --) bos=(mul(bos,Base,prime[q])+_ANS_.IOI[i])%prime[q];
bos=(LQS[q]-bos+prime[q])%prime[q],k=mul(bos,qpow(tos,prime[q]-2,prime[q]),prime[q]),
_ANS_=(convert(k)*dddddd+_ANS_),dddddd=dddddd*convert(prime[q]),_ANS_=_ANS_%dddddd;
}
int DECLEN = _ANS_.len - 1;
for(i = DECLEN;i >= 0;i --)
{
if(i == DECLEN) printf("%d",_ANS_.IOI[i]);
else printf("%04d",_ANS_.IOI[i]);
}
#ifndef ONLINE_JUDGE
fclose(stdin);
fclose(stdout);
#endif
return 0;
}