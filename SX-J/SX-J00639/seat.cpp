#include <bits/stdc++.h>
using namespace std;
int a[105], n, m, s = 0, x;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	x = a[0];
	sort(a + 1, a + n *m + 1 );
	for (int i = n * m - 1; i >= 0; i--) {
		s++;
		if (a[i] == a[0]) {
			break;
		}
	}
	if (s % n == 0) {
		cout << n + 1 - n << " " << s / n;
	}
	if (s % n != 0) {
		cout << s % n << " " << n + 1 - s / n;
	}
	return 0;
}