#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int a[n * m];
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	int a_sum = a[0], sum = 0, y = 0;
	int d_u = 1;
	sort(a, a + n *m);
	for (int x = 0; x < m; x++) {
		while (1) {
			if (a[sum] == a_sum) {
				cout << y + 1 << " " << x + 1;
				return 0;
			}
			if (y == n - 1 && d_u == 1) {
				d_u = 0;
				break;
			} else if (y == 0 && d_u == 0) {
				d_u = 1;
				break;
			}
			if (d_u == 1) {
				y++;
				sum++;
			} else if (d_u == 0) {
				y--;
				sum++;
			}
		}
	}
	return 0;
}
