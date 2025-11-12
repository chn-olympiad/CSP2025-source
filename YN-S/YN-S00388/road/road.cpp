#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n, m, k, ans;
vector<int>g[10010], w[10010];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	while (m--) {
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back(v);
		g[v].push_back(u);
		w[u].push_back(c);
		w[v].push_back(c);
	}
	while (k--) {
		int c;
		cin >> c;
		for (int i = 1; i <= n; i++) {
			int a;
			cin >> a;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < w[i].size(); j++) {
			ans += w[i][j];
		}
	}
	cout << ans / 2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}