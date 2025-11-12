#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int G[10005][10005];
int K[11];
int N[10005];
bool a[10005][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			G[i][j] = INT_MAX;
		}
	}
	for(int i = 1;i <= n;i++)
		G[i][i] = 0;
	for(int i = 1;i <= m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		G[u][v] = w;
		G[v][u] = w;
	}
	for(int i = 1;i <= k;i++)
	{
		cin >> K[i];
		for(int j = 1;j <= n;j++)
		{
			cin >> G[n + j][j];
			G[j][j + n] = G[n + j][j];
		}
	}
	int cnt2 = 1;
	for(int i = 1;i<=n;i++)
	{
		int cnt = 0,x;
		for(int j = 1;j <= n;j++)
		{
			if(G[i][j] != 0 && G[i][j] != INT_MAX)
			{
				cnt++;
				x = j;
			}
		}
		if(cnt == 1)
		{
			ans += G[i][x];
			cnt2++;
			a[i][j] = a[j][i] = 1;
		}
			
		
	}
	return 0;
}
