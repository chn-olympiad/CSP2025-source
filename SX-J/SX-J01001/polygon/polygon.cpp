#include <bits/stdc++.h>
using namespace std;
int a[50009];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int maxx = -1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	if (n == 3) {
		sort(a + 1, a + n + 1);
		if (a[1] + a[2] > a[3]) {
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	} else if (maxx == 1) {
		long long h = 0;
		int sl = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) {
				sl++;
			} else {
				for (int i = sl - 2; i >= 1; i--) {
					h += i;
					h %= 998244353;
				}
			}
		}
		cout << h;
		return 0;
	}
	long long ans = 0;
	for (int i = 1; i <= n - 2; i++) {
		for (int j = i + 2; j <= n; j++) {
			int h = 0, z = 0;
			for (int t = i; t <= j; t++) {
				if (a[t] > z) {
					z = a[t];
				}
				h += a[t];
			}
			if (2 * z < h) {
				ans++;
				ans %= 998244353;
				//cout << i << " " << j << endl;
			}
		}
	}
	cout << ans;
	return 0;
}
