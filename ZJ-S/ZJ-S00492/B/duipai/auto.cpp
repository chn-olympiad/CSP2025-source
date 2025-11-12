#include<bits/stdc++.h>
using namespace std;

int main()
{
	system("g++ ../B.cpp -o B -O2 -std=c++14 -static");
	system("g++ brute.cpp -o brute -O2 -std=c++14 -static");
	system("g++ gen.cpp -o gen -O2 -std=c++14 -static");
	int c = 0;
	while(true)
	{
		printf("%d\n", ++c);
		system("./gen > road.in");
		system("./brute");system("./B");
		if(system("diff road.out road2.out")) break;
	}
	return 0;
}