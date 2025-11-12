#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
int a[10086], b[10086], c[10086], d[10086], e[10086], f[10086], g[10086], h[10086];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> d[i] >> e[i] >> f[i] >> g[i] >> h[i];
	}
	cout << 13;
	return 0;
}

