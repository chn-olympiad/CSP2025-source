#include <bits/stdc++.h>
using namespace std;
int m, n, x = 0, suum = 0;

int yh(int a, int b) {
	int c, mn = 1;
	c = 0;
	while (a != 0 || b != 0) {
		int d = a % 10, e = b % 10;
		a /= 10;
		b /= 10;
		if (d != e) {
			c += 1 * mn;
		}
		mn *= 10;
		9 *
	}
	return c;
}

int zh(int a) {
	int sum = 0, mn = 1;
	while (a != 0) {
		sum = sum + (a % 2) * mn;
		mn *= 10;
		a /= 2;
	}
	return sum;
}

int hz(int a) {
	int sum = 0, mn = 1;
	while (a != 0) {
		sum += a % 10 * mn;
		mn *= 2;
		a /= 10;
	}
	return sum;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		int s;
		cin >> s;
		if (hz(yh(zh(s), zh(x))) == n) {
			suum++;
			x = 0;
		} else if (hz(yh(zh(s), zh(x))) != n) {
			x = hz(yh(zh(s), zh(x)));
		}
	}
	cout << suum;
	return 0;
}
