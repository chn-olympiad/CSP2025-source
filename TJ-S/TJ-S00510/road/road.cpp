#include <bits/stdc++.h>
using namespace std;
int fa[11000 + 10];
long long ans;
struct node
{
	int u, v, w;
};
inline bool cmp(node x, node y)
{
	return x.w < y.w;
}
inline int findfa(int x)
{
	if (fa[x] == x)
		return x;
	else
		return fa[x] = findfa(fa[x]);
}
int n, m, k;
node bian[1100000];
int cntbian;
int xiangcun;
void kruskal()
{
	int cnt = 0;
	for (int i = 1; i <= cntbian; i++)
	{
		if (cnt == n)
		{
			break;
		}
		int u = bian[i].u, v = bian[i].v, w = bian[i].w;
		int fu = findfa(u), fv = findfa(v);
		if (fu != fv)
		{
			if (1 <= u && u <= n && 1 <= v && v <= n)
				cnt++;
			fa[fu] = fa[fv];
			ans += w;
			cout << u << " " << v << " " << w << endl;
		}
	}
	cout << ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n + 20; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		bian[++cntbian] = {u, v, w};
	}
	xiangcun = n;
	for (int i = 1; i <= k; i++)
	{
		int a, b;
		cin >> a;
		ans += a;
		xiangcun++;
		for (int j = 1; j <= n; j++)
		{
			cin >> b;
			bian[++cntbian] = {xiangcun, j, b};
			cout << j << " " << b << endl;
		}
	}
	sort(bian + 1, bian + cntbian + 1, cmp);
	kruskal();
	return 0;
}

