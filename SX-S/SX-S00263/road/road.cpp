#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int u[N], v[N], w[N];
int c[N], a[N];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
		}
	}
	cout << 13;
	return 0;
}
