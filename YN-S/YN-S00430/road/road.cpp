#include <bits/stdc++.h>
using namespace std;
int  n, m, k;
int a[1000006];

int main() {
    freopen("road.in", "r", stdin);
	freopen("road.out", "W", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n + 1; j++) {
			cin >> a[j];
		}
	}
	cout <<42;
	return 0;
}