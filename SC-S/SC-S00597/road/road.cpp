#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAXN = 10010; 
struct Road {
	int u, v;
};
long long n, m, k, G[MAXN][MAXN], ans;
vector<Road> r;
inline bool cmp(Road x, Road y) {
	return G[x.u][x.v] < G[y.u][y.v];
}
inline void init() {
	cin >> n >> m >> k;
	memset(G, 0x3f3f3f, sizeof(G));
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		cin >> G[min(u, v)][max(u, v)];
		r.push_back( {min(u, v), max(u, v)} );
	}
	for (int i = 1; i <= k; i++) {
		long long c, a[MAXN];
		cin >> c;
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
			for (int q = 1; q < j; q++) {
				if (G[q][j] >= 0x3f3f3f) {
					r.push_back( {q, j} );
				}
				G[q][j] = min(G[q][j], a[j] + a[q] + c);
			}
		}
	}
	sort(r.begin(), r.end(), cmp);
}
inline void kruskal() {
	int i = 0, q = n;
	bool vis[MAXN] = {false};
	while (q >= 1) {
		if (vis[r[i].u] == false || vis[r[i].v] == false) {
			if (vis[r[i].u] == false) q--; 
			if (vis[r[i].v] == false) q--;
			vis[r[i].u] = vis[r[i].v] = true;
			ans += G[r[i].u][r[i].v];
		}
		i++;
	}
	return;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	init();
	kruskal();
	cout << ans << '\n';
	return 0;
}