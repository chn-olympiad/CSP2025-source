#include <bits/stdc++.h>
using namespace std;
int a[1005], mp[105][105];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, i = 1, j = 1, k = 1, num;
	cin >> n >> m;
	for (int l = 1; l <= n * m; l++) {
		cin >> a[l];
		num = a[1];
	}
	sort(a + 1, a + n *m + 1, cmp);
	while (i >= 1 && j >= 1 && i <= n && j <= m) {
		if (((i == n && j == m ) && m % 2 != 0) || ((i == 1 && j == m) && m % 2 == 0))
			break;
		for (int x = 1; x <= n; x++) {
			mp[x][j] = a[k];
			k++;
		}
		j++;
		for (int x = n; x >= 1; x--) {
			mp[x][j] = a[k];
			k++;
		}
		j++;
	}
	for (int z = 1; z <= n; z++) {
		for (int c = 1; c <= m; c++) {
			if (mp[z][c] == num) {
				cout << c << " " << z;
			}
		}
	}
	return 0;
}