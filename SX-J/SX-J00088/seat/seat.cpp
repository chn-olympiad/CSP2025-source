#include <bits/stdc++.h>
using namespace std;

int cmp(int &x, int &y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int a[1001], b[1001];
	int n, m, s, l;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == b[1]) {
			s = i;
			break;
		}
	}
	l = (s - 1) / n;
	if (l % 2 == 0) {
		if (s % n != 0) {
			cout << l + 1 << " " << s % n;
		} else {
			cout << l + 1 << " " << n;
		}
	} else {
		if (s % n == 0) {
			cout << l + 1 << " " <<  1;
		} else {
			cout << l + 1 << " " <<  n - (s % n - 1);
		}
	}
	return 0;
}
