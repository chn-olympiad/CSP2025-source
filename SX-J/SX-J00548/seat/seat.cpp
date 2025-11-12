#include <bits/stdc++.h>
using namespace std;
int n, m, a[100010], c, b, j, x;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	j = n * m;
	for (int i = 1; i <= j; i++) {
		cin >> a[i];
	}
	c = a[1];
	sort(a + 1, a + j + 1);
	for (int i = j; i >= 1; i--) {
		x++;
		if (a[i] == c)
			break;
	}
	if (x <= n) {
		cout << '1' << " " << x;
		return 0;
	} else if (m == 1 && n == 1) {
		cout << '1' << " " << '1';
		return 0;
	}
	int d = x / n;
	if (x % n == 0 && d % n == 0) {
		cout << d << " " << '1';
	}
	return 0;
}