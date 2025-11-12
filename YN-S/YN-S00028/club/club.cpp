#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n, a[20005], b[20005], c[20005], ans = 0, sum[200005], cnt = 0, d, e;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> a[j] >> b[j] >> c[j];
			sum[j] = a[j] + b[j] + c[j];
			d += a[j];
			e += b[j];
			if (b[j] == 0 && c[j] == 0) {
				cnt++;
			} else {
				cnt = 0;
			}
			if (c[j] == 0) {
				ans++;
			} else {
				ans = 0;
			}
		}
		if (cnt == n) {
			sort(sum + 1, sum + n + 1);
			cout << sum[n] + sum[n - 1];
			continue;
		}
		if (ans == n) {
			sort(b + 1, b + n + 1);
			sort(a + 1, a + n + 1);
			cout << a[n] + a[n - 1] + b[n] + b[n - 1];
			continue;
		}
		if (n == 1) {
			cout << max(a[1], max(b[1], c[1]));
			continue;
		}
	}
	return 0;
}