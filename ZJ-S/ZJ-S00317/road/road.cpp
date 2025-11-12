#include <bits/stdc++.h>
using uint = unsigned;
using lint = long long;
using pii = std::pair<int, int>;

namespace mtyt {
	constexpr int N = 2e4 + 10, M = 2e6 + 10, K = 15;
	
	int n, m, k, c[K], a[K][N];
	
	struct Edge {
		int u, v, w;
		Edge() {}
		void operator=(const Edge &e) { u = e.u, v = e.v, w = e.w; }
		Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
		bool operator<(const Edge &x) const {
			return w < x.w;
		}
	} E[M], EE[M];
	
	namespace A {
		lint ans;
		int fa[N];
		
		bool check() {
			for (int i = 1; i <= k; ++i) {
				if (c[i] != 0) return false;
				bool flg = true;
				for (int j = 1; j <= n; ++j) {
					if (a[i][j] == 0) {
						flg = false;
						break;
					}
				}
				if (flg) return false;
			}
			return true;
		}
		
		int find(int x) {
			return fa[x] == x ? x : fa[x] = find(fa[x]);
		}
		
		void main() { // start mst
			for (int i = 1; i <= n + k; ++i) fa[i] = i;
			for (int i = 1; i <= k; ++i) for (int j = 1; j <= n; ++j)
				E[m++] = Edge(n + i, j, a[i][j]);
			std::sort(E, E + m);
			int cnt = n + k;
			for (int i = 0; i < m && cnt > 1; ++i) {
				int u = find(E[i].u), v = find(E[i].v), w = E[i].w;
				if (u == v) continue;
				ans += w, --cnt, fa[u] = v;
			}
			std::cout << ans << std::endl;
		}
	}
	
	namespace bf {
		lint ans = 1e18;
		
		std::vector<int> choson;
		
		int fa[N];
		
		int find(int x) {
			return fa[x] == x ? x : fa[x] = find(fa[x]);
		}
		
		lint calc() {
			lint res = 0;
			int t = choson.size();
			
			for (int i = 1; i <= n + t; ++i) fa[i] = i;
			
			int mm = m;
			for (int i = 0; i < m; ++i) EE[i] = E[i];
			
			for (auto i : choson) { // add new edge
				res += c[i];
				for (int j = 1; j <= n; ++j) EE[mm++] = Edge(n + i, j, a[i][j]);
			}
			
			std::sort(EE, EE + mm);
			int cnt = n + t;
			for (int i = 0; i < mm && cnt > 1; ++i) {
				int u = find(EE[i].u), v = find(EE[i].v), w = EE[i].w;
				if (u == v) continue;
				res += w, --cnt, fa[u] = v;
			}
			
			return res;
		}
		
		void dfs(int u) {
			if (u == k + 1) { // ok!
				ans = std::min(ans, calc());
				return ;
			}
			dfs(u + 1);
			choson.emplace_back(u);
			dfs(u + 1);
			choson.pop_back();
		}
		
		void main() {
			dfs(1);
			std::cout << ans << std::endl;
		}
	}
	
	void main() {
		freopen("road.in", "r", stdin);
		freopen("road.out", "w", stdout);
		std::cin.tie(0)->sync_with_stdio(0);
		std::cin >> n >> m >> k;
		for (int i = 0; i < m; ++i) {
			std::cin >> E[i].u >> E[i].v >> E[i].w;
		}
		for (int i = 1; i <= k; ++i) {
			std::cin >> c[i];
			for (int j = 1; j <= n; ++j) std::cin >> a[i][j];
		}
		if (A::check()) A::main();
		else bf::main();
	}
}

int main() {
	mtyt::main();
	return 0;
}
