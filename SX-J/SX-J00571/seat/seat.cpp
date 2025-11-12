#include <bits/stdc++.h>
using namespace std;
int n, m, a[10005], sum, num, b[20][20];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i < n * m; i++)
		cin >> a[i];
	sum = a[1];
	sort(a + 1, a + n *m + 1, greater<int>());
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j++) {
			b[i][j] = a[++num];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i % 2 != 0) {
			sort(b[i] + 1, b[i] + n + 1);
		} else {
			sort(b[i] + 1, b[i] + n + 1, greater<int>());
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (b[i][j] == sum) {
				cout << i << " " << m - j + 1;
			}
		}
	}
	cout << endl;
	return 0;
}
