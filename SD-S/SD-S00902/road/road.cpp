#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;
#define int long long
int read()
{
	int res = 0, f = 1;
	char s = getchar();
	while (s < '0' || s > '9')
	{
		if (s == '-') f = -1;
		s = getchar();
	}
	while ('0' <= s && s <= '9')
	{
		res = (res << 1) + (res << 3) + (s ^ 48);
		s = getchar();
	}
	return res * f;
}
void write(int v)
{
	if (v < 10)
	{
		putchar(v + '0');
		return ;
	}
	write(v / 10);
	putchar(v % 10 + '0');
}
void wt(int v, bool f = 1)
{
	if (v < 0) putchar('-'), v = -v;
	write(v);
	putchar(f ? '\n' : ' ');
}
#define rd read()

const int N = 1e4 + 10;
const int M = 1e6 + 10;
const int K = 15;
const int MOD = 1e9 + 7;
const int Fill = 0x3f3f3f3f;
const int INF = 0x7fffffffffffffff;

int n, m, k;
int ans, edgetot;
int fa[N + K], c[K], a[K][N];
struct edge
{
	int u, v, w;
	bool operator<(const edge &t) const {
		return w < t.w;
	}
}e1[M], e[N * K + M];
int fd(int x)
{
	return fa[x] = fa[x] == x ? x : fd(fa[x]);
}
bool uni(int x, int y)
{
	x = fd(x), y = fd(y);
	if (x == y) return 0;
	fa[x] = y;
	return 1;
}
int calc(int S)
{
	int res = 0;
	int i, j;
	int tot = edgetot;
	int cnt = n;
	for (i = 1; i <= n + k; i++)
	{
		fa[i] = i;
	}
	for (i = 1; i <= n - 1; i++)
	{
		e[i] = e1[i];
	}
	for (i = 1; i <= k; i++)
	{
		if (((1ll << (i - 1ll)) & S) == 0)
		{
			continue;
		}
		cnt++;
		res += c[i];
		for (j = 1; j <= n; j++)
		{
			e[++tot] = {n + i, j, a[i][j]};
		}
	}
	sort(e + 1, e + tot + 1);
	int cnt1 = 0;
	for (i = 1; i <= tot; i++)
	{
		if (uni(e[i].u, e[i].v))
		{
			cnt1++;
			res += e[i].w;
		}
		if (cnt1 == cnt - 1) break;
	}
	return res;
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int i, j;
	n = rd, m = rd, k = rd;
	for (i = 1; i <= m; i++)
	{
		if (i <= n + k) fa[i] = i;
		e1[i].u = rd, e1[i].v = rd, e1[i].w = rd;
	}
	sort(e1 + 1, e1 + m + 1);
	for (i = 1; i <= m; i++)
	{
		if (uni(e1[i].u, e1[i].v))
		{
			edgetot++;
			e1[edgetot] = e1[i];
			ans += e1[i].w;
		}
		if (edgetot == n - 1) break;
	}
	for (i = 1; i <= k; i++)
	{
		c[i] = rd;
		for (j = 1; j <= n; j++)
		{
			a[i][j] = rd;
		}
	}
	for (i = 1; i < (1ll << k); i++)
	{
		ans = min(ans, calc(i));
	}
	wt(ans);
	return 0;
}

