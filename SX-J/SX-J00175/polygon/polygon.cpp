#include <bits/stdc++.h>
using namespace std;
long long n,a[5010],f[20010],maxa,ans,out=1,sm[5010];
const long long mo=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		maxa=max(maxa,a[i]);
	}
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=maxa;j>=a[i];j--)
		{
			f[j]+=f[j-a[i]];
			f[j]%=mo;
		}
	}
	for(int i=2;i<=maxa;i++)
	{
		f[i]+=f[i-1];
		f[i]%=mo;
	}
	for(int i=1;i<=n;i++)
	{
		sm[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		ans+=f[a[i]]-sm[a[i]];
		ans%=mo;
	}
	for(int i=1;i<=n;i++)
	{
		out*=2;
		out%=mo;
	}
	out-=1;
	out=(out+2*mo)%mo;
	out-=n;
	out=(out+2*mo)%mo;
	out-=(n*(n-1)/2)%mo;
	out=(out+2*mo)%mo;
	printf("%lld",(out-ans+2*mo)%mo);
	return 0;
}