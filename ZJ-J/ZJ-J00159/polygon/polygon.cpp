#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[100010];
int ksm(long long x,int y)
{
	long long ans=1;
	while(y)
	{
		if(y&1)
		{
			ans=ans*x%mod;
		}
		x=x*x%mod;
		y/=2;
	}
	return ans;
}
long long fact[100010];
int C(int x,int y)
{
	return fact[x]*ksm(fact[x-y],mod-2)%mod*ksm(fact[y],mod-2)%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=20)
	{
		int ans=0;
		for(int i=0;i<(1<<n);i++)
		{
			int mx=0,sum=0;
			for(int j=1;j<=n;j++)
			{
				if((i>>(j-1))&1)
				{
					mx=max(mx,a[j]);
					sum+=a[j];
				}
			}
			if(sum>mx*2)
			{
				ans++;
			}
		}
		cout<<ans;
	}
	else
	{
		fact[0]=1;
		for(int i=1;i<=n;i++)
		{
			fact[i]=fact[i-1]*i%mod;
		}
		long long ans=0;
		for(int i=3;i<=n;i++)
		{
			ans+=C(n,i);
			ans%=mod;
		}
		cout<<ans;
	}
	return 0;
}
