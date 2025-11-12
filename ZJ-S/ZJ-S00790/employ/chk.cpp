#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=1;;++i)
	{
		system("./gen>in");
		system("./bru<in>ans");
		system("./sol<in>out");
		if(system("diff out ans -w"))break;
		cout<<i<<endl;
	}
	return 0;
}