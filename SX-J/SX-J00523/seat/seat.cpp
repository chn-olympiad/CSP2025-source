#include <bits/stdc++.h>
#define qwq return
using namespace std;
int n, m;
int a[110];
int b[15][15];
int sum, x, y;

bool cmp(int l, int r) {
	return l > r;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	sum = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	int q123 = 0;
	for (int j = 1; j <= m; j++) {
		if (j % 2 == 1) {
			for (int i = 1; i <= n; i++) {
				b[i][j] = a[++q123];
				if (a[q123] == sum)
					x = i, y = j;
			}
		} else {
			for (int i = n; i >= 1; i--) {
				b[i][j] = a[++q123];
				if (a[q123] == sum)
					x = i, y = j;
			}
		}
	}
	cout << y << ' ' << x;
	qwq 0;
}