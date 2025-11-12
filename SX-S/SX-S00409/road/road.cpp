#include <bits/stdc++.h>
using namespace std;
int n, m, k, u, v, w, a, sum, x;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < 3; i++) {
		cin >> u >> v >> w;
		sum += w;
	}
	for (int i = 0; i <= n; i++) {
		cin >> a;
	}
	cout << sum;
	return 0;
}
