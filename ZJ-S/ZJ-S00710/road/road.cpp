#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010],b[1000010],c[1000010];
int d[20],e[20][10010];
int n,m,k,minn=INT_MAX,ttt;
bool vis[1000010],gai[20][10010];
vector<int>v[10010],g[10010];
void dfs(int t,int s,int ans)
{
	if(s==n)minn=min(minn,ans);
	if(minn<=ans)return;
	for(int i=0;i<v[t].size();i++)
	{
		int to=v[t][i];
		if(!vis[to])
		{
			vis[to]=1;
			dfs(to,s+1,ans+g[t][i]);
			dfs(t,s+1,ans+g[t][i]);
			vis[to]=0;
		}
	}
}
void dfss(int t,int s,int ans)
{
	if(s==n)minn=min(minn,ans);
	if(minn<=ans)return;
	for(int i=0;i<v[t].size();i++)
	{
		int to=v[t][i];
		if(!vis[to])
		{
			vis[to]=1;
			dfs(to,s+1,ans+g[t][i]);
			dfs(t,s+1,ans+g[t][i]);
			vis[to]=0;
		}
	}
	for(int i=1;i<=k;i++)
	{
		int f=gai[i][0],ff=gai[i][t];
		gai[i][0]=gai[i][t]=1;
		int cc=(1-f)*d[i]+(1-ff)*e[i][t];
		if(ans+cc>=minn)continue;
		ans+=cc;
		for(int j=1;j<=n;j++)
			if(j!=t)
			{
				int fff=gai[i][j];
				gai[i][j]=1;vis[j]=1;
				dfs(j,s+1,ans+(1-fff)*e[i][j]);
				dfs(t,s+1,ans+(1-fff)*e[i][j]);
				gai[i][j]=fff;vis[j]=0;
			}
		ans-=cc;
		gai[i][0]=f;gai[i][t]=ff;
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		v[a[i]].push_back(b[i]);
		g[a[i]].push_back(c[i]);
		v[b[i]].push_back(a[i]);
		g[b[i]].push_back(c[i]);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>d[i];
		for(int j=1;j<=n;j++)
			cin>>e[i][j];
	}
	vis[1]=1;
	dfs(1,1,0);
	cout<<minn;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
