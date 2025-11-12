#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define sz size
#define fi first
#define se second
#define pii pair<int, int>
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;

const int N = 2e4 + 5;
const int M = 2e6 + 5;

int n, m, k, tot, c[N], f[N], pos[N];
ll ans = 1e18;
pii a[15][N];

struct edge {
	int u, v;
	ll w;
}e[M], ee[M];

int find(int x) {
	return f[x] == x ? f[x] : f[x] = find(f[x]);
}

void solve(int s) {
	ll sum = 0;
	for (int i = 0; i <= n + k; i++) f[i] = i, pos[i] = 1;
	for (int i = 1; i <= k; i++) 
		if (s >> (i - 1) & 1) sum += c[i];
	int cnt = 0, cnts = __builtin_popcount(s);
	while (cnt < n + cnts - 1) {
		ll mnv = 1e18;
		int p = -1;
		for (int i = 1; i <= k; i++) {
			if (!(s >> (i - 1) & 1)) continue;
			while (pos[i] <= n && find(a[i][pos[i]].se) == find(i + n)) pos[i]++;
			if (pos[i] <= n) {
				if (mnv > a[i][pos[i]].fi) {
					mnv = a[i][pos[i]].fi;
					p = i;
				}
			}
		}
		while (pos[0] <= tot && find(ee[pos[0]].u) == find(ee[pos[0]].v)) pos[0]++;
		if (pos[0] <= tot) {
			if (mnv > ee[pos[0]].w) {
				mnv = ee[pos[0]].w;
				p = 0;
			}
		}
		sum += mnv;
		if (sum > ans) return;
		if (p == 0) f[find(ee[pos[0]].u)] = find(ee[pos[0]].v);
		else f[find(a[p][pos[p]].se)] = find(p + n);
		pos[p]++;
		cnt++;
	}
	ans = min(ans, sum);
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> a[i][j].fi, a[i][j].se = j;
		sort(a[i] + 1, a[i] + n + 1);
	}
	sort(e + 1, e + m + 1, [](edge x, edge y) {
		return x.w < y.w;
	});
	for (int i = 1; i <= n + k; i++) f[i] = i;
	for (int i = 1; i <= m; i++) {
		auto [u, v, w] = e[i];
		u = find(u); v = find(v);
		if (u != v) {
			f[u] = v;
			ee[++tot] = e[i];
		}
	}
	assert(tot == n - 1);
	for (int s = 0; s < 1 << k; s++) solve(s);
	cout << ans << '\n';
	return 0;
}
