#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+15, M = 2.2e6+5;

int n, m, k, c[12], a[12][N];
int fa[N];
struct rd_t {
	int u, v, w;
} rd[M];

bool cmp1(rd_t a, rd_t b) {
	return a.w < b.w;
}

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while ('0' <= c && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * f;
}

int find_set(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find_set(fa[x]);
}

ll kruskal() {
	ll ans = 0;
	sort(rd + 1, rd + m + 1, cmp1);
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	for (int i = 1; i <= m; ++i) {
		int a = find_set(rd[i].u);
		int b = find_set(rd[i].v);
		if (a == b) continue;
		fa[a] = b;
		ans += rd[i].w;
	}
	return ans;
}

void solve1() {
	ll ans = kruskal();
	printf("%lld\n", ans);
}

void solve2() {
	for (int j = 1; j <= k; ++j) {
		for (int i = 1; i <= n; ++i) {
			++m;
			rd[m].u = n + j;
			rd[m].v = i;
			rd[m].w = a[j][i];
		}
	}
	n += k;
	ll ans = kruskal();
	printf("%lld\n", ans);
}

void solve3() {
	int kk = 1 << k;
	ll ans = 1e18+7;
	int om = m, on = n;
	for (int p = 0; p < kk; ++p) {
		int t = p; ll tmp = 0;
		int cnt = 0;
		for (int j = 1; j <= k; ++j) {
			if (t & 1) {
				++cnt;
				for (int i = 1; i <= n; ++i) {
					++m;
					rd[m].u = n + cnt;
					rd[m].v = i;
					rd[m].w = a[j][i];
				}
				++n;
				tmp += c[j];
			}
			t >>= 1;
		}
		ans = min(ans, kruskal() + tmp);
		m = om; n = on;
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; ++i) {
		rd[i].u = read();
		rd[i].v = read();
		rd[i].w = read();
	}
	if (k == 0) {
		solve1();
	} else {
		bool all_zero = true;
		for (int j = 1; j <= k; ++j) {
			c[j] = read();
			if (c[j] != 0)
				all_zero = false;
			for (int i = 1; i <= n; ++i) {
				a[j][i] = read();
			}
		}
		if (all_zero) {
			solve2();
		} else {
			solve3();
		}
	}
	return 0;
}
