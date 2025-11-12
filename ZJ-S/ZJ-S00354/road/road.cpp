#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7, M = 1e6 + 7;
struct edge {
	int u, v, w;
};
vector<edge> p, vec;
int f[N + 20], sz[N + 20], n, m, k, c[13], a[13][N];
long long ans = 0x3f3f3f3f3f3f3f3f;
int find(int x) {
	if (f[x] == x) return x;
	return (f[x] = find(f[x]));
}
inline void merge(int u, int v) {
	u = find(u), v = find(v);
	if (sz[u] < sz[v]) f[u] = v;
	else f[v] = u;
	return;
}
inline bool cmp(edge _a, edge _b) {
	return _a.w < _b.w;
}
long long res;
void solve(int msk) {
	res = 0;
	vec = p;
	int kk = 0;
	for (int i = 1; i <= n + k + 1; i++) f[i] = i, sz[i] = 1;
	for (int i = 1; i <= k; i++) {
		if ((msk >> (i - 1)) & 1) {
			res += c[i];
			for (int j = 1; j <= n; j++)
			vec.push_back({n + i, j, a[i][j]}), ++kk;
		}
	}
	sort(vec.begin(), vec.end(), cmp);
	int u, v, w, cnt = 0;
	for (auto x : vec) {
		u = x.u, v = x.v, w = x.w;
		if (find(u) == find(v)) continue;
		merge(u, v);
		++cnt;
		res += w;
		if (cnt >= n + kk - 1) break;
	}
	ans = min(ans, res);
	return;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		p.push_back({u, v, w});
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < (1 << k); i++) {
		solve(i);
	}
	cout << ans;
	return 0;
}
