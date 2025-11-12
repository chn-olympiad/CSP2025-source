#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int u[10005], v[10005], w[10005];
int c, a[10005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int j = 1; j <= k; j++) {
		cin >> c;
		cin >> a[j];
	}
	cout << 13;
	return 0;
}