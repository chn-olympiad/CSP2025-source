#include <bits/stdc++.h>
using namespace std;
int a[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m, ans = 1;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (a[i] > a[1]) {
			ans++;
		}
	}
	if (ans % n == 0) {
		cout << ans / n << " " << n;
	} else {
		if ((ans / n + 1 ) % 2 == 0) {
			cout << ans / n + 1 << " " << n - ans % n + 1;
		} else {
			cout << ans / n + 1 << " " << ans % n;
		}
	}
	return 0;
}
