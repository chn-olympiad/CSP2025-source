#include <iostream>
using namespace std;
int n, m, a[15][15], q, b, w;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	q = a[1][1];
	for (int i = 1; i <= m; i += 2) {
		for (int j = 1; j < n; j++) {
			if (a[i][j] < a[i + 1][j]) {
				swap(a[i][j], a[i + 1][j]);
			}
		}
		if (a[n][i] < a[n][i + 1]) {
			swap( a[i], a[i + 1]);
		}
		for (int j = n; j > 1; j--) {
			if (a[i][j + 1] < a[i - 1][j + 1]) {
				swap(a[i][j + 1], a[i - 1][j + 1]);
			}
		}
		if (a[1][i + 1] < a[1][i]) {
			swap(a[1][i + 1], a[1][i]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (q == a[i][j]) {
				b = i;
				w = j + 1;
			}
		}
	}
	cout << b << " " << w;
	return 0;
}