#include <bits/stdc++.h>
using namespace std;
int n, m, k;

struct node {
	int v, w;
};
vector<node>e[1000006], g[1000006];
int c[1000006];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		e[a].push_back({b, c});
		e[b].push_back({a, c});
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; i++) {
			int x;
			cin >> x;
			g[i].push_back({j, x});
			g[j].push_back({i, x});
		}
	}
	cout << 0;
	return 0;
}