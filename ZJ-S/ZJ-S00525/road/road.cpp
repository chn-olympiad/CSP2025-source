#include <bits/stdc++.h>
using namespace std; typedef long long ll;
const int N = 10005, M = 1000005, K = 15;
int n, m, k, ptr[K]; ll sum, ans, c[K];
struct DSU {
	int f[N + K], cnt;
	void init() {
		for (int i = 1; i < N + K; ++i) f[i] = -1; cnt = 0;
	}
	int find(int x) {
		return f[x] < 0 ? x : f[x] = find(f[x]);
	}
	void merge(int x, int y) {
		x = find(x); y = find(y);
		if (f[x] > f[y]) swap(x, y);
		f[x] += f[y]; f[y] = x; ++cnt;
	}
} ds;
struct edge {
	int u, v; ll w;
	bool operator<(const edge &_) const {
		return w < _.w;
	}
} ed[M], ok[N * K]; vector<edge> ex[K];
ll work(int sta) {
	vector<int> nds;
	int cntv = 0;
	for (int i = 0; i < k; ++i)
		if ((sta >> i) & 1) nds.push_back(i + 1), ++cntv;
	memset(ptr, 0, sizeof ptr);
	ll ret = 0;
	for (int i = 0; i < nds.size(); ++i)
		ret += c[nds[i]];
	int tot = 0;
	nds.push_back(0);
	while (1) {
		int p = -1; ll mn = 2e9;
		for (int i = 0; i < nds.size(); ++i)
			if (ptr[i] < ex[nds[i]].size() && ex[nds[i]][ptr[i]].w < mn) {
				mn = ex[nds[i]][ptr[i]].w;
				p = i;
			}
		if (p == -1) break;
		ok[++tot] = ex[nds[p]][ptr[p]]; ++ptr[p];
	}
	ds.init();
	for (int i = 1; i <= tot; ++i) {
		if (ds.find(ok[i].u) != ds.find(ok[i].v)) {
			ds.merge(ok[i].u, ok[i].v);
			ret += ok[i].w;
			if (ds.cnt == n + cntv - 1) break;
		}
	}
	return ret;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i)
		cin >> ed[i].u >> ed[i].v >> ed[i].w;
	stable_sort(ed + 1, ed + m + 1);
	ds.init();
	ll maxe = 0;
	for (int i = 1; i <= m; ++i) {
		if (ds.find(ed[i].u) != ds.find(ed[i].v)) {
			ds.merge(ed[i].u, ed[i].v);
			ans += ed[i].w;
			maxe = max(maxe, ed[i].w);
			ex[0].push_back(ed[i]);
			if (ds.cnt == n - 1) break;
		}
	}
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j) {
			ll w; cin >> w;
			if (w <= maxe)
				ex[i].push_back(edge{i + n, j, w});
		}
		stable_sort(ex[i].begin(), ex[i].end());
	}
	for (int i = 1; i < (1 << k); ++i) ans = min(ans, work(i));
	cout << ans << '\n'; return 0;
}