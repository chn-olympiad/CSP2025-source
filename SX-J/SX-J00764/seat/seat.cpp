#include <bits/stdc++.h>
using namespace std;
int s[1005];

int main() {
	freopen("number.in", "r", "stdin");
	freopen("number.out", "w", "stdout");
	int n, m, b, x = 1, y = 1, f;
	cin >> n >> m;
	int j = n * m;
	for (int i = 0; i < j; i++) {
		cin >> s[i];
	}
	b = s[0];
	for (int i = 0; i < j; i++) {
		if (s[i] < s[i + 1]) {
			f = s[i];
			s[i] = s[i + 1];
			s[i + 1] = f;
		}
	}
	for (int i = 0; i < j; i++) {
		if (y % 2 != 0) {
			if (b < s[i] && x < n) {
				x = x + 1;
			} else if (b < s[i] && x == n) {
				y = y + 1;
			} else if (b == s[i] && x <= n && x >= 1) {
				cout << y << " " << x;
			}
		} else {
			if (b < s[i] && x <= n && x > 1) {
				x = x - 1;
			} else if (b < s[i] && x == 1) {
				y = y + 1;
			} else if (b == s[i] && x <= n && x >= 1) {
				cout << y << " " << x;
			}
		}
	}

	return 0;
}
