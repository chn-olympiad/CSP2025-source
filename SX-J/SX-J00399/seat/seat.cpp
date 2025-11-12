#include <bits/stdc++.h>
using namespace std;

bool jh(int a, int b) {
	return a > b;
}
int st[12][12];
int cj[105];

int main() {
//	freopen("seat.in", "r", stdin);
//	freopen("seat.out", "w", stdout);
	int n, m, cj1, zw, x = 1, y = 1;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> cj[i];
	cj1 = cj[1];
	sort(cj + 1, cj + n *m + 1, jh);
	for (int i = 1; i <= n * m; i++)
		if (cj1 == cj[i])
			zw = i;
	st[1][1] = 1;
	if (zw == 1) {
		cout << 1 << ' ' << 1;
	}
	for (int i = 1; i < zw; i++) {
		if (y % 2 == 1 && x < n) {
			x++;
		}
		if (y % 2 == 0 && x > 1) {
			x--;
		}
		if (x == 1 && y != 1)
			y++;
		if (x == n && y != m)
			y++;
	}
	cout << x << ' ' << y;
	return 0;
}
