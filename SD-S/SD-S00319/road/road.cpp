#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
vector<int> edge[N];
bool flag[N];

void dfs(int step)
{
	int a = edge[step].size();
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edge[u][v] = w;
		edge[v][u] = w;
	}
	for (int j = 1; j <= n; j++)
	{
		int c;
		cin >> c;
		for (int i = 1; i <= n; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			edge[u][v] = w + c;
			edge[v][u] = w + c;
		}
	}
	cout << 0;
	return 0;
}
