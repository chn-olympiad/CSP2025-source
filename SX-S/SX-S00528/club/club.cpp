#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5+5;
long long t, n, a[N][4], sum1, sum2, sum3, ans, b[N], c[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		sum1 = sum2 = sum3 = ans = 0;
		cin >> n;
		for (long long i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			long long tot = max(a[i][1], max(a[i][2], a[i][3]));
			if (tot == a[i][1]) {
				sum1++;
				b[i] = 1;
			} else if (tot == a[i][2]) {
				sum2++;
				b[i] = 2;
			} else {
				sum3++;
				b[i] = 3;
			}
			ans += tot;
		}
		if (sum1 <= n / 2 && sum2 <= n / 2 && sum3 <= n / 2) {
			cout << ans << endl;
			continue;
		}
		long long aa;
		if (sum1 > n / 2)
			aa = 1;
		if (sum2 > n / 2)
			aa = 2;
		if (sum3 > n / 2)
			aa = 3;
		for (long long i = 1; i <= n; i++) {
			long long x, y;
			if (b[i] != aa) {
				c[i] = 1e18;
				continue;
			}
			if (b[i] == 1) {
				x = 2;
				y = 3;
			} else if (b[i] == 2) {
				x = 1;
				y = 3;
			} else {
				x = 1;
				y = 2;
			}
			c[i] = min(a[i][b[i]] - a[i][x], a[i][b[i]] - a[i][y]);
		}
		sort(c + 1, c + n + 1);
		for (long long i = 1; i <= max(sum1, max(sum2, sum3)) - n / 2; i++)
			ans -= c[i];
		cout << ans << endl;
	}
	return 0;
}
