#include <bits/stdc++.h>
using namespace std;
int n, m, t, l ;
int a[105], b[15][15];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n * m; i ++ ) {
		cin >> a[i];
	}
	t = a[1];
	sort(a + 1, a + n *m + 1);
	l = n * m;
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 0) {
			for (int j = n; j >= 1; j--) {
				b[i][j] = a[l--];
				if (b[i][j] == t) {
					cout << i << " " << j;
				}
			}
		} else {
			for (int j = 1; j <= n; j++) {
				b[i][j] = a[l--];
				if (b[i][j] == t) {
					cout << i << " " << j;
				}
			}
		}
	}
	return 0;
}
