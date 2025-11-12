#include <bits/stdc++.h>
using namespace std;

int n, a[5005], maxn;
const long long mod = 998244353;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	if (n < 3) {
		cout << 0;
	} else if (n == 3) {
		if (a[1] + a[2] + a[3] > maxn * 2) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		long long sum = 0;
		for (int i = 3; i <= n; i++) {
			long long m = 1, f = 1;
			for (int j = 1; j <= i; j++) {
				m *= j;
			}
			for (int j = n - (i - 1); j <= n; j++) {
				f *= j;
			}
			sum += f / m % mod;
		}
		cout << sum % mod;
	}

	return 0;
}
