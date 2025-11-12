#include <bits/stdc++.h>
using namespace std;
int zz[140];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int a, b, c, a1, a2, a3, ai1 = 0, ai2 = 0, ai3 = 0, g = 0, m;
	cin >> a;

	for (int j = 1; j <= a; j++) {

		cin >> b;
		int z[b] = {0, 0}, l1[b], l2[b], l3[b] ;

		for (int i = 0; i <= b - 1; i++) {

			cin >> a1 >> a2 >> a3;
			l2[i] = a2;
			l3[i] = a3;
			l1[i] = a1;

			if (ai1 >= b / 2) {
				if (a2 > a3) {
					z[i] = a2;
					ai2++;
				} else {
					z[i] = a3;
					ai3++;
				}
			} else if (ai2 >= b / 2) {
				if (a1 > a3) {
					z[i] = a1;
					ai1++;
				} else {
					z[i] = a3;
					ai3++;
				}
			} else if (ai3 >= b / 2) {
				if (a2 > a1) {
					z[i] = a2;
					ai2++;
				} else {
					z[i] = a1;
					ai1++;
				}
			} else if (a1 >= a2) {
				z[i] = a1;
			} else {
				z[i] = a2;
			}

			if (z[i] < a3) {
				z[i] = a3;
				ai3++;
			} else if (a1 >= a2) {
				ai1++;
			} else {
				ai2++;
			}

			if (a1 >= a2) {
				m = a1;
			} else {
				m = a2;
			}

			if (z[i] < a3) {
				m = a3;
			}

			for (int p = b - 1; p >= 0; p--) {

				if (z[p] + z[i] <= l1[p] + m) {
					ai1++;

					if (z[p] == l2[p]) {
						ai2--;
					} else {
						ai3--;
					}

					z[i] = m;
					z[p] = l1[p];
				}

				else if (z[p] + z[i] <= l2[p] + m) {
					if (z[p] == l1[p]) {
						ai1--;
					} else {
						ai3--;
					}

					z[i] = m;
					z[p] = l2[p];
					ai2++;
				}

				else if ( z[p] + z[i] <= l3[p] + m) {
					if (z[p] == l2[p]) {
						ai2--;
					} else {
						ai1--;
					}

					z[i] = m;
					z[p] = l3[p];
					ai3++;
				}
			}
		}

		for (int i = 0; i <= b - 1; i++) {

			g += z[i];
		}

		zz[j] = g;
	}

	for (int i = 1; i <= a ; i++) {

		cout << zz[i] - zz[i - 1] << endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}