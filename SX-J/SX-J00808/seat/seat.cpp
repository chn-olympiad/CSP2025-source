#include <bits/stdc++.h>
using namespace std;
int a[110];
int n, m, h = 0;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int l = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = n * m ; i >= 1; i--) {
		if (a[i] == l) {
			h++;
			int x = h / m + 1, y = h % m;
			if (x % 2 == 0)
				y = m - y;
			cout << x << " " << y;
			return 0;

		}
		h++;
	}
}
