#include <bits/stdc++.h>
using namespace std;
int m, n;
int num[150];
int a[15][15];
int x, c;
int j = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	x = m * n;
	c = x;
	for (int i = 1; i <= x; i++) {
		cin >> num[i];
	}
	int score = num[1];
	sort(num, num + x + 1);
	for (int k = c; k >= 1; k--) {
		if (j % 2 != 0) {
			for (int i = 1; i <= n; i++) {
				a[i][j] = num[x];
				x--;
			}
			j++;
		} else {
			for (int i = n; i >= 1; i--) {
				a[i][j] = num[x];
				x--;
			}
			j++;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int l = 1; l <= m; l++) {
			if (a[i][l] == score) {
				cout << l << " " << i;
				return 0;
			}
		}
	}
	return 0;
}
