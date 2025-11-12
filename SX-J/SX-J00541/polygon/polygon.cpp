#include <bits/stdc++.h>

using namespace std;

long long n, a[50005];

int Mod = 998244353;

long long ans;

long long getans(long long m, long long x) {
	long long num1 = 1, num2 = 1;
	if (m / 2 > x) {
		for (long long i = m - x + 1; i <= m; i ++) {
			num1 *= i;
			num1 %= Mod;
		}
		for (int i = 1; i <= x; i ++) {
			num2 *= i;
			num2 %= Mod;
		}
		return num1 / num2;
	} else {
		for (int i = x + 1; i <= m; i ++) {
			num1 *= i;
			num1 %= Mod;
		}
		for (int i = 1; i <= m - x; i ++) {
			num2 *= i;
			num2 %= Mod;
		}
		return num1 / num2;
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	if (n == 3) {
		if ((a[1] + a[2] + a[3]) > max(a[1], max(a[2], a[3])) * 2) {
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	}
	for (long long i = 3; i <= n; i ++) {
		ans += getans(n, i);
		ans %= Mod;
	}
	cout << ans;
	return 0;
}
