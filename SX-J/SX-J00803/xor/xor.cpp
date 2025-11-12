#include <cstdio>
#include <iostream>
using namespace std;
int n, m, a[18][36], t;

int main() {
//	freopen("seat.in", "r", stdin);
//	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	t = a[1][1];
	for (int k = 1; k <= n * m; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[i][j] < a[i][j + 1] && j + 1 <= m) {
					int t1 = a[i][j];
					a[i][j] = a[i][j + 1];
					a[i][j + 1] = t1;
				} else if (j == m && a[i][j] < a[i + 1][j] && i + 1 <= n) {
					int t1 = a[i][j];
					a[i][j] = a[i + 1][j];
					a[i + 1][j] = t1;
				}
				cout << a[i][j] << " ";
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (t == a[i][j]) {
				cout << endl << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}