#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[1000006];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y >> a[i];
	}
	sort(a + 1, a + 1 + m);
	long long ans = 0;
	for (int i = 1; i < n; i++)
		ans += a[i];
	cout << ans;
	return 0;
}