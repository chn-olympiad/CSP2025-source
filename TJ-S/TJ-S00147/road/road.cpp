#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct edge
{
	int to, w;
};
int n, m, k, ans, c[15], a[15][10005];
vector<edge> g[10005];

void dfs(int step, int cost)
{
	if(cost > ans) return ;
	if(step == n)
	{
		ans = min(ans, cost);
		return ;
	}
	for(int i = 0; i < g[step].size(); i++)
	{
		edge nxt = g[step][i];
		int to = nxt.to, w = nxt.w;
		dfs(to, cost + w);
	}
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int u, v, p;
		cin >> u >> v >> p;
		g[u].push_back({v, p});
		g[v].push_back({u, p});
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	if(k == 0)
	{
		ans = 2e9;
		dfs(1, 0);
		cout << ans << endl;
		return 0;
	}
	
	
	return 0;
}
