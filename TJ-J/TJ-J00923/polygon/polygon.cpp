#include <bits/stdc++.h>
using namespace std;
int n;
int a[5500];
int dfs(int x,int cnt,int mx,int sum)
{
	if(x==n+1)
	{
		if(cnt<3)
			return 0;
		if(sum<=(mx<<1))
			return 0;
		return 1;
	}
	int ans=0;
	ans+=dfs(x+1,cnt+1,max(mx,a[x]),sum+a[x]);
	ans+=dfs(x+1,cnt,mx,sum);
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int mx=-1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx<=1)
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans<<=1;
			ans%=998244353;
		}
		ans=(ans+998244353-1-n-((n*(n-1))>>1))%998244353;
		cout<<ans;
	}
	else if(n<=22)
		cout<<dfs(1,0,0,0);
	return 0;
}
