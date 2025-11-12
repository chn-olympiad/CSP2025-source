#include <bits/stdc++.h>
using namespace std;
long long t, n;
long long a[1000000], b[1000000], c[1000000], k[1000000], k1[1000000], k2[1000000];

int main() {
	freopen("club.in", "r", stdin);
	freopern("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		int c1 = 0, c2 = 0, c3 = 0, sum1 = 0, sum2 = 0, sum3 = 0;
		for (int j = 1; j <= n; j++) {
			cin >> a[i] >> b[i] >> c[i];
			if (a[i] > b[i] && a[i] > c[i])
				k[i] = 1;
			else if (b[i] > a[i] && b[i] > c[i])
				k[i] = 2;
			else if (c[i] > a[i] && c[i] > b[i])
				k[i] = 3;
			else if (a[i] > b[i] && a[i] < c[i] || a[i] > c[i] && a[i] < b[i])
				k1[i] = 1;
			else if (b[i] > a[i] && b[i] < c[i] || b[i] > c[i] && b[i] < a[i])
				k1[i] = 2;
			else if (c[i] > a[i] && c[i] < b[i] || c[i] > b[i] && c[i] < a[i])
				k1[i] = 3;
			else if (a[i] < b[i] && a[i] < c[i])
				k2[i] = 1;
			else if (b[i] < a[i] && b[i] < c[i])
				k2[i] = 2;
			else if (c[i] < b[i] && c[i] < a[i])
				k2[i] = 3;
			if (k[i] == 1 && c1 <= n / 2) {
				sum1 += a[i];
				c1++;
			} else if (k[i] == 2 && c2 <= n / 2) {
				sum2 += b[i];
				c2++;
			} else if (k[i] == 3 && c3 <= n / 2) {
				sum3 += c[i];
				c3++;
			} else if (k[i] == 1 && c1 > n / 2 && k1[i] == 2) {
				sum2 += b[i];
				c2++;
			} else if (k[i] == 1 && c1 > n / 2 && k1[i] == 3) {
				sum3 += c[i];
				c3++;
			} else if (k[i] == 2 && c2 > n / 2 && k1[i] == 1) {
				sum1 += a[i];
				c1++;
			} else if (k[i] == 2 && c2 > n / 2 && k1[i] == 3) {
				sum3 += c[i];
				c3++;
			} else if (k[i] == 3 && c3 > n / 2 && k1[i] == 1) {
				sum1 += a[i];
				c1++;
			} else if (k[i] == 3 && c3 > n / 2 && k1[i] == 2) {
				sum2 += b[i];
				c2++;
			} else if (k[i] == 1 && c1 > n / 2 && k1[i] == 2 && c2 > n / 2 && k2[i] == 3 || k[i] == 2 && c2 > n / 2 && k1[i] == 1
			           && c1 > n / 2 && k2[i] == 3) {
				sum3 += c[i];
				c3++;
			} else if (k[i] == 1 && c1 > n / 2 && k1[i] == 3 && c3 > n / 2 && k2[i] == 2 || k[i] == 3 && c3 > n / 2 && k1[i] == 1
			           && c1 > n / 2 && k2[i] == 2) {
				sum2 += b[i];
				c2++;
			} else if (k[i] == 3 && c3 > n / 2 && k1[i] == 2 && c2 > n / 2 && k2[i] == 1 || k[i] == 2 && c2 > n / 2 && k1[i] == 3
			           && c3 > n / 2 && k2[i] == 1) {
				sum1 += c[i];
				c1++;
			}
		}
		cout << sum1 + sum2 + sum3;
	}
	return 0;
}