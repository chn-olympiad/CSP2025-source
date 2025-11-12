#include <bits/stdc++.h>
using namespace std;
int a[105];

int cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, x, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	x = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == x) {
			ans = i;
		}
	}
	int sum = 0;
	for (int j = 1; j <= m; j++) {
		if (j % 2 == 1) {
			for (int i = 1; i <= n; i++) {
				sum++;
				if (sum == ans) {
					cout << j << " " << i;
					return 0;
				}
			}
		} else {
			for (int i = n; i >= 1; i--) {
				sum++;
				if (sum == ans) {
					cout << j << " " << i;
					return 0;
				}
			}
		}
	}
	return 0;
}