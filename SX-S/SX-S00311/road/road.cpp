#include <bits/stdc++.h>
using namespace std;
#define int long long
int w[10005];

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, sum = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int a;
		cin >> a >> a >> w[i];
		sum += w[i];
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n + 1; j++) {
			int a;
			cin >> a;
		}
	}
	cout << sum;
	return 0;
}