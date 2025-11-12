#include <bits/stdc++.h>
using namespace std;
int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int f;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	f = a[1];
	sort(a + 1, a + n *m + 1, greater<int>());
	int w;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == f) {
			w = i;
			break;
		}
	}
	int x, y;
	if (w % n == 0) {
		y = w / n;
		if (y % 2 == 0) {
			cout << y << " " << 1;
			return 0;
		} else {
			cout << y << " " << n;
			return 0;
		}
	} else {
		y = w / n + 1;
		x = w % n;
		if (y % 2 == 0) {
			cout << y << " " << n - x + 1 ;
		} else
			cout << y << " " << x;
	}
	return 0;
}
