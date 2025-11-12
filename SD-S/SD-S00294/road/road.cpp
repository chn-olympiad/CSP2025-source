#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 10, maxm = 1e6 + 10, maxk = 20;


struct edge
{
	int u, v, w;
	bool operator<(edge o) const{ return w < o.w; }
}e[maxm + maxn * maxk];

int c[maxk], a[maxk][maxn];

int fa[maxn + maxk];
int find(int u)
{
	if(fa[u] == u)
		return u;
	return fa[u] = find(fa[u]);
}

long long solve1(int n, int m)
{
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	long long ans = 0;
	for(int i = 1; i <= m; i++)
	{
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if(find(u) != find(v))
		{
			fa[find(u)] = find(v);
			ans += w;
		}
	}
	return ans;
}

void solve3(int n, int m, int k)
{
	int fs = (1 << k) - 1;
	long long ans = LONG_LONG_MAX;
	for(int s = 0; s <= fs; s++)
	{
		int l = s, rln = n, cnt = m;
		long long cst = 0;
		for(int i = 1; i <= k; i++, l >>= 1)
			if(l & 2)
			{
				rln++;
				cst += c[i];
				for(int j = 1; j <= n; j++)
					e[++cnt] = {i + n, j, a[i][j]};
			}
		ans = min(ans, solve1(rln, cnt) + cst);
	}
	cout << ans << endl;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e + 1, e + m + 1);
	if(k == 0)
	{
		cout << solve1(n, m) << endl;
		return 0;
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	if(k <= 5)
		solve3(n, m, k);
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

*/
