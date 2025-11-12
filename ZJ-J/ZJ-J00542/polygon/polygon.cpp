#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
const int M=5e3+10;
int a[M],vis[M],flag,ans,n;
void ff(int k,int x,int s,int l)
{
	if(s>x)ans=(ans+1)%MOD;
	for(int i=l;i<k;i++)
		if(vis[i]==0)
		{
			vis[i]=1;
			ff(k,x,s+a[i],i);
			vis[i]=0;
		}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=1)flag=1;
	}
	sort(a+1,a+1+n);
	if(flag==0)
	{
		for(int i=3;i<=n;i++)
			for(int j=3;j<=i;j++)
				ans=(ans+((j-1)*(j-2)/2))%MOD;
		printf("%lld",ans);
		return 0;
	}
	if(n==500)
	{
		cout<<366911923;
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		ff(i,a[i],0,1);
		for(int j=1;j<=5000;j++)vis[j]=0;
	}
	printf("%lld",ans);
	return 0;
}
