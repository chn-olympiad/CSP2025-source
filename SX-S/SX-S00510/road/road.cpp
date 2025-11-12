#include <bits/stdc++.h>
using namespace std;
long long n, m, k, x, y, z, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> z;
		ans += z;
	}
	cout << ans;
	return 0;
}
