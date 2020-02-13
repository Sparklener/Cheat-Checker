/*
 * Creator: Eqvpkbz
 * Create Date: 2020.2.12
 * Use ./deal FILE_NAME to generate FILE without '\n' 
 */


#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
string FNWS,S;
inline void generate(char* FN) //fn is FILENAME
{
	FNWS.assign(FN);
	FNWS.erase(FNWS.find('.'),FNWS.npos);
	FNWS += ".out";

	printf("(INFO) Dealing with %s\n",FN);

	freopen(FN,"r",stdin);
	freopen(FNWS.data(),"w",stdout);

	while(getline(cin,S))
	{
		if(S.find("#include") == S.npos)
			cout << S;
	}

	fclose(stdin),fclose(stdout);
	return ;
}
int main(int argc,char *argv[])
{
	if(argc > 2)
	{
		puts("ERROR!");
		return 0;
	}
	generate(argv[1]);
	return 0;
}
