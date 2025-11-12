#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long sum[5005];
long long f[5000*5000+5];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0;
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=sum[i-1]+a[i];j>=a[i];j--)
		{
			if(f[j-a[i]]>0)
			{
				f[j]=(f[j]+f[j-a[i]])%998244353;
				if(j-a[i]>a[i]) ans=(ans+f[j-a[i]])%998244353;
			}
		}
	}
	cout<<ans;
}