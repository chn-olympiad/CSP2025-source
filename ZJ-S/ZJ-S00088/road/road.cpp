#include <bits/stdc++.h>

using namespace std;

#define int long long

int _;
inline int read() {int s = 0, w = 1;char ch = getchar();while (ch < '0' || ch > '9') {if (ch == '-') w *= -1;ch = getchar();}while (ch >= '0' && ch <= '9') {s = (s << 3) + (s << 1) + (ch ^ 48);ch = getchar();}return s * w;}
inline void write(int x) {if (x < 0) x = -x, putchar('-');if (x > 9) write(x / 10);putchar(x % 10 + '0');}

const int N = 1e4 + 5, M = 1e6 + 5;
int n, m, k, t, c[N], a[15][N], pa[N], ans1, s;

struct node {
	int u, v, w;
	bool operator < (const node& o) {
		return w < o.w;
	}
} b[M + 10 * N];

int find(int x) {
	return pa[x] == x ? x : pa[x] = find(pa[x]);
}

inline int kruskal() {
	for (int i = 1; i <= t; ++i) {
		pa[i] = i;
	}
	sort(b + 1, b + m + 1);
	int cnt = 0, ans = 0;
	set<int> f;
	for (int i = 1; i <= m; ++i) {
		int u = find(b[i].u), v = find(b[i].v);
		if (u == v) continue;
		int x = ceil((i - s) * 1.0 / n);
		if (i > s && f.find(x) == f.end()) {
			f.insert(x);
			ans += c[x];
		}
		if (ans > ans1) return 0x3f3f3f3f3f3f3f3f;
		ans += b[i].w;
		if (ans > ans1) return 0x3f3f3f3f3f3f3f3f;
		cnt++;
		pa[u] = v;
		if (cnt == t - 1) {
			return ans;
		}
	}
}

inline void solve() {
	n = read(), m = read(), k = read();
	s = m;
	for (int i = 1; i <= m; ++i) {
		int u = read(), v = read(), w = read();
		b[i] = {u, v, w};
	}
	t = n;
	ans1 = kruskal();
	int id = 1;
	for (int i = 1; i <= k; ++i) {
		c[id] = read();
		t++;
		for (int j = 1; j <= n; ++j) {
			a[i][j] = read();
			b[++m] = {t, j, a[i][j]};
		}
		if (c[id] > ans1) continue;
		int cur = kruskal();
		if (cur < ans1) {
			ans1 = cur;
			id++;
		} else {
			for (int i = m; i >= m - n + 1; --i) {
				b[i] = {0, 0, 0};
			}
			m -= n;
			c[id--] = 0;
		}
	}
	write(ans1);
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	_ = read();
	_ = 1;
	for (int i = 1; i <= _; ++i) solve();
	return 0;
}
