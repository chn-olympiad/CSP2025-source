#include <bits/stdc++.h>
using namespace std;
int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int c, b;
	cin >> b >> c;
	for (int i = 1; i <= b * c; i++) {
		cin >> a[i];
	}
	int d = b * c, m = 0, n = a[1];
	sort(a, a + d + 1);
	for (int i = 1; i <= b * c; i++) {
		if (a[i] != n) {
			m++;
		}
	}
	int y = b - m;
	if (m % 2 != 0) {
		cout << m << " " << y;
	} else {
		cout << m << " " << b - y;
	}
	return 0;
}