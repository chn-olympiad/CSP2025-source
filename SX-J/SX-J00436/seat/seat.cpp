#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", stdin);
	freopen("seat.out", stdout);
	int a, b, c, z, n, m;
	int d[100];
	cin >> a >> b;
	c = a * b;
	for (int i = 0; i < c; i++) {
		cin >> d[i];
		if (i == 0) {
			z = d[i];
		}
	}
	for (int i = 0; i < c; i++) {
		for (int j = i; j < c; j++) {
			if (d[i] < d[i + 1]) {
				int l[1];
				l[0] = d[i + 1];
				d[i + 1] = d[i];
				d[i] = l[0];
			}
		}
	}
	for (int i = 0; i < c; i++) {
		if (d[i] == z) {
			n = i + 1;
			m = n / a + 1;
			if (n > 2 && m % 2 == 0) {
				while (n >= a) {
					n = n / a;
				}
				n = a - n + 1;
			} else if (n % a != 0) {
				n = n % a;
			} else {
				n = a;
				m -= 1;
			}
		}
	}
	cout << m << " " << n;
	return 0;
}
