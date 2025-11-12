#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int m, n, k, a[N], ans;

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>  n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		ans += c;
	}
	for (int i = 1; i <= k; i++) {
		int c;
		cin >> c;
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
		}
	}
	cout << ans;
	return 0;
}