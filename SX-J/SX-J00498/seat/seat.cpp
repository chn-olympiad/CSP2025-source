#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[100];
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int b = a[1];
	sort(a, a + n *m);
	for (int i = n * m ; i >= 1; i--) {
		int c = a[i];
		if (c == b) {
			if (i > n) {
				cout << n - 1  << " ";
			} else if (i = n) {
				cout << n << " ";
			} else if (i < n) {
				cout << n << " ";
			}
			if (i > m) {
				cout << m   ;
			} else if (i < m) {
				cout << m - 1;
			} else if (i == m) {
				cout << m - 2;
			}
			break;
		}
	}
	return 0;
}