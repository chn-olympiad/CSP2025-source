#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e4 + 5;
const int maxM = 3e6 + 5;
struct edge
{
	int u, v;
	ll w;
} edges[maxM];
int n, m, k, cnt, m_cnt, fa[maxN];
ll ans, c[15];
bool cmp(edge a, edge b)
{
	return a.w < b.w;
}
int find_set(int x)
{
	if (x == fa[x]) { return x; }
	else { return fa[x] = find_set(fa[x]); }
}
void merge_set(int x, int y)
{
	fa[find_set(y)] = find_set(x);
}
void addedge(int u, int v, ll w)
{
	m_cnt++;
	edges[m_cnt].u = u;
	edges[m_cnt].v = v;
	edges[m_cnt].w = w;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) { fa[i] = i; }
	for (int i = 1; i <= m; i++)
	{
		int u = 0, v = 0;
		ll w = 0;
		scanf("%d %d %lld", &u, &v, &w);
		addedge(u, v, w);
		addedge(v, u, w);
	}
	for (int i = 1; i <= k; i++)
	{
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++)
		{
			ll w = 0;
			scanf("%lld", &w);
			addedge(i, j, w);
			addedge(j, i, w);
		}
	}
	sort(edges + 1, edges + m_cnt + 1, cmp);
	for (int i = 1; i <= m_cnt; i++)
	{
		if (cnt == n - 1) { break; }
		if (find_set(edges[i].u) != find_set(edges[i].v))
		{
			merge_set(edges[i].u, edges[i].v);
			ans += edges[i].w;
			cnt++;
		}
	}
	printf("%lld", ans);
	return 0;
}
