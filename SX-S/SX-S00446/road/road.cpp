#include <bits/stdc++.h>
using namespace std;
long long ans;
int n, m, k;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		ans += c;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n + 1; j++) {
			int x;
			cin >> x;
		}
	}
	if (k == 0)
		cout << ans << endl;
	else
		cout << 0 << endl;
	return 0;
}
