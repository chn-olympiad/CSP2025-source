#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,a[10000];
int main()
{
	std::ifstream cin("seat.in");
	std::ofstream cout("seat.out");
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	if(n==1 and m<=10)
	{
		int x=0;
		for(int i=1;i<=n*m;i++)
		{
			for(int s=1;s<=n*m;s++)
			{
				if(a[s]>x) x=a[s];
			}
			if(x==a[1])
			cout<<i<<" 1";
			for(int j=1;j<=n*m;j++)
			{
				if(x==a[j]) a[j]=0;
			}
			x=0;
		}
	}
	else if(n<=10 and m==1)
	{
		int x=0;
		for(int i=1;i<=n*m;i++)
		{
			for(int s=1;s<=n*m;s++)
			{
				if(a[s]>x) x=a[s];
			}
			if(x==a[1])
			cout<<"1 "<<i;
			for(int j=1;j<=n*m;j++)
			{
				if(x==a[j]) a[j]=0;
			}
			x=0;
		}
	}
	return 0;
 } 
