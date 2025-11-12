#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a[100], e, a1 = 0;
	cin >> n >> m;
	e = m * n;
	for (int i = 0; i < e; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < e - 1; i++) {
		for (int y = e - 1; y > i; y--) {
			if (a[y] > a[y - 1]) {
				if (a1 == y) {
					a1 = y - 1;
				}

				if (a1 == y - 1) {
					a1 = y;
				}
				swap(a[y], a[y - 1]);
			}
		}
	}
	a1++;
	int n1, m1;
	if (a1 % n == 0)
		m1 = a1 / n;
	else
		m1 = a1 / n + 1;
	if (m1 % 2 == 1)
		n1 = a1 - n * (m1 - 1);
	else
		n1 = n + 1 - (a1 - n * (m1 - 1));
	if (n1 == 0)
		n1 = n;
	if (m1 == 0)
		m1 = m;
	cout << m1 << " " << n1;
	return 0;
}
