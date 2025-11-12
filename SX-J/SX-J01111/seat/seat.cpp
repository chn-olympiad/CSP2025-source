#include <bits/stdc++.h>
using namespace std;
int n, m, b, c[1000], a[1000][1000], d;

bool aaa(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> c[i];
	}
	b = c[1];
	sort(c + 1, c + n *m + 1, aaa);
	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <= m; j++) {
			d++;
			a[i][j] = c[d];
		}
	}

	for (int i = 1; i <= n; i += 2) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == b) {
				cout << i << " " << j;
				return 0;
			}

		}
		for (int j = m; j >= 1; j--) {
			if (a[i + 1][j] == b) {
				cout << i + 1 << " " << j + 1;
				return 0;
			}

		}
	}
	return 0;
}