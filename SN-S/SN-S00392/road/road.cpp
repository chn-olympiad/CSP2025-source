// road

#include <bits/stdc++.h>

#define lnt long long
#define pii pair <int, int>

using namespace std;

inline int read()
{
	int val = 0;
	bool si = 0;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) si ^= ch == '-';
	for (;  isdigit(ch); ch = getchar())
		val = (val << 3) + (val << 1) + (ch ^ 48);
	return si == 0 ? val : -val;
}

const int N = 1e4 + 5;
const int M = 1e6 + 5;
const int K = 11;

int n, m, k, t, l;
int c[K];
pii d[K][N];

struct edge
{
	int u, v, w;
	
	friend bool operator < (edge a, edge b)
	{
		return a.w < b.w;
	}
} e[M], g[M + N * K];

int fa[N + K];
int rk[N + K];

int find(int u)
{
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}

inline bool merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v) return 0;
	if (rk[u] < rk[v]) swap(u, v);
	rk[u] += rk[v];
	fa[v] = u;
	return 1;
}

lnt ans, tot;

struct node
{
	int u, i, w;
	
	friend bool operator < (node a, node b)
	{
		return a.w > b.w;
	}
};

priority_queue <node> hep;

inline void init(int s)
{
	l = 0;
	hep.push((node) {0, 1, e[1].w});
	for (int i = 1; i <= n + k; i ++) rk[fa[i] = i] = 1;
	for (int i = 1; i <= k; i ++)
		if (s >> i - 1 & 1)
			hep.push((node) {i, 1, d[i][1].first});
	while (0 == hep.empty())
	{
		node tmp = hep.top(); hep.pop();
		if (tmp.u == 0)
		{
			g[++ l] = e[tmp.i];
			if (tmp.i < t)
				hep.push((node) {0, tmp.i + 1, e[tmp.i + 1].w});
		}
		else
		{
			g[++ l] = (edge) {tmp.u + n, d[tmp.u][tmp.i].second, d[tmp.u][tmp.i].first};
			if (tmp.i < n)
				hep.push((node) {tmp.u, tmp.i + 1, d[tmp.u][tmp.i + 1].first});
		}
	}
}

inline void calc(int s)
{
	lnt res = tot = 0;
	for (int i = 1; i <= k; i ++)
		if (s >> i - 1 & 1)
		{
			res += c[i];
			tot ++;
		}
	tot += n;
	for (int i = 1; i <= l; i ++)
		if (merge(g[i].u, g[i].v))
		{
			res += g[i].w;
			tot --;
			if (res >= ans) return;
			if (tot ==   1) break;
		}
	ans = min(ans, res);
}

int main()
{
	freopen("road.in" , "r", stdin);
	freopen("road.out", "w", stdout);
	
	n = read();
	m = read();
	k = read();
	for (int i = 1; i <= m; i ++)
	{
		g[i].u = read();
		g[i].v = read();
		g[i].w = read();
	}
	for (int i = 1; i <= k; i ++)
	{
		c[i] = read();
		for (int j = 1; j <= n; j ++)
			d[i][j] = make_pair(read(), j);
		sort(d[i] + 1, d[i] + n + 1);
	}
	sort(g + 1, g + m + 1);
	for (int i = 1; i <= n; i ++) rk[fa[i] = i] = 1;
	for (int i = 1; i <= m; i ++)
		if (merge(g[i].u, g[i].v))
		{
			ans += g[i].w;
			e[++ t] = g[i];
		}
	for (int s = 1; s < (1 << k); s ++)
	{
		init(s);
		calc(s);
	}
	printf("%lld\n", ans);
	
	return 0;
}
