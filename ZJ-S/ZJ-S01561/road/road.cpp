#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, k, c[15], a[15][10010];
ll ans;
bool flag;
vector<vector<pair<int, int>>> adj;
struct Edge {
	int l, r, w;
	bool operator <(const Edge& other) const {
		return w < other.w;
	}
};
vector<int> f;
vector<Edge> v;
int find(int x) {
	return (f[x] == x ? f[x]: (f[x] = find(f[x])));
}
void join(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy) f[fx] = fy;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	f.resize(n + k + 2, 0);
	adj.resize(n + k + 1);
	for (int i = 0; i < m; i ++ ) {
		int u, e, w;
		cin >> u >> e >> w;
		adj[u].push_back({e, w});
		adj[e].push_back({u, w});
		v.push_back({u, e, w});
	}
	for (int i = 1; i <= k; i ++ ) {
		cin >> c[i];
		if (c[i] != 0) flag = 1;
		for (int j = 1; j <= n; j ++ ) {
			cin >> a[i][j];
			if (a[i][j] != 0) flag = 1;
		}
	}
	if (!a && k) {cout << 0; return 0;}
	for (int i = 1; i <= n + k; i ++ ) f[i] = i;
	if (k == 0) {
		sort(v.begin(), v.end());
		for (auto i: v)
			if (find(i.l) != find(i.r)) {
				join(i.l, i.r);
				ans += i.w;
			}
		cout << ans;
		return 0;
	}
	for (int i = 1; i <= k; i ++ )
		for (int j = 1; j <= n; j ++ ) v.push_back({i + n, j, a[i][j]});
	sort(v.begin(), v.end());
	for (auto i: v) {
		if (find(i.l) != find(i.r)) {
			join(i.l, i.r);
			ans += i.w;
			if (i.l > n) ans += c[i.l], c[i.l] = 0;
			if (i.r > n) ans += c[i.r], c[i.r] = 0;
		}
	}
	cout << ans;
	return 0;                     
}