#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MX = 1e4 + 10;
int G[MX][MX];
int m,n,k;
int c[20],a[10][MX],ans = INT_MAX; 
bool vis[MX];
void dfs(int x,int sum,int step)
{
	for(int i = 1;i <= n;i++)
	{
		if(vis[i] == 0 && G[i][x] >= 0)
		{
			vis[i] = 1;
			dfs(i,sum + G[i][x],step + 1);
			vis[i] = 0;
		}
	}
	if(step == 3)
	{
		ans = min(ans,sum);
	}
	
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i,j;
	cin >> n >> m >> k;
	memset(G,-1,sizeof(G));
	for(i = 1;i <= n;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		G[u][v] = G[v][u] = w;
	}
	for(i = 1;i <= k;i++)
	{
		cin >> c[i];
		for(j = 1;j <= n;j++)
		{
			memset(vis,0,sizeof(vis));
			cin >> a[i][j];
		}
	}
	if(k == 0)
	{
		for(i = 1;i <= n;i++)
		{
			dfs(i,0,0);
		}
		cout << ans << '\n';
		return 0;
	}
	cout << "0" << '\n';
	return 0;
}
