// 这道题可做在哪 
#include <bits/stdc++.h>
#define int long long
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
#define D(i, a, b) for (int i = (a); i >= (b); --i)
#define FIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e4 + 5, K = 15, inf = 1e9;
int n, m, k, par[N], d[K][N], c[K];
int find(int x) {
	return (x == par[x] ? x : par[x] = find(par[x]));
}
struct E {
	int to, val, nxt;
} e[2000005];
int hd[N], ec;
void AE(int u, int v, int w) {
	e[++ec] = {v, w, hd[u]}, hd[u] = ec;
}
struct EE {
	int u, v, w;
} E[2000005];
bool cmp(EE u, EE v) {
	return u.w < v.w;
} 
int res;
struct V {
	int to, val;
};
vector<V> G[N];
void Kru() {
	F(i, 1, n) par[i] = i;
	sort(E + 1, E + 1 + m, cmp);
	F(i, 1, m) {
		int uu = E[i].u, vv = E[i].v;
		int u = find(uu), v = find(vv);
		if (u != v) {
			res += E[i].w;
			par[u] = v;
			G[uu].push_back({vv, E[i].w});
		}
	} 
}
int f[K][N], g[K][N];
bool ins[N];
void DFS(int u, int p) {
	ins[u] = 1;
	F(i, 1, k) f[i][u] = d[i][u], g[i][u] = inf;
	for (V tmp : G[u]) {
		int v = tmp.to;
		if (v == p) continue;
		DFS(v, u);
		F(i, 1, k) {
			f[i][u] = min(f[i][u], f[i][v]);
		}
	}
	F(i, 1, n) if (!ins[i]) F(j, 1, k) g[j][u] = min(g[j][u], d[j][i]);
	ins[u] = 0;
}
bool vis[K];
bool used[K];
void DFS2(int u, int p) {
	for (V tmp : G[u]) {
		int v = tmp.to, w = tmp.val;
		int mn = w, p = -1;
		F(i, 1, k) {
			int cur;
			if (!vis[i]) {
//				cur = f[i][u];
//			} else {
				if (!used[i]) cur = g[i][u] + f[i][u] + c[i];
				else cur = f[i][u];
				if (cur < mn) {
					mn = cur, p = i;
				}
			}
			
		}
		if (mn < w) {
			res = res - w + mn;
//			cout << u<<' '<<v << ' ' << p << ' ' << mn << '\n';
//			cout << res << '\n'; 
			vis[p] = 1;
			used[p] = 1;
		}
		DFS2(v, u);
		if (mn < w) vis[p] = 0;
	}
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	FIO
	cin >> n >> m >> k;
	F(i, 1, m) {
		int u, v, w; cin >> u >> v >> w;
		AE(u, v, w), AE(v, u, w);
		E[i] = {u, v, w};
	}
	F(i, 1, k) {
		cin >> c[i];
		F(j, 1, n) cin >> d[i][j];
	}
	Kru(); 
	if (k == 0) {
		cout << res << '\n';
		return 0;
	}
	DFS(1, 0);
	DFS2(1, 0);
	cout << res << '\n'; 
	return 0;
}

