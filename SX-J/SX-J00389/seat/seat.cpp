#include <bits/stdc++.h>
using namespace std;

int n, m, num;
int cj[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> cj[i];
		if (i == 1) {
			num = cj[i];
		}
	}
	sort(cj + 1, cj + n *m + 1);
	int c = 1, r = 1;
	for (int i = n * m; i >= 1; i--) {
		if (num == cj[i]) {
			cout << c << " " << r;
			return 0;
		}
		if (r < n && c % 2 == 1) {
			r++;
		} else if (r == n && c % 2 == 1) {
			c++;
		} else if (c % 2 == 0 && r <= n && r > 1) {
			r--;
		} else if (c % 2 == 0 && r == 1) {
			c++;
		}
	}
	return 0;
}
