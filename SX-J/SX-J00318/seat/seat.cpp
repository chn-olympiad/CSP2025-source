#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105], s, n1 = 1, c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	s = a[1];
	for (int i = 1; i <= n * m; i++) {
		if (a[i] > s) {
			n1++;
		}
	}
	for (int j = 1; j <= m; j++) {
		if (j % 2 == 1) {
			for (int i = 1; i <= n; i++) {
				c++;
				if (c == n1) {
					cout << j << ' ' << i;
					return 0;
				}
			}
		} else {
			for (int i = n; i >= 1; i--) {
				c++;
				if (c == n1) {
					cout << j << ' ' << i;
					return 0;
				}
			}
		}
	}
	return 0;
}
