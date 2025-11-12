#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
#define int long long
int n, m, k;
int g[N][N];
int c[N];
int f[N];
priority_queue<int> q;
int num;
int use[N];
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	memset(g, 0x3f, sizeof(g));
	for(int i = 1;i <= m;i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = min(g[u][v], w);
		g[v][u] = min(g[v][u], w);
	}
	for(int jcr = 1;jcr <= k; jcr++)
	{
		int tmp;
		cin >> tmp;
		for(int j = 1;j <= n;j++)
		{
			cin >> c[j];
		}
		for(int i = 1;i <= n;i++)
			for(int j = 1;j < i;j++)
			{
				int u = i, v = j;
				g[u][v] = min(g[u][v], c[i] + c[j]);
				g[v][u] = min(g[v][u], c[i] + c[j]);
			}
	}
	for(int i = 1; i <= n;i++)
	{
		for(int j = 1;j < i;j++)
		{
			if(i == j)	continue;
			q.push(g[i][j]);
			num++;
			if(num > n - 1)
			{
				q.pop();
				num--;
			}
		}
	}
	int ans = 0;
	while(!q.empty())
	{
		ans += q.top();
		q.pop();
	}
	cout << ans ;
	return 0;
}
/*
1 3
f[find(1)] = find(3);
f[1] = 3
2 1
f[find(2)] = find(1)
f[2] = 3

*/
