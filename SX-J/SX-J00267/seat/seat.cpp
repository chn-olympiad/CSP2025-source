#include <bits/stdc++.h>
using namespace std;
int n, m, s, p = 0, q;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int a[m][n];
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	s = a[1][1];
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] >= s) {
				p++;
			}
		}
	}
	q = p / n;
	if (q * n != p)
		q++;
	if (p % n != 0) {
		if (q % 2 == 1)
			cout << q << " " << p % n;
		else
			cout << q << " " << (n - p % n ) + 1;
	} else {
		if (q % 2 == 1)
			cout << q << " " << n;
		else
			cout << q << " " << 1;
	}

	return 0;
}
