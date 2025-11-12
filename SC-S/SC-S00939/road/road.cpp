#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 10015, M = 1100005;

struct Edge
{
	int u, v, w;
} e[M], ee[M];

int n, m, k;
int c[15], a[15][N], fa[N], tmp[N];

bool cmp(Edge x, Edge y)
{
	return x.w < y.w;
}

int find(int x)
{
	return (x == fa[x] ? x : fa[x] = find(fa[x]));
}

int work(int x)
{
	int mm = m, ans = 0, cnt = 0, cntk = 0;
	if (x > 1)
	{
		for (int i = 1; i <= k; i++)
		{
			if ((x >> i) & 1)
			{
				cntk++;
				for (int j = 1; j <= n; j++)
					e[++m] = (Edge){n + cntk, j, a[i][j]};
				ans += c[i], cntk++;
			}
		}
	}
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= n + cntk; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int fu = find(u), fv = find(v);
		if (fu != fv)
		{
			fa[fu] = fv;
			cnt++, ans += w;
			if (cnt == n + cntk - 1) break;
		}
	}
	m = mm;
	for (int i = 1; i <= m; i++)
		e[i] = ee[i];
	return ans;
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= m; i++)
		scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w), ee[i] = e[i];
	bool flag = 0;
	for (int i = 1; i <= k; i++)
	{
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++)
			scanf("%lld", &a[i][j]);
		if (c[i] != 0) flag = 1;
	}
	if (!flag)
	{
		int ans = work((1 << (k + 1)) - 1);
		printf("%lld\n", ans);
	}
	else
	{
		int ans = 1e18;
		for (int i = 1; i < (1 << k); i++)
		{
			int x = work(i);
			ans = min(ans, x);
		}
		printf("%lld\n", ans);
	}
	return 0;
}