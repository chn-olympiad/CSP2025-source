#include <bits/stdc++.h>

using namespace std;

int a[15][15];
int b[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> b[i];
	}
	int x = b[1];
	for (int i = 1; i < n * m; i++) {
		for (int j = i+1; j <= n*m; j++) {
			if (b[i] < b[j]) {
				swap(b[i], b[j]);
			}
		}
	}
	int u = 1;
	int index = 1;
	for (int i = 1; i <= m; i++) {
		if (u) {
			for (int j = 1; j <= n; j++) {
				a[j][i] = b[index];
				index++;
			}
			u = 0;
		} else {
			for (int j = n; j > 0; j--) {
				a[j][i] = b[index];
				index++;
			}
			u=1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == x) {
				cout << j << " " << i;
			}
		}
	}
	return 0;
}
