#include <bits/stdc++.h>
using namespace std;
int m, n, a[105], b[15][15], c, r, d, e;

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> m >> n;
	e = n;
	for (int i = 1; i <= m * n; i++) {
		cin >> a[i];
	}
	int z = a[1];
	sort(a + 1, a + m *n + 1);
	if (m == n && n == 1)
		cout << 1 << " " << 1;
	else {
		int x = 0, y = 1, f = m * n;
		for (int i = 1; i <= n; i++) {
			for (i = 1; i <= m; i++) {
				if (d % 2 == 0)
					x++;
				else
					x--;
				b[x][y] = a[f];
				if (b[x][y] == z)
					c = y, r = x;
				f--;
			}
			d++, y++;
		}
		cout << c << " " << r;
	}
	return 0;
}
