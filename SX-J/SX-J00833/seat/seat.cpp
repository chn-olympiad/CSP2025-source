#include <bits/stdc++.h>
using namespace std;
int me, n, m, a;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int x, y;
	cin >> me;
	for (int i = 2; i <= n * m; i++) {
		cin >> x;
		if (x > me)
			a++;
	}
	a++;
	x = a / n;
	y = a % n;
	if (y != 0) {
		cout << x + 1 << ' ' << ((x + 1) & 1 ? y : n - y + 1);
	} else {
		cout << x << ' ' << (x & 1 ? n : 1);
	}
	return 0;
}
