#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[15][10010];
int f[10050];
long long ans = INT64_MAX;

struct edge {
	int u, v, w;
	operator<(const edge &rhs) {
		return w < rhs.w;
	}
} c[1000005], b[1100005];

int find(int x) {
	if (f[x] == x)
		return x;
	return f[x] = find(f[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cout.tie(nullptr), cin.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i)
		cin >> c[i].u >> c[i].v >> c[i].w;
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j <= n; ++j)
			cin >> a[i][j];
	}
	for (int i = 0; i < (1 << k); ++i) {
		long long ret = 0;
		for (int j = 1; j <= n + k; ++j)
			f[j] = j;
		for (int j = 1; j <= m; ++j) {
			b[j].u = c[j].u;
			b[j].v = c[j].v;
			b[j].w = c[j].w;
		}
		int cnt = m;
		for (int j = 0; j < k; ++j) {
			if ((i >> j) & 1) {
				ret += a[j][0];
				for (int p = 1; p <= n; ++p) {
					++cnt;
					b[cnt].u = n + j;
					b[cnt].v = p;
					b[cnt].w = a[j][p];
				}
			}
		}
		sort(b + 1, b + cnt + 2);
		for (int j = 1; j <= cnt; ++j) {
			int u = find(b[j].u), v = find(b[j].v);
			if (u != v) {
				f[u] = v;
				ret += b[j].w;
			}
		}
		ans = min(ans, ret);
	}
	cout << ans << '\n';
	return 0;
}