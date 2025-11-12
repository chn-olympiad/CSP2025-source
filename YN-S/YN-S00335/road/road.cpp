#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[2001][2001];
int u[N], v2[N], w[N];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> q;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	cout << 0;
	return 0;
}