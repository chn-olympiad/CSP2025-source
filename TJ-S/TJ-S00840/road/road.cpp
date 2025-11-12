#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e4 + 8;
int n, m, k, fa[maxn];
vector<pair<int, int> > e[maxn];
bool cmp(pair<int, int> x, pair<int, int> y) {
	return x.second < y.second;
}
int find(int x) {
	if (fa[x] != x) return fa[x] = find(fa[x]);
	return fa[x] = x;
}
void merge(int u, int v) {
	fa[find(u)] = find(v);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	for (int i = n + 1, c; i <= n + k + 1; i++) {
		cin >> c;
		for (int j = 1, w; j <= n; j++) {
			cin >> w;
			e[i].push_back({j, w});
			e[j].push_back({i, w});
		}
	}
	// sort(e.begin(), e.end());
	cout << rand();
	return 0;
}
