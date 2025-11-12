#include <bits/stdc++.h>
using namespace std;
int n, m, a[1010], r, wc;

bool cmp(int a, int b) {
	return a >= b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	r = a[0];
	sort(a, a + m *n, cmp);
	for (int i = 0; wc == 0; i++) {
		if (a[i] == r) {
			wc = i + 1;
		}
	}
	if ((wc / n) % 2 == 0) {
		if (wc % n == 0) {
			cout << wc / n << " " << 1;
		} else {
			cout << wc / n + 1 << " " << wc % n;
		}
	} else {
		if (wc % n == 0) {
			cout << wc / n << " " << n;
		} else {
			cout << wc / n + 1 << " " << n - wc % n + 1;
		}
	}
	return 0;
}
