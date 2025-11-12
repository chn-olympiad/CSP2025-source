#include <bits/stdc++.h>
using namespace std;
int a[10005], b[10005], n, m, q, d;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int c = 1, r = 1;
	cin >> n >> m;
	d = n * m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	for (int i = 2; i <= n * m; i++) {
		if (a[i] > a[i - 1]) {
			q = a[i - 1];
			a[i - 1] = a[i];
			a[i] = q;
		}
	}
//	for (int i = 1; i <= n * m; i++) {
//		cout << a[i] << endl;
//	}
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == b[1]) {
			d = i;
		}
	}
//	cout << d;
	if (d % n == 0) {
		c = d / n;
	}
	if (d % n != 0) {
		c = d / n + 1;
	}
	if (c % 2 != 0) {
		r = d - (n*(c - 1));
	}
	if (c % 2 == 0) {
		r = n - (d - (n*(c - 1))) + 1;
	}
	cout << c << " " << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}