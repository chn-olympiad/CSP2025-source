#include <bits/stdc++.h>
using namespace std;
int t, n, a1[100], a[100], b[100], c[100], l = 0, p = 0, m = 0, q1 = 0, k = 0, z = 0;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		if (n % 2 == 0) {
			for (int j = 0; j < n; j++) {
				cin >> a1[0] >> a1[1] >> a1[2];
				a[q1] = a1[0];
				b[q1] = a1[1];
				c[q1] = a1[2];
				q1++;
				if (a[k] > b[k] && a[k] > c[k]) {
					l++;
					//if (l != n / 2) {
					//cout << a[k] << "p" << endl;
					if (l <= n / 2) {
						z = z + a[k];
					} else if (p + 1 <= n / 2 && b[k] > c[k] || b[k] == c[k] && p + 1 <= n / 2) {
						z = z + b[k];
					} else if (m + 1 <= n / 2) {
						z = z + c[k];
					}
					//}
				}
				if (a[k] < b[k] && b[k] > c[k]) {
					p++;
					//if (p != n / 2) {

					if (p <= n / 2) {
						z = z + b[k];
					} else if (l + 1 <= n / 2 && a[k] > c[k] || a[k] == c[k] && l + 1 <= n / 2) {
						z = z + a[k];
					} else if (m + 1 <= n / 2) {
						z = z + c[k];
					}
					//cout << lp << "w" << endl;
					//}
				}
				if (c[k] > b[k] && a[k] < c[k]) {
					m++;
					//if (m != n / 2) {

					//cout << c[k] << " r" << endl;
					if (m <= n / 2) {
						z = z + c[k];
						//		cout << c[k] << "t" << endl;
					} else if (m + 1 <= n / 2 && a[k] > b[k] || a[k] == b[k] && m + 1 <= n / 2) {
						z = z + a[k];
					} else if (p + 1 <= n / 2) {
						z = z + b[k];
					}
					//}
					//cout << lp;
				}
				k++;
				m = 0;
				p = 0;
				l = 0;
			}
			cout << z << endl;
			z = 0;
		} else {
			return 0;
		}

	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}