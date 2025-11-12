#include <bits/stdc++.h>
using namespace std;
int b[410];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n + 10][m + 10] = {};
	for (int i = 1; i <= n / 2; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
		i++;
		for (int j = m; j >= 1; j--) {
			cin >> a[i][j];
		}
	}
	if (m % 2 == 1) {
		for (int i = m; i <= m; i++) {
			for (int j = 1; j <= n; j++)
				cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == a[1][1]) {
				cout << i << " " << j;
			}
		}
	}
	return 0;
}