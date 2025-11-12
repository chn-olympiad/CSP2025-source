#include <bits/stdc++.h>
using namespace std;
int a[500005], b[500005][20], c[500005][20], d[20];

int main() {
	int n, k;
	cin >> n >> k;
	long long h = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		h = 1;
		for (int j = 1; j <= 21; j++) {
			b[i][j] = (a[i] ) % 2;
			a[i] /= 2;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 20; j++) {
			c[i][j] = c[i - 1][j] + b[i][j];
		}
	}
	h = 1;
	for (int i = 1; i <= 21; i++) {
		d[i] = (k ) % 2;
		k /= 2;
	}
	int f = 0;
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			f = 1;
			for (int l = 1; l <= 20; l++) {
				if (d[l] % 2 != (c[j][l] - c[i - 1][l]) % 2) {
					f = 0;
					break;
				}
			}
			if (f == 1) {
				sum++;
			}
		}
	}
	cout << sum;
}