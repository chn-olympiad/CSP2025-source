#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

bool cmp(int x, int y) {
	return x > y;
}
int t, a[N], b[N], c[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int f = 0, fl = 0;

		for (int i = 1; i <= n; i++) {

			cin >> a[i] >> b[i] >> c[i];

			if (b[i] != 0)
				f = 1;

			if (c[i] != 0)
				fl = 1;
		}

		if (n == 2) {
			int ans = max(max(c[1] + a[2], c[1] + b[2]), max(max(a[1] + b[2], a[1] + c[2]), max(b[1] + a[2], b[1] + c[2])));
			cout << ans;
			continue;
		} else if (f == 0 && fl == 0) {
			sort(a + 1, a + n + 1, cmp);
			int ans = 0;

			for (int i = 1; i <= n / 2; i++) {

				ans += a[i];
			}

			cout << ans;
			continue;
		} else {
			int ans = 0;

			for (int i = 1; i <= n; i++) {

				ans += max(a[i], max(b[i], c[i]));
			}

			cout << ans;
			continue;
		}
	}

	return 0;
}