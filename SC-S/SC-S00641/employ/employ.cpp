#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,a[505],c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	long long sum=0;
	for(long long i=1;i<=n;i++)
	{
		scanf("%1lld",&a[i]);
		if(a[i]==1)
		{
			sum++;
		}
	}
	long long ss=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]!=0)
		{
			ss++;
		}
	}
	if(ss<m)
	{
		cout<<0;
		return 0;
	}
	if(n<=18)
	{
		long long p[20];
		for(long long i=1;i<=n;i++) p[i]=i;
		long long ans=0;
		do
		{
			long long sum=0,cnt=0;
			for(long long i=1;i<=n;i++)
			{
				if(sum>=c[p[i]])
				{
					sum++;
					continue;
				}
				if(a[i]==0)
				{
					sum++;
					continue;
				}
				cnt++;
			}
			if(cnt>=m)
			{
				ans=ans%mod;
				ans++;
			}
		}
		while(next_permutation(p+1,p+n+1));
		cout<<ans;
		return 0;
	}
	if(m==n&&sum==n)
	{
		long long x=1;
		for(long long i=1;i<=n;i++)
		{
			x*=i;
			x=x%mod;
		}
		cout<<x;
		return 0;
	}
	cout<<0;
	return 0;
}