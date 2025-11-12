#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000], R, x = 1, y = 1;
int f = 1;

int main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);


	cin >> n >> m;

	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	R = a[1];
	stable_sort(a + 1, a + n *m + 1);
	for (int i = n * m; i >= 1; i--) {
		if (a[i] == R) {
			cout << y << ' ' << x;
			break;
		} else {
			if (f == 0 and (x == 1 or x == n)) {
				f = 1;
				y++;
			}

			else {
				if (y % 2 == 0) {
					x--;
					if (x == 1)
						f = 0;
				} else {
					x++;
					if (x == n)
						f = 0;
				}
			}

		}
	}

	return 0;
}
