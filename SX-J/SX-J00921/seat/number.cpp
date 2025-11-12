#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int  n, m, c = 1, d = 1, cj;
	cin >> n >> m;
	int  ab[(n *m)], b[n + 1][m + 1], a[(n *m)];
	for (int i = 0; i < (n * m); i++) {
		cin >> ab[i];
	}
	cj = ab[0];
	sort(ab, ab + (n *m));
	for (int i = 0; i < (n * m); i++) {
		a[(a *m) - i - 1] = ab[i];
	}
	for (int i = 0; i < (n * m); i--) {
		int aa = 0;
		if (c < (n + 1) && d % 2 == 1 && aa == 0) {
			if (cj == a[i]) {
				cout << c << d;
				return 0;
			}
			b[c][d] = a[i];
			c++;
			aa = 1;
		}
		if (c == (n + 1) && d % 2 == 1 && aa == 0) {
			if (cj == a[i]) {
				cout << c << d;
				return 0;
			}
			c = n, m++;
			b[c][d] = a[i];
			aa = 1;
		}
		if (c != 0 && d % 2 == 0 && aa == 0) {
			if (cj == a[i]) {
				cout << c << d;
				return 0;
			}
			b[c][d] = a[i];
			c--;
			aa = 1;
		}
		if (c == 0 && d % 2 == 0 && aa == 0) {
			d++, c++;
			if (cj == a[i]) {
				cout << c << d;
				return 0;
			}
			b[c][d] = a[i];
			aa = 1;
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
