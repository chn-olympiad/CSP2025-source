#include <bits/stdc++.h>
using namespace std;
#define int long long

namespace wsq {
	const int N = 1e4 + 5, M = 1e7 + 5;
	int n, m, k;
	int c[N], a[N];
	struct Edge {
		int u, v, w; 
		int f = 0;
		bool operator<(Edge x) {
			return w < x.w;
		}
	};
	Edge e[M];
	int tot;
	int fa[M];
	int find(int x) {
		if(fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}
	int ans;
	bool flag[M];
	void krs() {
		sort(e + 1, e + tot + 1);
		for(int i = 1; i <= tot; i++) {
			int u = e[i].u, v = e[i].v, w = e[i].w, f = e[i].f;
			// cout << u << " "<< v << " "<< w << endl;
			if(find(u) != find(v)) {
				ans += w;
				if(flag[f]) ans -= c[f];
				flag[f] = 1;
				fa[find(u)] = find(v);
			}
		}
	}
	void main() {
		for(int i = 1; i < M; i++) fa[i] = i;
		cin >> n >> m >> k;
		for(int i = 1, u, v, w; i <= m; i++) {
			cin >> u >> v >> w;
			e[++tot] = {u, v, w};
		}
		for(int i = 1; i <= k; i++) {
			cin >> c[i];
			for(int j = 1; j <= n; j++) {
				cin >> a[j];
				for(int J = 1; J < j; J++)
					e[++tot] = {j, J, a[j] + c[i] + a[J], i};
			}
		}
		krs();
		cout << ans;
	}
};

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;
	// cin >> T;
	while(T--)
		wsq::main();
	return 0;
}
//I have no egg!
