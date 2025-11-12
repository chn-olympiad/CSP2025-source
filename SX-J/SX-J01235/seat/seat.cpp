#include <bits/stdc++.h>
using namespace std;
int d[101];

int main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int a, b, c, e, f, g, m, n;
	cin >> a >> b;
	c = a * b;
	for (int i = 1; i <= c; i++) {
		cin >> d[i];
	}
	g = d[1];
	for (int i = 2; i <= c; i++) {
		for (int j = 1; j < i; j++) {
			if (d[j] < d[i]) {
				e = d[j];
				d[j] = d[i];
				d[i] = e;
				i = 1;
			}
		}
	}
	for (int i = 1; i <= c; i++) {
		if (d[i] == g)
			f = i;
	}
	m = f / a;
	n = f % a;
	if (n == 0) {
		if (m % 2 == 0) {
			cout << m << " " << 1;
			return 0;
		}
		if (m % 2 == 1) {
			cout << m << " " << a;
			return 0;
		}
	}
	if (m % 2 == 0) {
		cout << m + 1 << " " << n;
		return 0;
	}
	if (m % 2 == 1) {
		cout << m + 1 << " " << a + 1 - n;
		return 0;
	}
	return 0;
}
