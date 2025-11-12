#include<bits/stdc++.h>
using namespace std;
long long f(long long d)
{
	d%=998244353;
	if(d==0)
	{
		return 1;
	}
	else
	{
		return d*f(d-1);
	}
}
long long c(long long x,long long y)
{
	return f(y)/f(y-x)/f(x);
}
int a[5005],n;
long long r;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>2*(max(a[1],max(a[2],a[3]))))
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		r+=c(i,n);
		r%=998244353;
	}
	cout<<r;
	return 0;
}
