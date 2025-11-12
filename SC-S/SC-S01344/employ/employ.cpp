#include<bits/stdc++.h>
using namespace std;
int n,m;
int p[510],c[510],vis[510],ans;
string s;
void dfs(int now)
{
	if(now==n)
	{
		int cnt=0,ct=0;
		for(int i=0;i<(int)s.size();i++)
		{
			if(s[i]=='0' || c[p[i]]<=cnt) cnt++;
			else ct++;
		}
		if(ct>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			p[now]=i;
			vis[i]=1;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(0);
	cout<<ans<<endl;
	return 0;
}

