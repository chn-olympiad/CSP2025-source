#include <bits/stdc++.h>
using namespace std;
int a[1100];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, b, c;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		b = a[1];
	}
	sort(a + 1, a + n + 1);
	b = a[c];
	for (int i = 1; i <= n * m; i++) {
		if (n == 1 && m == 1 || c == 1) {
			cout << 1 << " " << 1;
		}
		if (n == 1 && m != 1) {
			cout << 1 << " " << c;
		}
		if (m == 1 && n != 1) {
			cout << c << " " << 1;
		}
		if (n > 1 && c % m == 1) {
			cout << (c / m) + 1 << " " << 2;
		}
		if (n > 1 && c % m == 0) {
			cout << (c / m) + 1 << " " << 1;
		}
	}
	return 0;
}
