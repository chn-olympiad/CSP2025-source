#include <bits/stdc++.h>
using namespace std;
int n,a[5005],all,type;
long long ans;
const long long mod=998244353;
bool cmp(int a,int b)
{
	return a>b;
}
int vis[5005];
void dfs(int tot,int sum,int maxn,int step)
{
	
	if(sum>maxn*2&&tot>=3)
	{
		ans=(ans+1)%mod;
	}
		
	if(all<=maxn*2)
		return ;
	for(int i=step+1;i<=n;i++)
	{
		if(vis[i]==1)
			continue;
		vis[i]=1;
		dfs(tot+1,sum+a[i],max(maxn,a[i]),i);
		vis[i]=0;
	}
}
int z[5005][5005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],all+=a[i];
	type=2;
	for(int i=1;i<=n;i++)
		if(a[i]>1)
			type=1;
	if(type==1)
	{
		sort(a+1,a+n+1);
		dfs(0,0,0,0);
	}
	else
	{
		for(int i=1;i<=n;i++)
			z[i][1]=z[i][i]=1;
		for(int i=1;i<=n+1;i++)
			for(int j=2;j<=i;j++)
				z[i][j]=(z[i-1][j]+z[i-1][j-1])%mod;
		for(int i=3;i<=n;i++)
			ans=(ans+z[n+1][i+1])%mod;
	}
	cout<<ans;
	return 0;
}
