#include <bits/stdc++.h>
#define gc getchar
#define ll long long
using namespace std;
int rd() {
	int x = 0, f = 1; char c = gc();
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = gc(); }
	while(c >= '0' && c <= '9') { x = x * 10 + (c - '0'); c = gc(); }
	return (x * f);
}

const int N = 10000, M = 1000000;
int n, m, k;
struct E { int u, v, w; };
E ori[M + 1]; int c[11];
vector < vector < E > > a(1 << 10), e(1 << 10);

namespace Dsu {
	int fa[N + 10 + 1];
	void Init() { for(int i = 1; i <= n + k; ++ i) fa[i] = i; }
	int fd(int u) { return u == fa[u] ? u : fa[u] = fd(fa[u]); }
} using namespace Dsu;

inline bool cmp(const E & x, const E & y) { return x.w < y.w; }

void Mrg(vector < E > & res, const vector < E > & x, const vector < E > & y) {
	int sizx = ((int)x.size()), sizy = ((int)y.size());
	int i = 0, j = 0;
	while(i < sizx && j < sizy) {
		if(x[i].w < y[j].w) { res.emplace_back(x[i]); ++ i; }
		else { res.emplace_back(y[j]); ++ j; }
	}
	if(i < sizx) { res.emplace_back(x[i]); ++ i; }
	if(j < sizy) { res.emplace_back(y[j]); ++ j; }
}

ll Kruskal(vector < E > & x) {
	ll res = 0; vector < E > tmp;
	Init();
	for(E & i : x) {
		int u = fd(i.u), v = fd(i.v);
		if(u != v) {
			fa[u] = v;
			res += i.w;
			tmp.emplace_back(i);
		}
	}
	x = tmp;
	return res;
}

void Solve() {
	n = rd(); m = rd(); k = rd();
	for(int i = 1; i <= m; ++ i) { ori[i].u = rd(); ori[i].v = rd(); ori[i].w = rd(); }
	sort(ori + 1, ori + m + 1, cmp);
	ll ans = 0;
	Init();
	for(int i = 1; i <= m; ++ i) {
		int x = fd(ori[i].u), y = fd(ori[i].v);
		if(x == y) continue;
		e[0].emplace_back(ori[i]); fa[x] = y;
		ans += ori[i].w;
	}
	for(int i = 1; i <= k; ++ i) {
		c[i] = rd();
		a[1 << (i - 1)].resize(n);
		for(int j = 1; j <= n; ++ j) { a[1 << (i - 1)][j - 1].u = n + i; a[1 << (i - 1)][j - 1].v = j; a[1 << (i - 1)][j - 1].w = rd(); }
		sort(a[1 << (i - 1)].begin(), a[1 << (i - 1)].end(), cmp);
	}
	for(int S = 1; S < (1 << k); ++ S) {
		int x = (S & -S);
		Mrg(e[S], e[S ^ x], a[x]);
		ll res = 0;
		for(int i = 0; i < k; ++ i) if(S >> i & 1) res += c[i + 1];
		res += Kruskal(e[S]);
		ans = min(ans, res);
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	Solve();
	return 0;
}