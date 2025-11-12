#include <bits/stdc++.h>
using namespace std;
int a[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, k, r, cnt = 0;
	cin >> n >> m >> r;
	for (int i = 1; i < n * m; i++) {
		cin >> k;
		if (k > r)
			cnt++;
	}
	int x, y;
	x = cnt / (n * 2) * 2 + 1;
	y = cnt % (n * 2) + 1;
	if (y > n) {
		x++;
		y = 2 * n - y + 1;
	}
	cout << x << ' ' << y;
	return 0;
}
