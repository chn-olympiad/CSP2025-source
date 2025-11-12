#include <bits/stdc++.h>
using namespace std;

namespace myb {
	
	using ll = long long;
	const int N = 1e4 + 100;
	const int M = 1e6 + 100; 
	
	struct node {
		int v, w;
	};
	vector<node> edge[N];
	struct Edge {
		int u, v, w;
//		ll w2;
		friend bool operator < (const Edge &a, const Edge &b) {
			return a.w < b.w;
		}
	};
	vector<Edge> E;
	
	int n, m, k;
	ll c[15], a[15][N];
	
	int fa[N];
	int find(int x) {
		if (fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}
	
	void main() {
		cin >> n >> m >> k;
		for (int i = 1;i <= m;i++) {
			int u, v, w;
			cin >> u >> v >> w;
			edge[u].push_back({v, w});
			edge[v].push_back({u, w});
			E.push_back({u, v, w});
		}
		for (int i = 0;i < k;i++) {
			cin >> c[i];
			for (int j = 1;j <= n;j++) {
				cin >> a[i][j];
			}
		}
		sort(E.begin(), E.end());
		
		for (int i = 1;i <= n;i++) fa[i] = i;
		
		ll ans = 0;
		vector<Edge> e;
		for (auto i : E) {
			int u = i.u, v = i.v, w = i.w;
			
			if (find(u) == find(v)) continue;
			fa[find(u)] = find(v);
			e.push_back(i);
			ans += w;
		}
		
//		cout << ans << "\n";
		
		ll Ans = 1e18;
		
		for (int i = 0;i < (1 << k);i++) {
			ll res = 0;
			vector<Edge> ee;
			for (auto t : e) ee.push_back(t);
			int maxn = 0;
			for (int j = 0;j < k;j++) {
				if ((i >> j) & 1) {
					res += c[j];
					for (int x = 1;x <= n;x++) ee.push_back({n + j + 1, x, a[j][x]});
					maxn = max(maxn, j);
//					for (auto t : e) {
//						int u = t.u, v = t.v;
//						ll w = t.w2;
//						if (a[i][u] + a[i][v] < w) {
//							res -= t.w2;
//							t.w2 = a[i][u] + a[i][v];
//							res += t.w2;
//						}
//					}
				}
			}
			
			sort(ee.begin(), ee.end());
			
			for (int j = 1;j <= n + maxn + 1;j++) fa[j] = j;
			
			for (auto j : ee) {
				int u = j.u, v = j.v, w = j.w;
				
				if (find(u) == find(v)) continue;
//				cout << u << " " << v << " " << w << "\n";
				fa[find(u)] = find(v);
				res += w;
			}
			
//			cout << bitset<2>(i) << ": " << res << "\n\n";
			
			Ans = min(Ans, res);
		}
		cout << Ans;
	}
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
//	int cnt = 0;
//	for (int i = 0;i <= 10;i++) {
//		int x = 1;
//		for (int j = 10 - i + 1;j <= 10;j++) x *= j;
//		for (int j = 1;j <= i;j++) x /= j;
//		cnt += i * x;
//	}
//	cout << cnt;

	myb::main();
	return 0;
}


