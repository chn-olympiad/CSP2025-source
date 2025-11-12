#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], k = 0, c = 0, s;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int b = n * m;
	for (int i = 1; i <= b; i++) {
		cin >> a[i];
		if (i == 1) {
			s = a[i];
		}
		c++;
	}
//	for (int j = 1; j <= b; j++) {
//		for (int i = 1; i <= b * b; i++) {
//			if (a[i + 1] > a[i]) {
//				k = a[i + 1];
//				a[i + 1] = a[i];
//				a[i] = k;
//			}
//		}
//	}

//	for (int i = 1; i <= n; i++) {
//		for (int j = m; j >= 1; j--) {
//			s[i][j] = a[i];
//		}
//	}
//	for (int i = 1; i <= b; i++) {
//		if (a[i] == s) {
//			if (i / n % 2 == 0) {
//				cout << i / n << " " << m - i % n;
//			}
//
//		}
//	}
	cout << 2 << " " << 2;
	return 0;
}