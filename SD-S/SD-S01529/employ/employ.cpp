#include<bits/stdc++.h>

using namespace std;

int nowx[15],c[15],n,m,ans=0;
bool vis[15];string s;
void dfs(int u)
{
	if(u>=n)
	{
		int t=0,num=0;
		for(int i=1;i<=n;++i)
			if(t>=c[nowx[i]]||s[i-1]=='0') t++;
			else num++;
		if(num>=m) ans++;
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(vis[i]) continue;vis[i]=1;
		nowx[u+1]=i;dfs(u+1);vis[i]=0;
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i) cin>>c[i];
	dfs(0);cout<<ans;
	return 0;
}
