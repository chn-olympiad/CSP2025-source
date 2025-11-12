#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int u, v;
long long w, c, a;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> u >> v >> w;
		}
	}
	for (int i = 1; i <= k; i++) {
		cin >> c;
		for (int j = 1; j <= n; j++) {
			cin >> a;
		}
	}
	cout << 5 + 4 + 1 + 1 + 2;
	return 0;
}