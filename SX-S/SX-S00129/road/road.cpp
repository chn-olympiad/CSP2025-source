#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, total = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		total += c;
	}
	cout << total;
	return 0;
}
