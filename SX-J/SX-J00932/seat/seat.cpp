#include <bits/stdc++.h>
using namespace std;
int a[102];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n;
	cin >> n >> m;
	int c = n * m;
	for (int i = 1; i <= c; i++) {
		cin >> a[i];
	}
	int ans = a[1];
	sort(a + 1, a + c + 1);
	int x = 1, y = 1;
	for (int i = c; i >= 1; i--) {
		if (a[i] == ans) {
			cout << x << " " << y;
			return 0;
		} else {
			if (x % 2 != 0) {
				if (y + 1 > n) {
					x++;
				} else {
					y++;
				}
			} else {
				if (y - 1 < 1) {
					x++;
				} else {
					y--;
				}
			}
		}
	}
	return 0;
}
