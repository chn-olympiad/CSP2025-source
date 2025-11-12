#include<bits/stdc++.h>
#define rep(_id, _st, _ed) for(int (_id) = (_st); _id <= (_ed); _id++)
#define per(_id, _st, _ed) for(int (_id) = (_st); _id >= (_ed); _id--)
#define db std::cerr
#define dbg(x) std::cerr << (#x) << " : " << (x) << "\n";
#define dbendl std::cerr << "\n";
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);
#define lookTime std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s used\n"; 

typedef long long i64;
typedef unsigned long long u64;

constexpr int maxn = 200005;
constexpr int maxm = 1000005;
constexpr int maxk = 13;

int n, m, k;

struct Edge {
	int u, v;
	int w;
};

int a[maxk][maxn];
int c[maxk];

std::vector<Edge> es;

namespace Task1 {
	struct DSU {
		int fa[maxn];
		int siz[maxn];
		int find(int x) {
			if (fa[x] == x) return x;
			return fa[x] = find(fa[x]);
		}
		
		inline void mrg(int u, int v) {
			u = find(u); v = find(v);
			if (u == v) return;
			if (siz[u] < siz[v]) std::swap(u, v);
			siz[u] += siz[v];
			fa[v] = u;
		}
		
		inline void init() {
			rep (i, 1, n + k) fa[i] = i;
			rep (i, 1, n + k) siz[i] = 1;
		}
	} dsu;
	
	std::vector<Edge> es1;
	
	inline i64 kruskal() {
		std::sort(es1.begin(), es1.end(), [&](Edge x, Edge y) -> bool {
			return x.w < y.w;
		});

		i64 res = 0;		
		dsu.init();
		for (Edge _ : es1) {
			int u = _.u;
			int v = _.v;
			int w = _.w;
			
			if (dsu.find(u) == dsu.find(v)) continue;
			dsu.mrg(u, v);
			res += w;
		} 
		
		return res;
	}
	
	inline i64 calc(int S) {
		i64 res = 0;
		es1 = es;
		rep (i, 1, k) {
			if (S & (1 << (i - 1))) {
				rep (j, 1, n) es1.push_back({n + i, j, a[i][j]});
				res += c[i];
			}
		}	
		
		res += kruskal();
			
		std::vector<Edge>{}.swap(es1);
		
		return res;
	}
	
	inline void solve() {
		i64 ans = 1e18;
		rep (S, 0, (1 << k) - 1) {
			ans = std::min(ans, calc(S));			
		}

		std::cout << ans << "\n";
	}
}

inline void solve() {
	std::cin >> n >> m >> k;
	rep (i, 1, m) {
		int u, v; std::cin >> u >> v;
		int w; std::cin >> w; 
		es.push_back({u, v, w});
	}
	
	bool flg = true;
	rep (i, 1, k) {
		std::cin >> c[i];
		flg &= (c[i] == 0);
		rep (j, 1, n) {
			std::cin >> a[i][j];
		}
	}
	
	if (not flg) Task1::solve(); 
	else std::cout << Task1::calc((1 << k) - 1) << "\n";
}

int main() {
	fastread

	file("road")

	solve();
	
	lookTime

	return 0;
}


