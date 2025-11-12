#include <bits/stdc++.h>
using namespace std;
int a[11011];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, k, u, v, w;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
	}
	if (k <= 0)
		cout << w;
	return 0;
}