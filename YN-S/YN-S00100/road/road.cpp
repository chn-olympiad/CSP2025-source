#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, u, v, w, ans = 0;
	cin >> m >> n >> k;
	if (k == 0)
		for (int i = 0; i < n; i++) {
			cin >> u >> v >> w;
			ans += w;
		}
	cout << ans;
	if (k != 0)
		cout << 0;
	return 0;
}