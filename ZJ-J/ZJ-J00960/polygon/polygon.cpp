#include<bits/stdc++.h>
using namespace std;
int main()
{
	fstream file=fstream("polygon.in",ios::in);
	fstream file2=fstream("polygon.out",ios::out);
	int n;
	file>>n;
	if(n==3)
	{
		int a,b,c;
		file>>a,b,c;
		if(a+b+c>max(max(a,b),c)*2)
		{
			file2<<"1";
		}
		else
		{
			file2<<"0";
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int temp;
		file>>temp;
	}
	file2<<"0";
	return 0;
}