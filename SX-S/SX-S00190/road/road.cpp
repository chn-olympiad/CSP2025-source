#include <bits/stdc++.h>
using namespace std;
int n, m, k, c, cx, cnt, u, v, w;

struct T {
	int u, v, w;
} e[2000005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> u >> v >> w;
		e[++cnt] = {u, v, w};
	}
	cin >> c;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> cx;

		}
	}
	return 0;
}
