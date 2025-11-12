// 吴昱胤 SN-S00113 西安铁一中国际合作学校
// By 0x0F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cerr << #x << ": " << x << endl;
int n, m, k, cnt; 
struct Edge {
	int u, v, dis;
	bool operator<(const Edge &rhs) const {
		return dis < rhs.dis;
	}
} e[1000010], edge[150010];
int a[15][10010], fu[20010];
int c[15], tot;
bool mked[15];
ll mst; int suc;
inline int query(int u) {
	if (fu[u] == u) return u;
	return fu[u] = query(fu[u]);
}
void getmst() {
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; i++) {
		int u = query(e[i].u), v = query(e[i].v);
		if (u == v) continue;
		fu[u] = v;
		suc++, mst += e[i].dis;
		edge[suc].u = e[i].u, edge[suc].v = e[i].v, edge[suc].dis = e[i].dis;
		if (suc == n - 1) break;
	}
}
ll getans(int b) {
	for (int i = 1; i <= k; i++) mked[i] = 0;
	for (int i = 1; i <= k; i++) if ((b >> i - 1) & 1) mked[i] = 1;
	for (int i = 1; i <= n + k; i++) fu[i] = i;
	int tt = 0, x = 0;
	ll aa = 0;
	for (int i = 1; i <= k; i++) if (mked[i] == 1) x++, aa += c[i];
	for (int i = 1; i <= tot; i++) {
		if (edge[i].u > n && mked[edge[i].u - n] == 0) continue;
		int u = query(edge[i].u), v = query(edge[i].v);
		if (u == v) continue;
		fu[u] = v;
		tt++, aa += edge[i].dis;
		if (tt == n + x - 1) break;
	}
	return aa;
}
void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) fu[i] = i;
	for (int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w; cnt++;
		e[cnt].u = u, e[cnt].v = v, e[cnt].dis = w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	getmst();
	ll ans = mst; tot = n - 1;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++) {
			tot++;
			edge[tot].u = n + i, edge[tot].v = j, edge[tot].dis = a[i][j];
		}
	sort(edge + 1, edge + tot + 1);
//	for (int i = 1; i <= tot; i++) 
//		cerr << edge[i].u << " " << edge[i].v << " " << edge[i].dis << endl;
	for (int b = 1; b < (1 << k); b++) ans = min(ans, getans(b));
	cout << ans << endl;
}
int main() {
//	clock_t st, ed; st = clock();
	ios :: sync_with_stdio(0); cout.tie(0); 
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	solve();
//	ed = clock();
//	debug(ed - st);
	return 0;
}

