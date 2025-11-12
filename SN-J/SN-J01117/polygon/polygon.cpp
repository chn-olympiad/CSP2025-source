#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,k,a[50005ll];
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		int maxx=max(a[1],max(a[2],a[3]))*2;
		int b=a[1]+a[2],c=a[3]+a[2],d=a[1]+a[3];
		if(b>maxx or c>maxx or d>maxx)
			cout<<1;
		else
			cout<<0;
	}
	return 0;
}
