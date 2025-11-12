#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[5005], he, mx, cnt;

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n < 3) {
		cout << 0;
		return 0;
	} else if (n == 3) {
		if (he > 2 * mx) {
			cout << 1;
		} else
			cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[j] + he > 2 * mx) {
				cnt++;
			} else {
				he += a[j];
			}
		}
	}
	cout << cnt;
	return 0;
}
