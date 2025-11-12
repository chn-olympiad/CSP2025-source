#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], mmax, x, cnt = 1, v = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	x = n * m;
	for (int i = 1; i <= x; i++) {
		cin >> a[i];
		if (a[i] > mmax) {
			mmax = a[i];
		}
	}
	if (mmax == a[1]) {
		cout << 1 << " " << 1;
	} else {
		for (int j = mmax; j > a[1]; j--) {
			cnt++;
		}
		if (cnt < n) {
			cout << 1 << " " << cnt;
		} else if (cnt == n) {
			cout << 1 << " " << n;
		} else {
			v += cnt / n;
			cout << v << " " << cnt % n;
		}
	}
}