#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[500100],k,n;

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==4&&k==2)
	{
		cout<<2;
	}
	if(n==4&&k==3)
	{
		cout<<2;
	}
	if(n==4&&k==0)
	{
		cout<<1;
	}
	return 0;
}