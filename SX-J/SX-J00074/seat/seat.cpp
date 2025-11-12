#include <bits/stdc++.h>
using namespace std;
int l[225];
int st[15][15];

int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> l[i];
	}
	int a = l[1];
	sort(l + 1, l + (n *m) + 1, greater());
	int x = 1, y = 1;
	for (int i = 1; i <= m * n + 1; i++) {
		st[x][y] = l[i];
		if (st[x][y] == a) {
			cout << y << " " << x;
			break;
		}
		if (x > 0 && x < n && y % 2 == 1)
			x++;
		else if (x > 1 && x <= n && y % 2 == 0)
			x--;
		else
			y++;
	}
	return 0;
}