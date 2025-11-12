#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], x;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	x = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == x) {
			x = i;
			int y = x / n;
			if (x % n != 0)
				y++;
			x = x % (2 * n);
			if (x == 0)
				x = 1;
			if (x > n) {
				cout << y << ' ' << n - (x - n) + 1;
			} else {
				cout << y << ' ' << x;
			}
			return 0;
		}
	}
	return 0;
}
