#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[1000010], b[1000010], c[1000010], ans = 0, p;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> b[i];
		cin >> c[i];
		ans = ans + c[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		cin >> b[i];
		cin >> c[i];
		cin >> p;
		ans = ans + c[i] + p;
	}
	cout << ans;
	return 0;
}
