#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 50, M = 1e6 + 5, K = 3e5 + 5;
int n, m, k, ans, p;
int a[15][N], fa[N], c[N], sz[N];
struct node { int u, v, w; } edge[M], E[K];

int find(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

bool cmp(node x, node y)
{
	return x.w < y.w;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int i, j, st;
	cin >> n >> m >> k;
	
	for(i = 1; i <= m; i++)
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	
	for(i = 1; i <= k; i++)
	{
		cin >> c[i];

		for(j = 1; j <= n; j++)
			cin >> a[i][j];
	}
		
	int cnt = n - 1;
	sort(edge + 1, edge + m + 1, cmp);
	
	for(i = 1; i <= n; i++)
		fa[i] = i;
	
	for(i = 1; i <= m; i++)
	{
		int u = edge[i].u;
		int v = edge[i].v;
		int w = edge[i].w;
		if(find(u) == find(v)) continue;
		ans += w;
		E[++p] = (node){u, v, w};
		fa[find(u)] = find(v);
		if(cnt == 0) break;
	}
	
	for(i = 1; i <= k; i++)
		for(j = 1; j <= n; j++)
			E[++p] = (node){n + i, j, a[i][j]};
	
	sort(E + 1, E + p + 1, cmp);
	
	for(st = 0; st < (1ll << k); st++)
	{
		int sum = 0, cnt = n - 1;
		
		for(i = 1; i <= n + k; i++)
			fa[i] = i, sz[i] = 1;

		for(i = 1; i <= k; i++)
			if(st & (1ll << (i - 1)))
				sum += c[i], cnt++;
		
		for(i = 1; i <= p; i++)
		{
			int u = E[i].u;
			int v = E[i].v;
			int w = E[i].w;
			if(u > n && (st & (1ll << (u - n - 1))) == 0) continue;
			if(v > n && (st & (1ll << (v - n - 1))) == 0) continue;
			u = find(u), v = find(v);
			if(v == u) continue;
			sum += w;
			cnt--;
			if(sz[u] > sz[v]) swap(u, v);
			fa[find(u)] = find(v);
			sz[v] += sz[u];
			if(cnt == 0) break;
		}
		
		ans = min(ans, sum);
	}
	
	cout << ans;
	return 0;
}

//pass all samples at 1h13min