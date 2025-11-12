#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 15, K = 12, M = 1e6 + 5;
int n, m, k;
int fa[N], siz[N];
int fnd(int x) {
	return x == fa[x] ? x : fa[x] = fnd(fa[x]);
}
void mge(int x, int y) {
	x = fnd(x), y = fnd(y);
	if (x == y) return;
	if (siz[x] < siz[y]) swap(x, y);
	fa[y] = x, siz[x] += siz[y];
}
void init() {
	for (int i = 1; i <= n + k; i++) fa[i] = i, siz[i] = 1;
}
int c[N];
vector<pair<int, int>>a[K];
struct Node {
	int x, y, w;
	bool operator < (const Node &a) const {
		return w < a.w;
	}
} bas[M], v[M], vt[M], nw[M];
int t1, t2, t3, t4;

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		v[++t2] = {x, y, w};
	}
	sort(v + 1, v + 1 + t2);
	init();
	for (int i = 1; i <= t2; i++) {
		int x = fnd(v[i].x), y = fnd(v[i].y);
		if (x == y) continue;
		bas[++t1] = v[i];
		mge(x, y);
	}
	for (int i = 0; i < k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			a[i].emplace_back(x, j);
		}
		sort(a[i].begin(), a[i].end());
	}
	ll ans = LONG_LONG_MAX;
	for (int s = 0; s < (1 << k); s++) {
		ll sm = 0;
		int cnt = n;
		for (int i = 1; i <= t1; i++) v[i] = bas[i]; t2 = t1;
		for (int i = 0; i < k; i++)
			if ((s >> i) & 1) sm += c[i];
		if (sm >= ans) continue;
		for (int i = 0; i < k; i++)
			if ((s >> i) & 1) {
				t3 = t4 = 0;
				++cnt;
				for (pair<int, int> p : a[i]) nw[++t4] = {n + i + 1, p.second, p.first};
				t3 = t2 + t4;
				merge(v + 1, v + 1 + t2, nw + 1, nw + 1 + t4, vt + 1);
				for (int j = 1; j <= t3; j++) v[j] = vt[j]; t2 = t3;
			}
		init();
		for (int i = 1; i <= t2; i++) {
			int x = fnd(v[i].x), y = fnd(v[i].y);
			if (x == y) continue;
			mge(x, y);
			sm += v[i].w;
			if (sm >= ans || (--cnt) == 0) break;
		}
		ans = min(ans, sm);
	}
	cout << ans << '\n';
	return 0;
}
