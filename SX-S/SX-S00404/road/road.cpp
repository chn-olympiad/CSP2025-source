#include <bits/stdc++.h>
using namespace std;

#define For(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<=(y);++i)
#define foR(i,x,y,...) for(int i=(x),##__VA_ARGS__;i>=(y);--i)
#define Rep(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<(y);++i)
typedef long long ll;
#define fi first
#define se second
#define me(s,x) memset(s,x,sizeof s)
#define pb emplace_back
const int M = 2e6+5, K = 15, N = 1e4+5;
int n, m, k, tot;
ll ans = 0;
int a[K][N], c[K], fa[N];

struct no {
	int u, v, w;
	void read() {
		cin >> u >> v >> w;
	}
} e[M], b[M];

int find(int x) {
	return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
}

void MAIN() {
	cin >> n >> m >> k;
	For(i, 1, n + k) fa[i] = i;
	For(i, 1, m) {
		e[i].read();
	}
	For(i, 1, k) {
		cin >> c[i];
		For(j, 1, n) cin >> a[i][j];
	}
	For(i, 1, k)For(j, 1, n) {
		e[++m] = {i + n, j, a[i][j]};
	}
	sort(e + 1, e + m + 1,
	[](no x, no y) {
		return x.w < y.w;
	});
	For(i, 1, m) {
		int p = find(e[i].u), q = find(e[i].v);
		if (p == q)
			continue;
		ans += e[i].w;
		fa[p] = q;
	}
//	if (k == 0)
	cout << ans << endl;
//	else {
//		foR(i, tot, tot - k + 1) {
//			ans -= e[i].w;
//		}
//		cout << ans << endl;
//	}
}

signed main() {
	freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(nullptr);
	int t = 1;
	while (t--) {
		MAIN();
	}
	return 0;
}
