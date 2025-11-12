#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define inf 1e18
using ll = long long;
using db = double;
using namespace std;
constexpr int N = 1e4 + 15, M = 2e6 + 5, P = 1e9 + 7;
bool A = true;
int n, m, k, cnt, c[15], a[15][N];
struct edge {
	int x, y, z;
} e[M], E[M];
int fa[N];
int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
ll krus(int num) {
	for (int i = 1; i <= n; ++ i) fa[i] = i;
	sort(e + 1, e + cnt + 1, [](edge x, edge y) {
		return x.z < y.z;
	});
	int tot = 0;
	ll res = 0;
	for (int i = 1; i <= cnt; ++ i) {
		int x = find(e[i].x), y = find(e[i].y);
		if (x == y) continue;
		res += e[i].z;
		fa[x] = y;
		++ tot;
		if (tot == n + num - 1) break;
	}
	return res;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1, x, y, z; i <= m; ++ i) {
		cin >> x >> y >> z;
		E[++ cnt] = {x, y, z};
	}
	for (int i = 1; i <= k; ++ i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++ j) cin >> a[i][j];
	}
	ll ans = inf;
	for (int s = 0; s < 1 << k; ++ s) {
		ll res = 0;
		cnt = 0;
		for (int i = 1; i <= m; ++ i) e[++ cnt] = E[i];
		int ss = s, num = 0;
		for (int i = 0; i < k; ++ i)
			if (ss & (1 << i)) {
				++ num;
				fa[i + 1 + n] = i + 1 + n;
				res += c[i + 1];
				for (int j = 1; j <= n; ++ j) e[++ cnt] = {i + 1 + n, j, a[i + 1][j]};
			}
		ans = min(ans, res + krus(num));
	}
	cout << ans << '\n';
	return 0;
}