#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], r, c, ma[12][12], x = 1, y = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int b = n * m;
	for (int i = 1; i <= b; i++) {
		cin >> a[i];
		if (i == 1)
			r = a[i];
	}
	sort(a + 1, a + 1 + b);
	for (int i = b; i >= 1; i--) {
		c++;
		if (a[i] == r) {
			cout << x << ' ' << y;
			break;
		}
		if (x % 2 == 1) {
			if (y == n) {
				x++;
			} else {
				y++;
			}
		} else {
			if (y == 1) {
				x++;
			} else {
				y--;
			}
		}
	}
	return 0;
}