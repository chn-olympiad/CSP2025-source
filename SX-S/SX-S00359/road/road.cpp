#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[1000010], b[1000010], c[1000010];
int f[10010], g[1000010], ans;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i] >> c[i];
		ans += c[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> f[i];
		for (int j = 1; j <= m; j++) {
			cin >> g[i];
		}
	}
	cout << ans;
	return 0;
}
