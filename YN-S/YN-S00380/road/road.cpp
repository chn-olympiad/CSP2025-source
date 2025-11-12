#include <bits/stdc++.h>
using namespace std;
int n, m, t, ans = 1;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	while (t <= ans) {
		cin >> n >> m;
		if (n ^ m == 0) {
			ans++;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}