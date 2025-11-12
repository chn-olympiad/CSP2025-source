#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[15][15], b;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (i == 1 && j == 1) {
				b = a[i][j];
			}
		}
	}
	sort(a + 1, a + n + 1, greater<int>());
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (b == a[i][j]) {
				cout << i << ' ' << j;
			}
		}
	}
	return 0;
}
