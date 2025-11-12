#include <bits/stdc++.h>
using namespace std;
long long a[5010];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n, s = 0, maxx = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 3) {
		for (int i = 1; i <= n; i++) {
			s = s + a[i];
			maxx = max(maxx, a[i]);
		}
		if (maxx * 2 < s) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		for (int i = 3; i <= n; i++) {
			if (i == 3) {
				for (int j = i - 2; j <= n; j++) {
					s = s + ((n - j) * (n - j - 1)) / 2;
				}
			} else {
				for (int j = i - 2; j <= n; j++) {
					if (j != i - 2) {
						s = s + ((((n - j) * (n - j - 1)) / 2) * (j - 1));
					} else {
						s = s + ((n - j) * (n - j - 1)) / 2;
					}

				}
			}
		}
		cout << s;
	}
	return 0;
}
