// 沒有別的選擇了，我必須贏
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10100;

int n, m, k, c[12], a[12][N];
ll ans = 1e18;
bool vis[N + 12];
vector<array<int, 3>> e;
int f[N + 12];

int findset(int x) {return (f[x] == x)?x:f[x]=findset(f[x]);}

ll work() {
	ll res = 0;
	for (int i = 1; i <= n + k; i++) {
		f[i] = i;
	}
	for (auto q : e) {
		auto w = q[0], u = q[1], v = q[2];
		if (!vis[u] || !vis[v]) continue;
		int f1 = findset(u), f2 = findset(v);
		if (f1 != f2) {
			res += (ll)w;
			f[f1] = f2;
		}
	}
	return res;
}

void solveA() {
	ll res = 0;
	for (int i = 1; i <= n + k; i++) {
		f[i] = i;
	}
	for (auto q : e) {
		auto w = q[0], u = q[1], v = q[2];
		int f1 = findset(u), f2 = findset(v);
		if (f1 != f2) {
			res += (ll)w;
			f[f1] = f2;
		}
	}
	printf("%lld\n", res);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e.push_back({w, u, v});
	}
	for (int i = 1; i <= n; i++) {
		vis[i] = 1;
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			e.push_back({a[i][j], n + i, j});
		}
	}
	sort(e.begin(), e.end());
	int f = 1;
	for (int i = 1; i <= k; i++) {
		if (c[i]) f = 0;
	}
	if (f) {
		solveA();
		return 0;
	}
	for (int i = 0; i < 1 << k; i++) {
		int l = i, d = 0;
		ll ans2 = 0;
		while (l) {
			++d;
			if (l & 1) {
				vis[n + d] = 1;
				ans2 += c[d];
			} else vis[n + d] = 0;
			l >>= 1;
		}
		ans = min(ans, ans2 + work());
	}
	printf("%lld\n", ans);
}
