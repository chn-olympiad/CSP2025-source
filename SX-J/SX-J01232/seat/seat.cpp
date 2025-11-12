#include <bits/stdc++.h>
using namespace std;
int a[12][12], n, m, b[105];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> b[i];
	}
	int sum = b[1];
	sort(b + 1, b + n *m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = b[i * j];
		}
	}
	for (int i = 1; i <= n * m; i++) {
		if (b[i] == sum) {
			if (n == 1)
				cout << i << ' ' << n;
			else
				cout << m << ' ' << i;
		}
	}
//	cout << n << ' ' << m;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			if (a[i][j] == sum) {
//				cout << i << ' ' << j;
//				return 0;
//			}
//		}
//	}
	return 0;
}
