#include <bits/stdc++.h>
using namespace std;
int m, n, a[1008], b[110][110];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int r = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	int q = 1;
	for (int i = 1; i <= m; i++) {
		if (i % 2) {
			for (int j = 1; j <= n; j++) {
				b[i][j] = a[q];
				q++;
				if (b[i][j] == r) {
					cout << i << " " << j << endl;
					return 0;
				}
			}
		} else {
			for (int j = n; j > 0; j--) {
				b[i][j] = a[q];
				q++;
				if (b[i][j] == r) {
					cout << i << " " << j - 1 << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
