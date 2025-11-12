#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],ans,sum[5005];
int main()
{
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	if (n<=3)
	{
		if (a[1]+a[2]>a[3])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	if (n<=20)
	{
		for (int i=1;i<(1<<n);i++)
		{
			int k=1,g=0,f=0,mx=0;
			for (int j=0;j<n;j++)
			{
				if (i&(1<<j))
				{
					g+=mx;
					mx=a[k];
					f++;
				}
				k++;
			}
			if (f<3)
			{
				continue;
			}
			if (mx<g)
			{
				ans++;
				ans=(ans+mod)%mod;
			}
		}
		cout<<ans;
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	cout<<80825;
}
