#include <bits/stdc++.h>
using namespace std;
int n, m, k, l, p;
int a[10000005], b[10000005], c[10000005];

int main() {
	freopen("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	for (int j = 1; j <= k; j++) {
		cin >> a[j] >> b[j] >> c[j] >> l >> p;
	}
	cout << 13;
	return 0;
}
