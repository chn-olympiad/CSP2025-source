#include <bits/stdc++.h>
using namespace std;
int n, sum = 0, a[5000];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n - 2; i++) {
		if (a[i] >= a[i + 1] && a[i] >= a[i + 2]) {
			if (a[i] + a[i + 1] + a[i + 2] > a[i] * 2) {
				sum++;
			}
		} else if (a[i + 1] >= a[i] && a[i + 1] >= a[i + 2]) {
			if (a[i] + a[i + 1] + a[i + 2] > a[i + 1] * 2) {
				sum++;
			}
		} else if (a[i + 2] >= a[i] && a[i + 2] >= a[i + 1]) {
			if (a[i] + a[i + 1] + a[i + 2] > a[i + 2] * 2) {
				sum++;
			}
		}
	}
	if (n > 3) {
		for (int i = 0; i < n - 3; i++) {
			if (a[i] >= a[i + 1] && a[i] >= a[i + 2] && a[i] >= a[i + 3]) {
				if (a[i] + a[i + 1] + a[i + 2] + a[i + 3] > a[i] * 2) {
					sum++;
				}
			} else if (a[i + 1] >= a[i] && a[i + 1] >= a[i + 2] && a[i + 1] >= a[i + 3]) {
				if (a[i] + a[i + 1] + a[i + 2] + a[i + 3] > a[i + 1] * 2) {
					sum++;
				}
			} else if (a[i + 2] >= a[i] && a[i + 2] >= a[i + 1] && a[i + 2] >= a[i + 3]) {
				if (a[i] + a[i + 1] + a[i + 2] + a[i + 3] > a[i + 2] * 2) {
					sum++;
				}
			} else if (a[i + 3] >= a[i] && a[i + 3] >= a[i + 1] && a[i + 3] >= a[i + 2]) {
				if (a[i] + a[i + 1] + a[i + 2] + a[i + 3] > a[i + 3] * 2) {
					sum++;
				}
			}
		}
	}
	if (n > 4) {
		for (int i = 0; i < n - 4; i++) {
			if (a[i] >= a[i + 1] && a[i] >= a[i + 2] && a[i] >= a[i + 3] && a[i] >= a[i + 4]) {
				if (a[i] + a[i + 1] + a[i + 2] + a[i + 3] + a[i + 4] > a[i] * 2) {
					sum++;
				}
			} else if (a[i + 1] >= a[i] && a[i + 1] >= a[i + 2] && a[i + 1] >= a[i + 3] && a[i + 1] >= a[i + 4]) {
				if (a[i] + a[i + 1] + a[i + 2] + a[i + 3] + a[i + 4] > a[i + 1] * 2) {
					sum++;
				}
			} else if (a[i + 2] >= a[i] && a[i + 2] >= a[i + 1] && a[i + 2] >= a[i + 3] && a[i + 2] >= a[i + 4]) {
				if (a[i] + a[i + 1] + a[i + 2] + a[i + 3] + a[i + 4] > a[i + 2] * 2) {
					sum++;
				}
			} else if (a[i + 3] >= a[i] && a[i + 3] >= a[i + 1] && a[i + 3] >= a[i + 2] && a[i + 3] >= a[i + 4]) {
				if (a[i] + a[i + 1] + a[i + 2] + a[i + 3] + a[i + 4] > a[i + 3] * 2) {
					sum++;
				}
			} else if (a[i + 4] >= a[i] && a[i + 4] >= a[i + 1] && a[i + 4] >= a[i + 2] && a[i + 4] >= a[i + 3]) {
				if (a[i] + a[i + 1] + a[i + 2] + a[i + 3] + a[i + 4] > a[i + 3] * 2) {
					sum++;
				}
			}
		}
	}
	cout << sum;
	return 0;
}
