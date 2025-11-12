#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL, int> PLI;
const int N = 10050, M = 2000010;

int n, m, k, cnt;
int w[15];
int f[N], sz[N];
int st[M];
struct Edge
{
	int a, b, c;
	bool operator < (const Edge &W) const
	{
		return c < W.c;
	}
}e[M];

int find(int x)
{
	return x == f[x] ? x : f[x] = find(f[x]);
}

LL kruskal(int state)
{
	LL res = 0;
	for (int i = 1; i <= n + k; i ++ ) f[i] = i, sz[i] = 1;
	for (int i = 1; i <= cnt; i ++ )
	{
		int a = e[i].a, b = e[i].b, c = e[i].c;
		if (b > n)
		{
			if (!(state >> (b - n - 1) & 1)) continue;
		}
		if (find(a) != find(b))
		{
			res += c;
			if (sz[a] < sz[b]) f[find(a)] = find(b), sz[find(b)] += sz[find(a)];
			else f[find(b)] = find(a), sz[find(a)] += sz[find(b)];
		}
	}
	for (int i = 0; i < k; i ++ )
		if (state >> i & 1)
			res += w[i + 1];
	return res;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i ++ )
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		e[ ++ cnt] = {a, b, c};
	}
	
	for (int i = 1; i <= k; i ++ )
	{
		scanf("%d", &w[i]);
		for (int j = 1; j <= n; j ++ )
		{
			int x;
			scanf("%d", &x);
			e[ ++ cnt] = {j, n + i, x};
		}
	}
	
	sort(e + 1, e + cnt + 1);
	
	for (int i = 1; i <= n; i ++ ) f[i] = i, sz[i] = 1;
	for (int i = 1; i <= cnt; i ++ )
	{
		int a = e[i].a, b = e[i].b, c = e[i].c;
		if (b > n)
		{
			st[i] = true;
			continue;
		}
		if (find(a) != find(b))
		{
			st[i] = true;
			if (sz[a] < sz[b]) f[find(a)] = find(b), sz[find(b)] += sz[find(a)];
			else f[find(b)] = find(a), sz[find(a)] += sz[find(b)];
		}
	}
	
	int ncnt = 0;
	for (int i = 1; i <= cnt; i ++ )
	{
		if (st[i]) e[ ++ ncnt] = e[i];
	}
	cnt = ncnt;
		
	LL res = 1e18;
	for (int i = 0; i < (1 << k); i ++ )
	{
		res = min(res, kruskal(i));
	}
	
	printf("%lld\n", res);
	
	return 0;
}
