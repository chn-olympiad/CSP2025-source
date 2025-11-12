#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100000005];

int cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++ ) {
		cin >> a[i];
	}
	int c = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	int x = 1, y = 1;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == c) {
			cout << y << " " << x;
		}
		if (y % 2 == 1) {
			if (n == x) {
				y++;
			} else {
				x++;
			}
		} else {
			if (x == 1) {
				y++;
			} else {
				x--;
			}
		}
	}
	return 0;
}