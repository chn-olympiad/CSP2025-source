#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, j, i, tmp, imax, isum, k;
	long long sum = 0;
	cin >> n;

	int num[n];
	for (i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			if (num[i] > num[j]) {
				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		}
	}
	if (n = 3) {
		isum = 0;
		for (k = n - 1; k >= 0; k--) {
			isum += num[k];

		}
		if (num[n - 1] * 2 < isum) {
			cout << 1 << endl;
			return 0;
		} else {
			cout << 0 << endl;
			return 0;
		}
	}

	for (i = n - 1; i >= 2; i--) {
		for (j = i - 2; j >= 0; j--) {
			imax = num[i];
			isum = 0;
			for (k = i; k >= j; k--) {
				isum += num[k];
			}
			if (isum > imax * 2) {
				sum++;
			}

		}
	}
	cout << sum % 998244353 << endl;

	return 0;
}
