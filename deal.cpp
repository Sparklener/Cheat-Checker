#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;
int main(int argc,char* argv[])
{
	system("g++ generate.cpp -o generate");
	string FN,CMD;
	for(int i = 1;i < argc;i ++)
	{
		FN.assign(argv[i]);
		CMD = "./generate " + FN;
		printf("%s\n",CMD.data());
		system(CMD.data());
	}
	return 0;
}
