#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, c[10], d[10], e, x, y;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> c[i];
	}
	y = c[0];
	sort(c, c + n *m + 1);
	for (int i = n * m; i > 0; i--) {
		d[i] = c[i];
	}
	for (int i = 0; i < m * n; i++)
		if (d[i] == y)
			e = i;
	for (int i = 1; i <= n * m; i++) {
		if (e >= n) {
			e -= n;
			x++;
		} else if (e < n and e>0) {
			if (x % 2 == 1) {
				cout << x + 1 << " " << n + 1 - e % n;
				break;
			} else if (x % 2 == 0) {
				cout << x + 1 << " " << e % n;
				break;
			}
		} else if (e == 0) {
			if (x % 2 == 1) {
				cout << x << " " << n;
				break;
			} else if (x % 2 == 0) {
				cout << x << " " << 1;
				break;
			}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);

}