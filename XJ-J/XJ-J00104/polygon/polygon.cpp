#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],maxn=0;
long long ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(n==2)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))) cout<<1;
		else cout<<0;
		return 0;
	}
	long long ans=0;
	for(int i=3;i<=n;i++)
	{
		long long la=1,lb=1;
		for(int j=1;j<=i;j++)
		{
			la*=n-j+1;
			la%=998244353;
			lb*=j;
			lb%=998244353;
		}
		ans+=(la/lb)%998244353;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
} 
