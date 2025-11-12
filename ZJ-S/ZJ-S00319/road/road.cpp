#include <bits/stdc++.h>
using namespace std;
struct node
{
	int u, v, w;
};
struct city
{
	int c;
	int a[10005];
}b[15];
int fa[10055];
int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<node> p, t;
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		p.push_back({u, v, w});
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> b[i].c;
		for (int j = 1; j <= n; j++)
			cin >> b[i].a[j];
	}
	long long sum = 1e18;
	for (int s = 0; s < (1 << k); s++)
	{
		int tot = n;
		t = p;
		long long ans = 0, cnt = 0;
		for (int i = 1; i <= k; i++)
		{
			if (s >> (i - 1) & 1)
			{
				for (int j = 1; j <= n; j++)
					t.push_back({n + i, j, b[i].a[j]});
				ans += b[i].c;
				tot++;
			}
		}
		for (int i = 1; i <= n + k; i++)
			fa[i] = i;
		sort(t.begin(), t.end(), [](node a, node b){
			return a.w < b.w;
		});
		for (int i = 0; i < t.size(); i++)
		{
			int u = find(t[i].u);
			int v = find(t[i].v);
			if (u == v)
				continue;
			fa[u] = v;
			ans += t[i].w;
			cnt++;
			if (cnt == tot - 1)
				break;
		}
		sum = min(sum, ans);
	}
	cout << sum;
	return 0;
}
