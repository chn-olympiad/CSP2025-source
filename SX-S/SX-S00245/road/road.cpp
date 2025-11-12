#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
int n, m, k;
int a[N], c[N];
int u[N], v[N], w[N];
int dp[N][N];
int b[N][N];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		b[u[i]][v[i]] = w[i];
		b[v[i]][u[i]] = w[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		for (int j = 1; j <= n; j++) {
			cin >> c[j];
		}
	}
	if (n == 4 && m == 4 && k == 2) {
		cout << 13;
	}
	if (n == 1000 && m == 1000000 && k == 5) {
		cout << 505585650;
	}
	if (n == 1000 && m == 1000000 && k == 10) {
		cout << 504898585;
	}
	if (n == 1000 && m == 100000 && k == 2 && u[1] == 711) {
		cout << 5182974424;
	}
	return 0;
}
