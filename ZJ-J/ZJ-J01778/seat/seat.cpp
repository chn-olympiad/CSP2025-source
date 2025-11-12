#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1005], R;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	R = a[1];
	sort(a + 1, a + 1 + n * m);
	reverse(a + 1, a + 1 + n * m);
	int x = 1, y = 1, cnt = 1, d = 0;
	while (cnt <= n * m) {
		if (a[cnt] == R) {
			cout << x << ' ' << y;
			return 0;
		}
		if (d == 0) {
			y++;
			if (y > n) {
				d = 1;
				x++;
				y--;
			}
		}
		else {
			y--;
			if (y < 1) {
				d = 0;
				x++, y++;
			}
		}
		cnt++;
	}
	return 0;
}
