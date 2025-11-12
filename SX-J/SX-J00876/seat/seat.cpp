# include <bits/stdc++.h>
using namespace std;
int a[10000], b[10000];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n, c, t, x;
	int p = 0;
	cin >> m >> n;
	c = m * n;
	if (c == 1)
		cout << m << " " << n;
	for (int i = 1; i <= c; i++) {
		int j;
		cin >> a[i];
		j = a[i];
		b[j] = j;
		if (i == 1) {

			t = j;
		}
	}
	for (int i = 100; i >= 1; i--) {
		if (b[i] == i)
			p++;
		if (b[i] == t)
			break;
	}
	int o, y;
	if (p % n != 0) {
		o = p / n + 1;
		y = p % n ;
		if (o % 2 == 0) {
			y = n + 1 - y;
		}
	}
	if (p % n == 0) {
		o = p / n;
		y = n;
	}
	cout << o << " " << y << " " << p;
	return 0;
}