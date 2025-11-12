#include <bits/stdc++.h>
using namespace std;

int n, m, r, cnt = 0;

int main() {
	freopen("seat.in", "r",stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> r;
	for (int i = 2; i <= n * m; i++) {
		int a;
		cin >> a;
		if (a > r) {
			cnt++;
		}
	}
	int x = cnt / n + 1;
	int y = (cnt + 1) % n;
	if (y == 0) y = n;
	if (x & 1) cout << x << " " << y;
	else cout << x << " " << n - y + 1;
	return 0;
}
