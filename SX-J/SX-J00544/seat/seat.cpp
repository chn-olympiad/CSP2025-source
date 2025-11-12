#include <bits/stdc++.h>
using namespace std;
long long x = 1, y = 1, a[105][105], ans, n, m, kk, b[10005], pp;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	ans = n * m;
	for (int i = 1; i <= ans; i++)
		cin >> b[i];
	kk = b[1];
	sort(b + 1, b + ans + 1, cmp);
	while (ans--) {
		if (y % 2 == 1) {
			while (x <= m) {
				a[x][y] = b[++pp];
				if (a[x][y] == kk) {
					cout << y << " " << x;
					return 0;
				}
				x++;
			}
			x--, y++;
		} else {
			while (x >= 1) {
				a[x][y] = b[++pp];
				if (a[x][y] == kk) {
					cout << y << " " << x;
					return 0;
				}
				x--;
			}
			x++, y++;
		}
	}
	return 0;
}

