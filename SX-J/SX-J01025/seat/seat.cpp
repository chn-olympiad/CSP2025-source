#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], q, s, sum = 0;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	s = a[1];
	sort(a + 1, a + 1 + n *m);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == s) {
			q = i;
		}
	}
	q = n * m - q + 1 ;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= m; j++) {
				sum++;
				if (sum == q) {
					cout << i << " " << j;
					break;
				}
			}
		} else {
			for (int j = m; j >= 1; j--) {
				sum++;
				if (sum == q) {
					cout << i << " " << j;
					break;
				}
			}
		}
	}
	return 0;
}
