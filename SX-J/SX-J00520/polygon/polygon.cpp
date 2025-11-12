#include <bits/stdc++.h>
using namespace std;
long long n, a[5005], mmax = INT_MIN, p, sum;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				for (int m = 1; m <= 3; m++) {
					mmax = max(a[i], max(a[j], a[k]));
					p = a[i] + a[j] + a[k];
					if (mmax * 2 < p) {
						sum++;
					}
				}
			}
		}
	}
	sum = sum % 998;
	sum = sum % 244;
	sum = sum % 353;
	cout << sum / 3;
	return 0;
}
