#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int a[N];
int n, m;

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	int Rc = a[1];
	sort(a + 1, a + n *m + 1, greater<int>());
	int x = 1, y = 1;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == Rc)
			cout << y << " " << x << endl;
		if (y % 2 == 1) {
			if (x == n)
				y++;
			else
				x++;
		} else {
			if (x == 1)
				y++;
			else
				x--;
		}
	}
	return 0;
}
