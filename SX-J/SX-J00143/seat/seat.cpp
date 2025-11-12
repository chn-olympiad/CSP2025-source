#include <bits/stdc++.h>
using namespace std;


int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);
	int n, m, a[150], sum, k ;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		sum = a[1];

	}
	for (int i = 1; i <= n * m; i++) {
		for (int j = 1; j <= i; j++) {
			if (a[j] < a[j + 1]) {
				swap(a[j + 1], a[j]);
			}
		}
	}
	for (int i = 1; i <= n * m; i++) {
		if (sum == a[i]) {
			k = i;
		}
	}
	if (k <= n) {
		cout << "1" << " " << k;
	} else if (k > n && k <= n * 2) {
		cout << "2" << " " << k - n;
	} else if (k > n && k >= n * 2 && k <= n * 3) {
		cout << "3" << " " << k - 2 * n;
	} else if (k > n && k >= n * 3 && k <= n * 4) {
		cout << "4" << " " << k - 3 * n;
	} else if (k > n && k >= n * 4 && k <= n * 5) {
		cout << "5" << " " << k - 4 * n;
	} else if (k > n && k >= n * 5 && k <= n * 6) {
		cout << "6" << " " << k - 5 * n;
	} else if (k > n && k >= n * 6 && k <= n * 7) {
		cout << "7" << " " << k - 6 * n;
	} else if (k > n && k >= n * 7 && k <= n * 8) {
		cout << "8" << " " << k - 7 * n;
	} else if (k > n && k >= n * 9 && k <= n * 9) {
		cout << "9" << " " << k - 8 * n;
	} else if (k > n && k >= n * 9 && k <= n * 10) {
		cout << "10" << " " << k - 9 * n;
	}

	return 0;
}