#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5;
int n, m, k, f[N], s[N], pl[15];

struct Edge {
	int u, v;
	ll w;
};
vector<Edge> e;

bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}
ll c[15];

int get(int x) {
	if (x == f[x])
		return x;
	return f[x] = get(f[x]);
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n + k; i++) {
		f[i] = i;
		s[i] = (i <= n);
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		e.push_back({u, v, w});
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			ll a;
			cin >> a;
			e.push_back({i + n, j, a + c[i]});
		}
	}
	sort(e.begin(), e.end(), cmp);
	int l = e.size();
	ll ans = 0;
	for (int i = 0; i < l; i++) {
		int u = e[i].u, v = e[i].v;
		if (u > n)
			pl[u - n]++;
		if (v > n)
			pl[v - n]++;
		ll cost = e[i].w;
		int fu = get(u), fv = get(v);
		if (fu == fv)
			continue;
		f[fu] = fv;
		s[fv] += s[fu];
		s[fu] = 0;
		ans += cost;
		if (s[fv] >= n) {
			break;
		}
	}
	for (int i = 1; i <= k; i++) {
		if (pl[i] <= 0)
			continue;
		ans -= (pl[i] - 1) * c[i];
	}
	cout << ans;
	return 0;
}