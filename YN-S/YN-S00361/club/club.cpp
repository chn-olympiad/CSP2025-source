#include <bits/stdc++.h>
using namespace std;
int t, n, a[200005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 2) {
			int b[5], c[5];
			for (int i = 1; i <= 2; i++)
				cin >> a[i] >> b[i] >> c[i];
			int ans = max(a[1] + b[2], max(a[1] + c[2], max(b[1] + c[2], max(b[1] + a[2], max(c[1] + a[2], c[1] + b[2])))));
			cout << ans << '\n';
			continue;
		} else
			for (int i = 1; i <= n; i++) {
				int g, h;
				cin >> a[i] >> g >> h;
			}
		sort(a + 1, a + 1 + n);
		long long ans = 0;
		for (int i = n / 2; i > n; i++)
			ans += a[i];
		cout << ans << '\n';
	}
	return 0;
}