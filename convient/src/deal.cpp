#include<cstdio>
#include<string>
#include<cstdlib>
using namespace std;
int main(int argc,char* argv[])
{
	string CMD,FN;
	for(int i = 1;i < argc;i ++)
	{
		FN.assign(argv[i]);
		CMD = "g++ -S " + FN;
		FN.erase(FN.find('.'),FN.npos);
		FN += ".s";
		
		system(CMD.data());
		CMD = "sed -i '1d' " + FN;
		system(CMD.data());
	}
	return 0;
}
