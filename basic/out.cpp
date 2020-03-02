int main()
{
int a;
int b;
cin>>a;
if(a)
{
return 0;
}
while(a>0)
{
a--;
b++;
}
cout<<(a<b)?a:b<<" "<<((a>b)?a:b)<<endl;
return 0;
}