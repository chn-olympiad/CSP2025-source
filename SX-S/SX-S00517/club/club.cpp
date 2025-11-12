#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y) {
	return x > y;
}

int t;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int a[100005] = {}, b[100005] = {}, c[100005] = {}, sum = 0, maxnc = 0, d[100005] = {}, n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			d[i] = max(max(a[i], b[i]), c[i]);
			maxnc = max(maxnc, c[i]);
		}
		sort(a + 1, a + 1 + n, cmp);
		sort(b + 1, b + 1 + n, cmp);
		sort(c + 1, c + 1 + n, cmp);
		if (maxnc == 0) {
			for (int i = 1; i <= 3; i++) {
				if (i == 1) {
					for (int j = 1; j <= n / 2; j++) {
						sum += a[j];
					}
				}
				if (i == 2) {
					for (int j = 1; j <= n / 2; j++) {
						sum += b[j];
					}
				}
				if (i == 3) {
					for (int j = 1; j <= n / 2; j++) {
						sum += c[j];
					}
				}
			}

		} else {
			for (int i = 1; i <= n; i++) {
				sum += d[i];
			}
		}
		cout << sum << endl;
	}
	return 0;
}
