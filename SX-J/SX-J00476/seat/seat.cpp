#include <bits/stdc++.h>
using namespace std;
int a[110];

int mad(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m, s;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s = a[1];
	}

	if (n == 1) {
		sort(a + 1, a + n + 1, mad);
		for (int i = 1; i <= n; i++) {
			if (a[i] == s) {
				cout << 1 << " " << i;
			}
		}
		return 0;
	}

	if (m == 1) {
		sort(a + 1, a + m + 1, mad);
		for (int i = 1; i <= m; i++) {
			if (a[i] == s) {
				cout << i  << " " << 1;
			}
		}

	}
	return 0;
}
