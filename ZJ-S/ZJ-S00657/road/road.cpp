#include <bits/stdc++.h>
#define FL(i, a, b) for (int i = (a); i <= (b); ++i)
#define FR(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
typedef long long ll;
const int N = 1e4 + 10;
const int M = 1e6 + 10;
const int INF = 1e9 + 10;
const ll INFLL = 1e18 + 10;
int n, m, k;
inline char gc() {
	static char buf[100000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)? EOF : *p1++;
}
template<typename T>
void read(T &x) {
	x = 0; int f = 0; char c = gc();
	for (; !isdigit(c); c = gc()) f |= c == '-';
	for (; isdigit(c); c = gc()) x = (x << 3) + (x << 1) + c - '0';
	if (f) x = -x;
}
struct Edge {
	int u, v, w;
} e[M + N * 10];
struct DSU {
	int fa[N], siz[N];
	void Init() {
		FL(i, 1, n + k) {
			fa[i] = i;
			siz[i] = 1;
		}
	}
	int Find(int u) {
		return fa[u] == u? u : fa[u] = Find(fa[u]);
	}
	void Union(int u, int v) {
		u = Find(u), v = Find(v);
		if (u == v) return;
		if (siz[u] < siz[v]) swap(u, v);
		fa[v] = u;
		siz[u] += siz[v];
	}
} dsu;
int tot, c[N];
ll f[(1 << 10) + 10];
int cnt[(1 << 10) + 10], id[(1 << 10) + 10][N];
int s;
inline void AddE(int i) {
	int u = dsu.Find(e[i].u), v = dsu.Find(e[i].v);
	if (u != v) {
		dsu.Union(u, v);
		f[s] += e[i].w;
		id[s][++cnt[s]] = i;
	}
}
void Calc() { // Calc s = 0
	dsu.Init();
	s = 0;
	FL(i, 1, m) {
		AddE(i);
		if (cnt[s] == n - 1) {
			return;
		}
	}
}
inline void CalcS(int t, int u) {
	dsu.Init();
	int i = 1, j = 1, cm = n + __builtin_popcount(t);
	while (i <= cnt[t] && j <= cnt[u]) {
		if (e[id[t][i]].w < e[id[u][j]].w) {
			AddE(id[t][i++]);
		} else {
			AddE(id[u][j++]);
		}
		if (cnt[s] == cm) return;
	}
	while (i <= cnt[t]) {
		AddE(id[t][i++]);
		if (cnt[s] == cm) return;
	}
	while (j <= cnt[u]) {
		AddE(id[u][j++]);
		if (cnt[s] == cm) return;
	}
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n), read(m), read(k);
	FL(i, 1, m) {
		read(e[i].u);
		read(e[i].v);
		read(e[i].w);
	}
	e[0].w = INF;
	sort(e + 1, e + m + 1, [&](Edge a, Edge b) {
		return a.w < b.w;
	});
	tot = m;
	FL(i, 0, k - 1) {
		read(c[i]); 
		FL(j, 1, n) {
			++tot;
			read(e[tot].w); 
			e[tot].u = n + 1 + i, e[tot].v = j;
			id[(1 << k) + i][j] = tot;
		}
		cnt[(1 << k) + i] = n;
		sort(id[(1 << k) + i] + 1, id[(1 << k) + i] + n + 1, [&](int x, int y) {
			return e[x].w < e[y].w;
		});
	}
	Calc();
//	cout << f[0] << " " << cnt[0] << endl; //
	FL(i, 1, (1 << k) - 1) {
		int u = 0;
		FL(j, 0, k - 1) {
			if (i >> j & 1) {
				u = j;
				f[i] += c[j];
			}
		}
		s = i;
		CalcS(i ^ (1 << u), (1 << k) + u);
	}
	ll ans = INFLL;
	FL(i, 0, (1 << k) - 1) {
		int bcnt = __builtin_popcount(i);
		if (cnt[i] == n - 1 + bcnt) {
			ans = min(ans, f[i]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
