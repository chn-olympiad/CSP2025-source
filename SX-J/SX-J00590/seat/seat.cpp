#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int cj[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int len = n * m;
	for (int i = 1; i <= len ; i++) {
		cin >> cj[i];
	}
	for (int i = 1; i <= len ; i++) {
		for (int j = 1; j <= len ; j++) {
			if (cj[j] <= cj[j + 1]) {
				swap(cj[j], cj[j + 1]);
			}
		}
	}
	int r = cj[1];
	int c = 1;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= m; j++) {
				a[i][j] = cj[c];
				c++;
			}
		} else {
			for (int j = m ; j >= 0; j--) {
				a[i][j] = cj[c];
				c++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == r) {
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}