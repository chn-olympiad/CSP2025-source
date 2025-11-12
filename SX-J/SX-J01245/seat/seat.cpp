#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n][m], c[100000];
	for (int i = 1; i <= n * m; i++) {
		cin >> c[i];
	}
	int b = c[1];
	int q = 0;
	sort(c + 1, c + n *m + 1, cmp);
	if (c[1] == b) {
		cout << "1 1";
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= m; j++) {
				a[i][j] = c[q];
				if (a[i][j] == b) {
					cout << i << " " << j;
					return 0;
				}
				q++;
			}
		} else {
			for (int j = m; j >= 1; j--) {
				a[i][j] = c[q];
				if (a[i][j] == b) {
					cout << i << " " << j;
					return 0;
				}
				q++;
			}
		}

	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == b) {
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}
