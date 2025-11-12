#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
long long n, m, k, u[N], v[N], w[N], c[N], sum;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		sum += w[i];
	}
	for (int i = 1; i <= n + 1; i++) {
		cin >> c[i];
	}
	cout << sum;
	return 0;
}
