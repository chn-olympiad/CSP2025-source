#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],sum;
long long ans,f[5005],k[5005],d[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		memset(d,0,sizeof(d));
		for(int j=sum;j>=a[i];j--)
		{
			d[0]=(d[0]+f[j-a[i]]-f[j-a[i]+1])%mod;
			d[j+1]=(d[j+1]-f[j-a[i]]+f[j-a[i]+1])%mod;
		}
		memset(k,0,sizeof(k));
		k[0]=d[0];
		for(int j=1;j<=sum;j++)
			k[j]=(k[j-1]+d[j])%mod;
		for(int j=0;j<=sum;j++)
			f[j]=(f[j]+k[j])%mod;
		if(i>1&&i<n)ans=(ans+f[a[i+1]+1])%mod;
	}
	printf("%d",ans);
	return 0;
}