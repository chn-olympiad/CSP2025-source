#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,a[505],vis[505],ord[505];
string s;
void dfs(int dep)
{
	if(dep==n+1)
	{
		int sum=0,out=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='1'&&out<a[ord[i]])
				sum++;
			else
				out++;
		}
		if(sum>=m)
		{
			ans=(ans+1)%998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		ord[dep]=i;
		dfs(dep+1);
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
