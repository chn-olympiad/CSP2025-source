#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5, M = 1.5e6 + 5;

using i64 = long long;

bool ST;

int n, m, k, p[N], a[N], t[11][N], cnt, len;
struct edge {
	int u, v, w;
} e[M], b[M];

bool ED;

int fifa(int x) { return p[x] == x ? x : p[x] = fifa(p[x]); }

bool cmp(edge x, edge y) { return x.w < y.w; }

int read()
{
	int x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
	return x;
}

void print(i64 x)
{
	if (x >= 10) print(x / 10);
	putchar(x % 10 + '0');
}

i64 kruskal()
{
	for (int i = 1; i <= n + k; i++) p[i] = i;
	sort (b + 1, b + cnt + 1, cmp);
	i64 ans = 0;
	for (int i = 1; i <= cnt; i++) {
		int u = b[i].u, v = b[i].v, w = b[i].w;
		int x = fifa(u), y = fifa(v);
		if (x == y) continue;
		p[x] = y; ans += w;
	}
	return ans; 
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read(), w = read();
		e[i] = { u, v, w };
		b[++cnt] = e[i];
	}
	
	i64 res = 0;
	for (int i = 1; i <= n + k; i++) p[i] = i;
	sort (b + 1, b + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++) {
		int u = b[i].u, v = b[i].v, w = b[i].w;
		int x = fifa(u), y = fifa(v);
		if (x == y) continue;
		p[x] = y; res += w;
		e[++len] = { u, v, w };
	}
	
	for (int i = 0; i < k; i++) {
		a[i] = read();
		for (int j = 1; j <= n; j++)
			t[i][j] = read();
	}
	for (int S = 1; S < (1 << k); S++) {
		i64 ans = 0; cnt = 0;
		for (int i = 1; i < n; i++) b[++cnt] = e[i];
		for (int i = 0; i < k; i++) {
			if (S >> i & 1) {
				ans += a[i];
				for (int j = 1; j <= n; j++)
					b[++cnt] = { i + n + 1, j, t[i][j] };
			}
		}
		ans += kruskal();
		res = min(res, ans);
	}
	print(res);
	return 0;
}

