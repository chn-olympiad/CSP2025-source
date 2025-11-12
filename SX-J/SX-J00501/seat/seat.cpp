#include <bits/stdc++.h>
using namespace std;
int n, m, a[120], a1, cnt = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a1;
	a[1] = a1;
	for (int i = 2; i <= n * m; i++) {
		cin >> a[i];
		if (a[i] > a1)
			cnt++;
	}
	if (cnt % n == 0) {
		cout << cnt / n << " ";
		if ((cnt / n) % 2 == 1)
			cout << n;
		else
			cout << 1;
	} else {
		cout << cnt / n + 1 << " ";
		if ((cnt / n + 1) % 2 == 1) {
			cout << cnt % n;
		} else
			cout << n - (cnt % n) + 1;
	}
	return 0;
}
