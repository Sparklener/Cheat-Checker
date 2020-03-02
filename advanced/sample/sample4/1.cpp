int dfs(int x)
{
if(x==100) return 0;
return dfs(x+1)+1;
}
int main()
{
#ifndef ONLINE_JUDGE
freopen("main.in","r",stdin);
freopen("main.out","w",stdout);
#endif
int a;
int b;
int c;
cin>>a>>b;c=a+b;
cout<<a+b<<endl;
#ifndef ONLINE_JUDGE
fclose(stdin);
fclose(stdout);
#endif
return 0;
}