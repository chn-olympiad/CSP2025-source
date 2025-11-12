#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5001],ans=0; 
void dfs(long long x,long long k,long long sum)
{
	if(k==x)
	{
		if(sum>a[x]*2)ans=(ans+1)%mod;
		return;
	}
	dfs(x,k+1,sum);
	dfs(x,k+1,sum+a[k]);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)dfs(i,1ll,a[i]);
	cout<<ans%mod;
	return 0;
}