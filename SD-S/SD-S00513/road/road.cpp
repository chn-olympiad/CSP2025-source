#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e4 + 10;

struct node { int u, v, w; };

int n, m, K, cnt;

ll answer = 1e16;

int fa[N], a[20][N];

vector<node> to, edge;

bool cmp(node x, node y)
{
	return x.w < y.w;
}

int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> K;
	for (int i = 1, u, v, w; i <= m; i++)
	{
		cin >> u >> v >> w;
		edge.push_back({u, v, w});
		edge.push_back({v, u, w});
	}
	for (int i = 0; i < K; i++)
		for (int j = 0; j <= n; j++) cin >> a[i][j];
	sort(edge.begin(), edge.end(), cmp);
	
	for (int i = 1; i <= n; i++) fa[i] = i;
	cnt = n;
	for (auto i : edge)
	{
		int u = i.u, v = i.v, w = i.w;
		if (find(u) == find(v)) continue;
		fa[find(u)] = find(v);
		to.push_back({u, v, w});
	}
	edge = to;
	
	for (int i = 0; i < (2 << K); i++)
	{
		ll ans = 0;
		to = edge;
		for (int i = 1; i <= n + K; i++) fa[i] = i;
		cnt = n;
		
		for (int u = 0; u < K; u++)
		{
			if (((1 << u) & i) == 0) continue;
			
			cnt++;
			ans += a[u][0];
			
			for (int v = 1; v <= n; v++)
			{
				int w = a[u][v];
				if (w > edge.back().w) continue;
				to.push_back({u + n + 1, v, w});
				to.push_back({v, u + n + 1, w});
			}
		}
		sort(to.begin(), to.end(), cmp);
		for (auto j : to)
		{
			if (cnt == 1) break;
			int u = j.u, v = j.v, w = j.w;
			if (find(u) == find(v)) continue;
			ans += w;
			cnt--;
			fa[find(u)] = find(v);
		}
		answer = min(answer, ans);
	}
	cout << answer;
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

13
*/
