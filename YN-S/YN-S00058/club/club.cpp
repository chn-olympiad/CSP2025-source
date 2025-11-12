#include <bits/stdc++.h>
using namespace std;
long long arr[100010][4];
long long t, n;
long long ans;

void check(long long a, long long b, long long c, long long top, long long sum) {
	long long x = 0, y = 0, z = 0;
	if (top == n) {
		if (a > 0) {
			x = arr[top][1];
		}
		if (b > 0) {
			y = arr[top][2];
		}
		if (c > 0) {
			z = arr[top][3];
		}
		ans = max(ans, sum + max(x, max(y, z)));
		return ;
	}
	if (a > 0) {
		check(a - 1, b, c, top + 1, sum + arr[top][1]);
	}
	if (b > 0) {
		check(a, b - 1, c, top + 1, sum + arr[top][2]);
	}
	if (c > 0) {
		check(a, b, c - 1, top + 1, sum + arr[top][3]);
	}
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (long long i = 1; i <= n; i++) {
			cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
		}
		ans = 0;
		check(n / 2, n / 2, n / 2, 1, 0);
		cout << ans << endl;
	}
	return 0;
}