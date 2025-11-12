#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, a[5005], mmax = INT_MAX, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			for (int k = 1; k <= j; k++) {
				if (a[i] + a[j] + a[k] > 2 * mmax)
					cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}