int dfs(int x)
{
if(x==100) return 0;
return dfs(x+1)+1;
}
int main()
{
int a;
int b;
cin>>a>>b;
cout<<a+b<<endl;
return 0;
}