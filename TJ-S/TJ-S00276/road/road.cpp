#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define MAXN 10001
using namespace std;
struct node {int to, edge;};
vector<node> a[MAXN], b[MAXN];
int c[11], ans;
bool vis[MAXN];
void dfs(int s)
{
	for (int i = 0; i < a[s].size(); i++)
	{
		if (!vis[a[s][i].to])
		{
			dfs(a[s][i].to);
			vis[a[s][i].to] = true;
			ans += a[s][i].edge;
		}
	}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		a[u].push_back((node){v, w});
		a[v].push_back((node){u, w});
	}
	for (int i = 1; i <= k; i++)
	{ 
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++)
		{
			int x;
			scanf("%d", &x);
			b[i].push_back((node){j, x});
			b[j].push_back((node){i, x});
		}
	} 
	dfs(1);
	printf("%d\n", ans);
	return 0;
}
