#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n * m + 1], R;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	R = a[1];
	sort(a, a + n *m + 1);
	int c = 0, r = 1;
	for (int i = n * m; i > 0; i--) {
		if (r % 2 == 1) {
			c++;
		} else {
			c--;
		}
		if (r % 2 == 1 && c == n + 1) {
			r++;
			c = n;
		} else if (r % 2 == 0 && c == 0) {
			r++;
			c = 1;
		}
		if (a[i] == R) {
			cout << r << " " << c;
			return 0;
		}
	}
	return 0;
}
