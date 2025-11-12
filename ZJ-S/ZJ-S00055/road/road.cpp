#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
int n, m, k;
int u, v, w;
int fa[N];
int ans;
struct EDGE
{
	int u, v, w;
}edge[4 * N];
EDGE e[4 * N];
int idx, h[N];
int c;
int maxx = 1e9;

void clean ()
{
	for (int i = 1;i <= n + 50; i ++)
	{
		fa[i] = i;
	}
}

int find (int x)
{
	if (fa[x] != x) return fa[x] = find (fa[x]);
	return x;
}

bool cmp (EDGE x, EDGE y)
{
	return x.w < y.w ;
}

int kur(int idx ,int ans)
{
	sort (edge + 1, edge + 1 + idx, cmp);
	for (int i = 1;i <= idx; i ++)
	{
		int u = find (edge[i].u);
		int v = find (edge[i].v);
		if (u == v) continue;
		fa[v] = fa[u];
		ans += edge[i].w ;
	}
	return ans;
}

void init ()
{
	cin >> n >> m >> k;
	for (int i = 1;i <= m; i ++)
	{
		cin >> u >> v >> w;
		edge[++ idx] = (EDGE) {u, v, w};
	}
	clean();
	int ks = idx;
	for (int i = 1;i <= idx; i ++)	e[i] = edge[i];	
	maxx = min(kur(idx, 0), maxx);
	for (int i = 1;i <= k; i ++)
	{
		clean();
		idx = ks;
		for (int j = 1;j <= idx; j ++) edge[i] = e[i]; 
		cin >> ans;
		for (int j = 1;j <= n; j ++)
		{
			cin >> c;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	init();
	cout << maxx;
	return 0;
}
