#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500010],f[500010],ans,amax;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		amax=max(amax,a[i]);
	}
	if(amax<=1 && n>1000)
	{
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					ans++;
				}
				if(a[i]==1 && a[i-1]==1 && f[i-1]==0 && i>1)
				{
					ans++;
					f[i]=1;
				}
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					ans++;
				}
			}
		}
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		if(a[i]==k)
		{
			f[i]++;
		}
		else
		{
			long long xo=a[i];
			for(int j=i-1;j>=1;j--)
			{
				xo^=a[j];
				if(xo==k)
				{
					f[i]=max(f[i],f[j-1]+1);
				}
			}
		}
		ans=max(f[i],ans);
	}
	printf("%lld",ans);
	return 0;
}