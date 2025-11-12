#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n, a[N], b[N], c[N], s = 0, ans = 0;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			if (a[i] != 0 && s == 0) {
				s = 1;
			}
			if (b[i] != 0 && s == 0) {
				s = 2;
			}
			if (c[i] != 0 && s == 0) {
				s = 3;
			}
		}
		if (s == 1) {
			sort(a, a + n);
			for (int i = n / 2; i < n; i++) {
				ans += a[i];
			}
		}
		if (s == 2) {
			sort(b, b + n);
			for (int i = n / 2; i < n; i++) {
				ans += b[i];
			}
		}
		if (s == 3) {
			sort(c, c + n);
			for (int i = n / 2; i < n; i++) {
				ans += c[i];
			}
		}
		cout << ans << endl;
	}

	return 0;
}