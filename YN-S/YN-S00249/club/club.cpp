#include <bits/stdc++.h>
using namespace std;
int a[100001][2];

int c[100001] = {0};;

int s[5] = {0};

int b[20] = {0};

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, sum = 0, d;
	cin >> t;

	for (int i = 0; i < t; i++) {

		cin >> n;

		for (int j = 0; j < n; j++) {

			for (int l = 0; l < 3; l++) {

				cin >> a[j][l];
			}
		}

		for (int j = 0; j < n; j++) {

			if (s[0] < n / 2) {
				for (int x = 0; x < n; x++) {

					if (a[j][0] < a[x][0]) {
						sum++;
					}
				}

				if (a[j][0] >= a[j][1] && a[j][0] >= a[j][2] && sum < (n / 2)) {
					b[i] += a[j][0];
					s[0]++;
					s[1] += n;
					s[2] += n;
				}

				sum = 0;
			}

			if (s[1] < n / 2) {
				for (int x = 0; x < n; x++) {

					if (a[j][1] < a[x][1]) {
						sum++;
					}
				}

				if (a[j][1] >= a[j][2] && (sum < (n / 2))) {
					b[i] += a[j][1];
					s[1]++;
					s[2] += n;
				}

				sum = 0;
			}

			if (s[1] >= n) {
				s[1] -= n;
			}

			if (s[2] >= n) {
				s[2] -= n;
			}

			if (s[2] < (n / 2)) {
				for (int x = 0; x < n; x++) {

					if (a[j][2] < a[x][2]) {
						sum++;
					}
				}

				if  (sum <= (n / 2)) {
					b[i] += a[j][2];
					s[2]++;
					c[j] = 1;
				}

				sum = 0;
			}

			if (c[j] == 0) {
				if (a[j][0] > a[j][1] && a[j][0] > a[j][2]) {
					b[i] += a[j][0];
					s[0]++;
				} else if (a[j][1]  > a[j][2] && a[j][1] > a[j][0]) {
					b[i] += a[j][1];
					s[1]++;
				} else if (a[j][2] > a[j][0] && a[j][2] > a[j][1]) {
					b[i] += a[j][2];
					s[2]++;
				}

			}

		}
	}

	for (int i = 0; i < t; i++) {

		cout << b[i] << endl;
	}

	return 0;
}
