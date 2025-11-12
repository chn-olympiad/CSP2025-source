#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 20;
int n, m, k, a[15][N], c[15];
bool vis[15];
struct Edge {
	int u, v, w;
	bool operator<(const Edge& other) const {
		return w < other.w;
	}
};
vector<Edge> edge;



int fa[N], mind[N][15];


int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}


void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	fa[x] = y;
	for (int i = 1; i <= k; i++) {
		mind[y][i] = min(mind[y][i], mind[x][i]);
	}
}


int Kruskal() {
	sort(edge.begin(), edge.end());
	int ans = 0;
	for (auto& e : edge) {
		int x = e.u, y = e.v, w = e.w;
		int fx = find(x), fy = find(y);
		if (fx == fy) continue;
		// 暴力找有没有更优的方案
		int now = 0, mn = w;
		for (int i = 1; i <= k; i++) {
			int nw = mind[fx][i] + mind[fy][i];
			if (!vis[i]) nw += c[i];
			if (mn >= nw) {
				mn = nw;
				now = i;
			}
		}
		
		merge(fx, fy);
		int ff = find(x);
		if (now != 0) {
			vis[now] = 1;
			mind[ff][now] = 0;
		}
		ans += mn;
	}
	return ans;
}


signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge.push_back({u, v, w});
	}
	
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			mind[j][i] = a[i][j];
		}
	}
	
	int ans = Kruskal();
	cout << ans << '\n';
	return 0;
}

/*
4 3 1
1 2 999
1 3 999
1 4 999
100 100 100 100 1000
*/

