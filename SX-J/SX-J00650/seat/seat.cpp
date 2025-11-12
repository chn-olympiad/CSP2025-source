#include <bits/stdc++.h>
using namespace std;

int a[105] = {0};

int b[15][15] = {0};
bool bl = 0;
bool cmp(int p, int q) {
	if (p > q)
		return 1;
	else
		return 0;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int w = a[1];

	sort(a + 1, a + n *m + 1, cmp);
	int t = 0;
	for (int y = 1; y <= m; y++) {
		if (bl == 0) {
			int x = 0;
			while (x < n) {
				t++;
				x++;
				b[x][y] = a[t];
			}
			bl = 1;
		} else {
			int x = n + 1;
			while (x > 1) {
				t++;
				x--;
				b[x][y] = a[t];
			}
			bl = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (b[i][j] == w) {
				cout << j << ' ' << i;
			}
		}
	}
	return 0;
}
