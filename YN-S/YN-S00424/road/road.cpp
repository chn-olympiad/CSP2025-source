// file memory long long
// 14点59分 Finish!

#include <bits/stdc++.h>

using namespace std;

bool st;
struct Edge
{
	int u, v;
	long long w;

	bool operator < (Edge b)
	{
		return w < b.w;
	}
};

struct Tree
{
	int fa[20010];

	void reset()
	{
		for (int i = 0; i <= 20000; i++)
		{
			fa[i] = i;
		}
	}

	int find(int u)
	{
		return fa[u] == u ? u : fa[u] = find(fa[u]);
	}

	void merge(int u, int v)
	{
		fa[find(u)] = find(v);
	}
};

Tree T;
Edge a[1000010], b[1000010], len[1000010];
int c[20];
long long dis[20][20010];
bool en;

int main()
{
//	fprintf(stderr, "%.1lf", (&en - &st) / 1024.0 / 1024.0); // 48.9 MB

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %lld", &a[i].u, &a[i].v, &a[i].w);
	}

	sort(a + 1, a + m + 1);

	int l = 0;

	T.reset();
	for (int i = 1; i <= m; i++)
	{
		if (T.find(a[i].u) != T.find(a[i].v))
		{
			T.merge(a[i].u, a[i].v);
			l++;
			len[l] = a[i];
		}
	}

	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &c[i]);

		for (int j = 1; j <= n; j++)
		{
			scanf("%lld", &dis[i][j]);
		}
	}

	int N = (1 << k) - 1;
	long long res = 1e18;

	for (int S = 0; S <= N; S++)
	{
		long long ans = 0;
		int nowm = l;

		for (int i = 1; i <= l; i++)
		{
			b[i] = len[i];
		}

		for (int i = 1; i <= k; i++)
		{
			if (S & (1 << (i - 1))) // 修城市
			{
				ans += c[i];

				for (int j = 1; j <= n; j++)
				{
					nowm++;
					b[nowm] = {n + i, j, dis[i][j]};
				}
			}
		}

		sort(b + 1, b + nowm + 1);

		T.reset();
		for (int i = 1; i <= nowm; i++)
		{
			if (T.find(b[i].u) != T.find(b[i].v))
			{
				T.merge(b[i].u, b[i].v);
				ans += b[i].w;
			}
		}

		res = min(res, ans);
	}

	printf("%lld", res);

	return 0;
}
