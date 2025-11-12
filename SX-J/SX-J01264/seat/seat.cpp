#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], R;

bool cmp(int x, int y) {
	return x > y;
}


int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {

		cin >> a[i];

	}
	R = a[1];
	sort(a + 1, a + n *m + 1, cmp);

	for (int i = 1; i <= n * m ; i++) {
		if (a[i] == R) {
			int x = i / m  + 1, y = i % m;
			if (i % m == 0)
				x--;
			if (y == 0)
				y = m;
			if (x % 2 == 0)
				y = m - y + 1;

			cout << x  << ' ' << y ;
		}
	}
	return 0;
}
