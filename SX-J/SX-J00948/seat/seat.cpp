#include <bits/stdc++.h>
using namespace std;
int m, n, a1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int t = 1;
	cin >> n >> m;
	cin >> a1;
	for (int i = 1; i < m * n; i++) {
		int an;
		cin >> an;
		if (an > a1) {
			t++;
		}
	}
	int x, y;
	if (t % n == 0) {
		x = t / n;
		if (x % 2 == 0) {
			y = 1;
		} else {
			y = n;
		}
	} else {
		x = (t / n) + 1;
		if (x % 2 == 0) {
			y = n - (t % n) + 1;
		} else {
			y = t % n;
		}
	}

	cout << x << " " << y;
	return 0;
}
