#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, k, c[21], cnt,  s[2000001][3], fa[20001];
ll ans, a[11][100001];
map<int, int> mp[20001];
struct info {
	ll u, v, w;
}e[10000001];
bool cmp (info a, info b) {
	return a.w < b.w;
}
int find (int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
inline void kr () {
	sort(e + 1, e + cnt + 1, cmp);
	for (register int i = 1; i <= n; ++i) fa[i] = i;
	for (register int i = 1; i <= m; ++i) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int uu = find(u), vv = find(v);
		if (uu == vv) continue;
		fa[vv] = fa[uu];
	//	int x = find(uu);
		ans += w;
	}
}
int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);cnt = m;
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
	}bool ok = 1;
	for (register int i = 1; i <= k; ++i) {
		scanf("%d", &c[i]);
		if (c[i]) ok = 0;
		for (register int j = 1; j <= n; ++j) {
			scanf("%lld", &a[i][j]);
			if (a[i][j]) ok = 0;
		}
	}
	if (ok) {
		cout << 0 << "\n";
		return 0;
	}
	for (register int i = 1; i <= k; ++i) {
		for (register int j = 1; j <= n; ++j) {
			for (register int kk = j + 1; kk <= n; ++kk) {
				e[++cnt].u = j, e[cnt].v = kk, e[cnt].w = c[i] + a[i][j] + a[i][kk];
			}
		}
	}
	kr();
	cout << ans << "\n";
	return 0;
}

