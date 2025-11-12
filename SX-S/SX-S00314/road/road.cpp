#include <bits/stdc++.h>
using namespace std;
int n, m, k, c, ans;

int a[10086] = {0}, b[5] = {0}, ccc[10086] = {0};

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	int vva = n + n - 2 ;
	int xy = vva - m;
	for (int i = 1; i <= m; i++) {
		int u = 0, v = 0, w = 0;
		cin >> u >> v >> w;
		a[i] = w;
	}
	sort(a + 1, a + 1 + n);
	for (int j = 1; j <= xy; j++) {
		ans += a[j];
	}

	for (int h = 1; h <= k; h++) {
		cin >> c >> b[1] >> b[2] >> b[3] >> b[4];
		ccc[h] = c;
	}
	sort(ccc + 1, ccc + 1 + k);
	sort(b + 1, b + 1 + n);
	ans += ccc[1];
	for (int i = 1; i <= xy; i++) {
		ans += b[i];
	}
	cout << ans;


	return 0;
}
