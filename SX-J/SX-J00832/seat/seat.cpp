#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y) {
	return x > y;
}
int a[105];
int xiaor;
int zw[15][15];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	cin >> xiaor;
	for (int i = 1; i < n * m; i++) {
		cin >> a[i];
	}
	sort(a + 2, a + n *m + 2, cmp);
	int t = 1;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= m; j++) {
				zw[i][j] = a[t];
				if (xiaor > a[t]) {
					cout << i << " " << j;
					return 0;
				}
				t++;
			}
		} else {
			for (int j = m; j >= 1; j--) {
				zw[i][j] = a[t];
				if (xiaor > a[t]) {
					cout << i << " " << j;
					return 0;
				}
				t++;
			}
		}
	}
	return 0;
}