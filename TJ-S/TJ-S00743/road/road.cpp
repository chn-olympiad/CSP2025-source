#include<bits/stdc++.h>

#define int long long

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 8
100 1 3 2 4
*/


using namespace std;

const int N = 1e4 + 20, M = 1e6 + 50;

struct edge
{
	int u, v, w;
	bool operator < (edge other) const 
	{
		return w < other.w;
	}
};

vector<edge> g;
bool vis[M], vis2[20];
int n, m, k;
int pa[N];
int c[20];

int find(int x)
{
	return (pa[x] == x ? x : pa[x] = find(pa[x]));
}

bool unite(int x, int y)
{
	int rootx = find(x);
	int rooty = find(y);
	if(rootx == rooty) return false;
	else
	{
		pa[x] = pa[y];
		return true;
	}
}

int kruskal()
{
	int res = 0, cnt = 0;
	for(int i = 1; i <= n; i++) pa[i] = i;
	sort(g.begin(), g.end());
//	for(auto &e : g)
//	{
//		if(vis[e.u] || vis[e.v]) continue;
//		if(unite(e.u, e.v))
//		{
//			vis[e.u] = vis[e.v] = 1;
//			res += e.w;
//			cnt++;
//		}
//	}
	int glen = g.size();
	for(int i = 0; i < glen && cnt <= n - 1; i++)
	{
		if(vis[g[i].u] || vis[g[i].v]) continue;
		if(unite(g[i].u, g[i].v))
		{
			if(g[i].u >= n + 1 && g[i].u <= n + k && !vis[g[i].u - n])
			{
				res += c[g[i].u - n];
				vis2[g[i].u - n] = 1;
			}
			res += g[i].w;
			cnt++;
			vis[g[i].u] = vis[g[i].v] = 1;
		}
	}
	return res;
}

signed main()
{
	memset(vis, 0, sizeof vis);
	memset(vis2, 0, sizeof vis2);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	int i;
	for(i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g.push_back({u, v, w});
		g.push_back({v, u, w});
	}
	for(i = n + 1; i <= n + k; i++)
	{
		cin >> c[i - n];
		for(int j = 1; j <= n; j++)
		{
			int t;
			cin >> t;
			g.push_back({i, j, t});
		}
	}
	int res = kruskal();
	cout << res;
} 
