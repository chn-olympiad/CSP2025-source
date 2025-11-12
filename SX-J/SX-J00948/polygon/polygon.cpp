#include <bits/stdc++.h>
using namespace std;
int a[5010], n;
long long ans = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 3) {
		sort(a, a + n);
		if (a[1] + a[2] > a[3]) {
			ans = 1;
		} else {
			ans = 0;
		}

	} else {
		for (int i = 4; i <= n; i++) {
			ans += i * (n - i) + 1;

		}
	}
	cout << ans % 998244353;
	return 0;
}
