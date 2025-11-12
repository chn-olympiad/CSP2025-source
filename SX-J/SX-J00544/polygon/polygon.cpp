#include <bits/stdc++.h>
using namespace std;
const int X = 998244353;
long long n, a[10005], mmax, tot, ans;
bool flag = 1;

int bb(long long k) {
	long long t = k, pos = n, a = 1, b = 1;
	while (t--) {
		a *= pos;
		a %= X, pos--;
	}
	t = k, pos = 1;
	while (t--) {
		b *= pos;
		b %= X, pos++;
	}
	return a / b;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1)
			flag = 0;
		mmax = max(mmax, a[i]);
		tot += a[i];
	}
	if (n == 3) {
		if (tot > 2 * mmax)
			cout << 1;
		else
			cout << 0;
	}

	else if (flag == 1) {
		for (int i = 3; i <= n; i++) {
			ans += bb(i);
			ans %= X;
		}
		cout << ans;
	} else
		cout << n;
	return 0;
}
