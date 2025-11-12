#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], s[110], r, c, sl[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int ln = n * m - 1;
	for (int i = 0; i <= ln; i++) {
		cin >> a[i];
		sl[i] = a[i];
	}
	sort(sl, sl + ln + 1);
	for (int i = ln; i >= 0; i--) {
		s[ln - i] = sl[i];
	}
	for (int j = 0; j <= ln ; j++) {
		cout << s[j] << ' ';
		int i = j + 1;
		if (s[j] == a[0]) {
			if (i % n == 0 && (i / n) % 2 == 1)
				r = n;
			else if (i % n == 0 && (i / n) % 2 == 0)
				r = 1;
			else if (i % n != 0 && (i / n + 1) % 2 == 1)
				r = i % n;
			else
				r = n - i % n;
			if (i % n != 0) {
				c = i / n + 1;
			} else {
				c = i / n;
			}
		}
	}
	cout << c << ' ' << r;
	return 0;
}