#include<bits/stdc++.h>
using namespace std;

namespace MyNamespace {
typedef long long ll;

inline namespace MyIO {
	inline ll rd() {
		ll s = 0, w = 1;
		char ch = char(getchar());
		while (!isdigit(ch)) {
			if (ch == '-') w = -1;
			ch = char(getchar());
		}
		while (isdigit(ch)) {
			s = (s << 3) + (s << 1) + (ch ^ 48);
			ch = char(getchar());
		}
		return (s * w);
	}
	template<typename T>
	inline void wr(T x) {
		if (x < 0) x = -x, putchar('-');
		if (x > 9) wr(x / 10);
		putchar(x % 10 + 48);
		return;
	}
	inline void wrsp() {}
	template<typename T, typename... Args>
	inline void wrsp(T x, Args... args) { wr(x), putchar(' '), wrsp(args...); }
	inline void wrln() { putchar('\n'); }
	template<typename T>
	inline void wrln(T x) { wr(x), wrln(); }
	template<typename T, typename... Args>
	inline void wrln(T x, Args... args) { wrsp(x), wrln(args...); }
}

inline namespace Base {
	#define siz(A) int((A).size())
	#define bug(x) << #x << '=' << (x) << ' '

	template<typename T>
	inline T& Max(T &x, const T &y) { return x = max(x, y); }
	template<typename T>
	inline T& Min(T &x, const T &y) { return x = min(x, y); }
}

constexpr ll INF = 1e18;

constexpr int fn = 1e5 + 10, fm = 2e6, gk = 10;
constexpr int N = fn + 10, M = fm + 10, K = gk + 3;

int n, m, kn;
struct edg_t {
	int u, v; ll w;
	friend inline bool operator < (const edg_t &A, const edg_t &B) {
		return A.w < B.w;
	}
} e[M], f[M]; int f_l;
ll c[K], a[K][N];

struct DSU {
	int fa[N], sz[N];
	void init() {
		iota(fa + 1, fa + n + kn + 1, 1);
		fill(sz + 1, sz + n + kn + 1, 1);
		return;
	}
	inline int operator () (int x) {
		if (fa[x] == x) return x;
		else return fa[x] = (*this)(fa[x]);
	}
	inline bool mrg(int x, int y) {
		int p = (*this)(x), q = (*this)(y);
		if (p == q) return 0;
		if (sz[p] < sz[q]) swap(p, q);
		fa[q] = p, sz[p] += sz[q];
		return 1;
	}
} dsu;

void get_MST() {
	sort(e + 1, e + m + 1/* , [&](const edg_t &A, const edg_t &B) -> bool { return A.w < B.w; } */);
	dsu.init(), f_l = 0;
	for (int i = 1; i <= m; ++i) {
		auto &o = e[i];
		if (dsu.mrg(o.u, o.v)) f[++f_l] = o;
	}
	return;
}

void sort_edges() {
	for (int j = 1; j <= kn; ++j) {
		for (int i = 1; i <= n; ++i) {
			f[++f_l] = {n + j, i, a[j][i]};
		}
	}
	sort(f + 1, f + f_l + 1);
	return;
}

void solve() {
	ll ans = INF;
	for (int p = 0; p < (1 << kn); ++p) {
		ll sum = 0; int cnt = 0;
		for (int j = 1; j <= kn; ++j) if (p >> (j - 1) & 1) ++cnt, sum += c[j];

		dsu.init();
		int edges_connected = 0;
		for (int i = 1; i <= f_l && edges_connected < n + cnt - 1; ++i) {
			auto &o = f[i];
			if (o.u <= n || (p >> (o.u - n - 1) & 1)) {
				if (dsu.mrg(o.u, o.v)) ++edges_connected, sum += o.w;
			}
		}
		Min(ans, sum);
	}
	wrln(ans);
	return;
}

void NamespaceMain() {
	n = rd(), m = rd(), kn = rd();
	for (int i = 1; i <= m; ++i) {
		e[i].u = rd(), e[i].v = rd(), e[i].w = rd();
	}
	for (int j = 1; j <= kn; ++j) {
		c[j] = rd();
		for (int i = 1; i <= n; ++i) a[j][i] = rd();
	}

	get_MST();
	sort_edges();
	solve();
	return;
}
}
int main() {
	ignore = freopen("road.in", "r", stdin);
	ignore = freopen("road.out", "w", stdout);
	MyNamespace::NamespaceMain();
	return 0;
}