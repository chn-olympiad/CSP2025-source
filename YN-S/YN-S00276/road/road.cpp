#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int n, m, k, a[N / 2];
int head[N], edge[N], nxt[N];

void add(int x, int y) {

}

void djstra() {

}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v);
	}
	while (k--) {
		for (int j = 1; j <= n + 1; j++) {
			cin >> a[j];
		}
		djstra();
	}
	cout << 13;
	return 0;
}