
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2e4 + 10;
typedef array<int, 2> pii;
typedef array<int, 3> pi3;
vector<pi3> e[2];
int n, m, k, c[N], fa[N];

int fd(int x) {
	if (fa[x] == x)	return x;
	return fa[x] = fd(fa[x]);
}

ll prime(int now, int id) {//now表示需要那些城镇
	ll ans = 0;
	for (ll i = 1; i <= k; ++i) {
		if (now & (1 << (i - 1))) {
			ans += (ll)c[i];
		}
	}
	for (int i = 1; i <= n + k; ++i)	fa[i] = i;
	for (pi3 tmp : e[id]) {
		int u = tmp[1], v = tmp[2], w = tmp[0];
		if (u > n && (now & (1 << (u - n - 1))) == 0)	continue;//若不需要u或v
		if (v > n && (now & (1 << (v - n - 1))) == 0)	continue;
		int fu = fd(u), fv = fd(v);
		if (fu == fv)	continue;
		fa[fu] = fv;
		ans += (ll)w;
		e[id ^ 1].push_back(tmp);
	}
	return ans;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1, u, v, w; i <= m; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		e[0].push_back({w, u, v});
	}
	sort(e[0].begin(), e[0].end());
	prime(0, 0);
	for (int i = 1, u; i <= k; ++i) {
		scanf("%d", &c[i]);
		u = i + n;
		for (int v = 1, w; v <= n; ++v) {
			scanf("%d", &w);
			e[1].push_back({w, u, v});
		}
	}
	sort(e[1].begin(), e[1].end());
	ll ans = 1e17;
	for (int i = 0; i < (1 << k); ++i) {
		ans = min(ans, prime(i, 1));
	}
	printf("%lld", ans);
	return 0;
}
