#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define lop(i, a, b) for (int i = (a); i < (b); i++)
#define dwn(i, a, b) for (int i = (a); i >= (b); i--)
#define pr pair<int, int>
#define mp(a, b) make_pair(a, b)
#define fir first
#define sec second
#define iosfst ios :: sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define File(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;
const int N = 1e4 + 10, M = 1e7 + 10;
int n, m, k, c[15], a[15][N], pre[15][N], bak[15][N], fa[N], cnt, tot, sub = 1;
long long ans;
struct edge{
	int u, v, w;
} e[M];
bool cmp(edge x, edge y) { return x.w < y.w; }
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
signed main() {
	iosfst;
	File("road");
	cin >> n >> m >> k;
	tot = m;
	rep (i, 1, n + k) fa[i] = i;
	rep (i, 1, m) cin >> e[i].u >> e[i].v >> e[i].w;
	rep (i, 1, k) {
		cin >> c[i]; sub &= (c[i] == 0);
		rep (j, 1, n) cin >> a[i][j];
	}
	if (sub) {
		rep (j, 1, n) rep (kk, j + 1, n) {
			int mn = 2e9;
			rep (i, 1, k) mn = min(a[i][j] + a[i][kk], mn);
			e[++tot] = edge{j, kk, mn};
		}
	//	cerr << tot;
		sort(e + 1, e + tot + 1, cmp);
		rep (i, 1, tot) {
			if (find(e[i].u) != find(e[i].v)) {
				fa[find(e[i].u)] = find(e[i].v);
				ans += e[i].w;
				cnt++;
			}
			if (cnt == n - 1) break;
		}
		cout << ans;
		return 0;
	}
	sort(e + 1, e + m + 1, cmp);
	rep (i, 1, m) {
		if (find(e[i].u) != find(e[i].v)) {
			fa[find(e[i].u)] = find(e[i].v);
			ans += e[i].w;
			cnt++;
		}
		if (cnt == n - 1) break;
	}
	cout << ans;
	return 0;
}
