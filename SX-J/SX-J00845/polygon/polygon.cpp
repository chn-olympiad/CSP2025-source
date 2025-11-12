#include <bits/stdc++.h>
using namespace std;
long long n, a[5015];
long long su;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long ma = 0, s = 0;
	if (n == 3) {
		for (int i = 1; i <= n; i++) {
			if (ma < a[i]) {
				ma = a[i];
			}
			s += a[i];
		}
		if (s > 2 * ma) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	return 0;
}