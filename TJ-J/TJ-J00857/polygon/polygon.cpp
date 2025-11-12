#include <bits/stdc++.h>
using namespace std;
int a[5005],num[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,amax=-1;
	bool ifa1=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		num[a[i]]++;
		if(a[i]>amax)
		{
			amax=a[i];
		}
		if(a[i]!=1)
		{
			ifa1=0;
		}
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>2*amax)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	if(ifa1)
	{
		cout<<(n-1)*(n-2)/2%998244353;
		return 0;
	}
	return 0;
 } 
