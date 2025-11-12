#include <bits/stdc++.h>
using namespace std;
int n, m, a[107], num, c, r, k = 1, v[17][17];

bool cmp1(int x, int y) {
	return x > y;
}

bool p = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	num = a[1];
	sort(a + 1, a + n *m + 1, cmp1);
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1)
			p = 1;
		else
			p = 0;
		if (p) {
			for (int j = 1; j <= n; j++) {
				v[j][i] = a[k];
				k++;
			}
		} else {
			for (int j = n; j >= 1; j--) {
				v[j][i] = a[k];
				k++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (num == v[i][j]) {
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}
