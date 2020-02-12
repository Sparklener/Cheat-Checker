/*
 * Creator: Eqvpkbz
 * Create Date: 2020.2.12
 * Use ./deal FILE_NAME to generate FILE without '\n' and ' ' 
 */


#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
string s;
int main(int argc,char *argv[])
{
	freopen(argv[1],"r",stdin);
	freopen("data.out","w",stdout);
	while(cin >> s)
	{
		if(s.find("#include") == s.npos)
			cout << s;
	}
	fclose(stdin),fclose(stdout);
	return 0;
}
