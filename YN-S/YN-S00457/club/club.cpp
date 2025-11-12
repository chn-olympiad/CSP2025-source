#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int t, n;
int a[N][3];
int b[N][3];
int x[N], z[N], y[N];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	while (t--) {
		cin >> n;

		for (int i = 1; i <= n; i++) {

			for (int j = 1; j <= 3; j++) {

				cin >> a[i][j];
			}
		}

		int f1 = 1, f2 = 1, f3 = 1, sum = 0;

		for (int i = 1; i <= n; i++) {

			if (a[i][1] > a[i][2] && a[i][1] > a[i][3]) {
				b[f1][1] = a[i][1];
				f1++;
			} else if (a[i][2] > a[i][1] && a[i][2] > a[i][3]) {
				b[f2][2] = a[i][2];
				f2++;
			} else {
				b[f3][3] = a[i][3];
				f3++;
			}
		}

		for (int i = 1; i <= max(f1, max(f2, f3)); i++) {

			x[i] = b[i][1];
			y[i] = b[i][2];
			z[i] = b[i][3];
		}

		sort(x + 1, x + f1, cmp);
		sort(y + 1, y + f2, cmp);
		sort(y + 1, y + f3, cmp);
		f1--;
		f2--;
		f3--;

		for (int i = 1; i <= n  ; i++) {

			if (f1 > n / 2) {
				if (f2 < n / 2 && f3 < n / 2) {
					sum = sum - x[i] + x[i + 1] + max(a[i][2], a[i][3]);
					f1--;

					if (a[i][2] > a[i][3]) {
						f2++;
					}

					else {
						f3++;
					}


				}

				else if (f2 < n / 2) {
					sum = sum - x[i] + x[i + 1] + a[i][2];
					f2++;
					f1--;
				}

				else if (f3 < n / 2) {
					sum = sum - x[i] + x[i + 1] + a[i][3];
					f3++;
					f1--;
				}

			} else if (f2 > n / 2) {

				if (f1 < n / 2 && f3 < n / 2) {
					sum = sum - y[i] + y[i + 1] + max(a[i][1], a[i][3]);
					f2--;

					if (a[i][1] > a[i][3]) {
						f1++;

					}

					else {
						f3++;
					}

				}

				else if (f1 < n / 2) {
					sum = sum - y[i] + y[i + 1] + a[i][1];
					f1++;
					f2--;
				}

				else if (f3 < n / 2) {
					sum = sum - y[i] + y[i + 1] + a[i][3];
					f3++;
					f2--;
				}


			} else if (f3 > n / 2) {

				if (f2 < n / 2 && f1 < n / 2) {
					sum = sum - z[i] + z[i + 1] + max(a[i][2], a[i][1]);
					f3--;

					if (a[i][2] > a[i][1]) {
						f2++;

					}

					else {
						f1++;
					}

				}

				else if (f2 < n / 2) {
					sum = sum - z[i] + z[i + 1] + a[i][2];
					f2++;
					f3--;
				}

				else if (f1 < n / 2) {
					sum = sum - z[i] + z[i + 1] + a[i][1];
					f1++;
					f3--;
				}

			}



		}


		for (int i = 1; i <= n / 2; i++) {

			sum += x[i] + y[i] + z[i];
		}

		for (int i = 1; i <= n; i++) {

			b[i][1] = 0;
			b[i][2] = 0;
			b[i][3] = 0;
			x[i] = 0;
			y[i] = 0;
			z[i] = 0;
		}

		cout << sum << endl;
	}

	return 0;
}