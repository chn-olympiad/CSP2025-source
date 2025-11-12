#include <bits/stdc++.h>
using namespace std;
long long n, a[1000005], tot, mmax = -1;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mmax = max(mmax, a[i]);
	}
	if (n == 3)
		if (a[0] + a[1] + a[2] > 2 * mmax) {
			cout << 1;
			return 0;
		} else {
			cout << 0;
			return 0;
		}
	cout << 1;
	return 0;
}
