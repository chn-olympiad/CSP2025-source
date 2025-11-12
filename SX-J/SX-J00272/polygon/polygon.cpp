#include<bits/stdc++.h>
using namespace std;
long long n,ans;
const long long mod=998244353;
int a[5020];
void dfs(int k,long long maxx,long long sum,long long s)
{
	if(k==n+1)
	{
		if(sum>maxx*2&&s>=3) ans=(ans+1)%mod;
		return;
	}
	dfs(k+1,max(maxx,1ll*a[k]),sum+a[k],s+1);
	dfs(k+1,maxx,sum,s);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld", &n);
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	dfs(1,LLONG_MIN,0,0);
	cout<<ans;
	return 0;
}
