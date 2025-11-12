#include <iostream>
#include <algorithm>
using namespace std;
const int V = 10000;
const int E = 1000000;
struct Edge
{
	int u, v, w;
	bool operator<(const Edge & oth) const
	{
		return w < oth.w;
	}
} Graph[E + 10 * V + 21];
int Label[E + 10 * V + 21];
int Cost[14];
int Res[1025][V + 10 + 14];
long long Ans[1025];
int Temp[2 * V + 15];
namespace DSU
{
	int Par[V + 14];
	int Siz[V + 14];
	void Reset(int n)
	{
		for (int i = 1; i <= n; i++)
		{
			Par[i] = i;
			Siz[i] = 1;
		}
	}
	int Find(int u)
	{
		return Par[u] = (u == Par[u] ? u : Find(Par[u]));
	}
	bool Merge(int u, int v)
	{
		u = Find(u), v = Find(v);
		if (u == v) return false;
		if (Siz[u] < Siz[v]) swap(u, v);
		Par[v] = u;
		Siz[u] += Siz[v];
		return true;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	using namespace DSU;
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> Graph[i].u >> Graph[i].v >> Graph[i].w;
	for (int i = 1; i <= k; i++)
	{
		cin >> Cost[i];
		for (int j = 1, w; j <= n; j++)
		{
			cin >> w;
			Graph[m + (i - 1) * n + j] = {n + i, j, w};
		}
	}
	sort(Graph + 1, Graph + m + 1);
	for (int i = 1; i <= k; i++)
		sort(Graph + m + (i - 1) * n + 1, Graph + m + i * n + 1);
	for (int i = 1; i <= m + k * n; i++) Label[i] = i;
	Reset(n + k);
	for (int i = 1; Res[0][0] < n - 1 && i <= m; i++)
	{
		int u = Graph[i].u, v = Graph[i].v, w = Graph[i].w;
		if (!Merge(u, v)) continue;
		Ans[0] += w;
		Res[0][++Res[0][0]] = i;
	}
	long long ans = Ans[0];
	for (int S = 1; S < 1 << k; S++)
	{
		int pc = 0;
		for (int i = 0; i < k; i++)
			if (S >> i & 1)
			{
				Ans[S] += Cost[i + 1];
				pc++;
			}
		int l = S & -S;
		int x = __lg(l) + 1;
		merge(Res[S - l] + 1, Res[S - l] + Res[S - l][0] + 1, Label + m + (x - 1) * n + 1, Label + m + x * n + 1, Temp + 1, [](int a, int b){ return Graph[a] < Graph[b]; });
		Reset(n + k);
		for (int i = 1; Res[S][0] < n + pc - 1 && i <= Res[S - l][0] + n; i++)
		{
			int u = Graph[Temp[i]].u, v = Graph[Temp[i]].v, w = Graph[Temp[i]].w;
			if (!Merge(u, v)) continue;
			Ans[S] += w;
			Res[S][++Res[S][0]] = Temp[i];
		}
		ans = min(ans, Ans[S]);
	}
	cout << ans;
	return 0;
}
