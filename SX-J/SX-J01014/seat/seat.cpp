#includ<bist/stdc++.h>
using namespace std;
int m, n, h, x = 1, y = 1, q = 1;
int a[20][20];
int c[110];

bool cmp(x, y) {
	if (x > y)
		return true;
	else
		return false;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> c[i];
	}
	h = c[1];
	sort(c + 1, c + n *m + 1, cmp);
	while (true) {
		if (a[x][y] != 0) {
			if (x != n) {
				x++;
			}
		}
		if (a[x, y] != 0) {
			if (x == n && a[x - 1][y] != 0) {
				y++;
			}
		}
		if (a[x][y] != 0) {
			if (a[x - 1][y] == 0) {
				x--;
			}
		}
		if (x == 1 && a[x + 1][y] != 0 && a[x][y + 1] == 0 && a[x][y] != 0) {
			y++;
		}
		if (a[x][y] == 0) {
			a[x][y] = a[q];
			q++;
		}
		if (x == n && y == m)
			break;
	}
	for (int i = 1, i <= n; i++) {
		for (int j = 1; <= m; j++) {
			if (a[i][j] == h) {
				cout << i << " " << j;
				break;
			}
		}
	}
	return 0;
}
