#include<bits/stdc++.h>
using namespace std;
int n,a[10000];
int main()
{
	std::ifstream cin("polygon.in");
	std::ofstream cout("polygon.out");
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		if(a[1]+a[2]>a[3] and a[1]+a[3]>a[2] and a[3]+a[2]>a[1])
		{
			cout<<"1";
		}
		else
		cout<<"0";
	}
	return 0;
 } 
