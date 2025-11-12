// rp++
// orz cyh sto

#include <bits/stdc++.h>

using namespace std;

const int M = 1e6 + 1e5 + 10, N = 1e4 + 20, K = 20;
int n, m, k, fa[N], c[K];
struct edge { int u, v, w; } E[M];
bool cmp(edge a, edge b) { return a.w < b.w; }
long long ans = 1e18;

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
long long kruskal(int s)
{
	long long r = 0;
	for (int i = 1;i <= n + k;i++)
		fa[i] = i;
	for (int i = 0;i < k;i++)
		if (s & (1 << i)) r += c[i+1];
	for (int i = 1;i <= m;i++)
	{
		int u = E[i].u, v = E[i].v, w = E[i].w;
		if (u > n && !(s & (1 << (u - n - 1)))) continue;
		int fu = find(u), fv = find(v);
		if (fu == fv) continue;
		fa[fu] = fv, r += w;
		if (r > ans) return 1e18;
	}
	return r;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++)
		cin >> E[i].u >> E[i].v >> E[i].w;
	int ok = 1;
	for (int i = 1;i <= k;i++)
	{
		cin >> c[i]; ok = ok && (c[i] == 0);
		for (int j = 1, x;j <= n;j++)
			cin >> x, E[m + (i - 1) * n + j] = {n + i, j, x};
	}
	m = m + n * k;
	sort(E + 1, E + 1 + m, cmp);
	if (ok == 1) { cout << kruskal((1 << k) - 1) << "\n"; return 0; }
	for (int s = 0;s < (1 << k);s++)
		ans = min(ans, kruskal(s));
	cout << ans << "\n";

	return 0;
}