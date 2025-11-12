#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
int a[5001],sum[5001];
int main()
{
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	long long ans=0;
	for(int i=3;i<=n;i++)
	{
		if(sum[i]/2>a[i])ans++;
		for(int j=0;j<=i-1;j++)
		{
			for(int k=j+1;k<=i;k++)
			{
				if((sum[i]-(sum[k]-sum[j]))/2>a[i])
				{
					ans++;
				}
			}
		}
		ans%=Mod;
	}
	cout<<ans;
	return 0;
}

