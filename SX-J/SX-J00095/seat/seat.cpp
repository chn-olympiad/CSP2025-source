#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
const int S = 100 + 50;
int a[S];

signed main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n, m, ans, ans1;
	cin >> n >> m;

	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if ((i) == 1) {
			ans = a[i];
		}
	}
	sort(a, a + (n *m + 1));
	for (int i = 0; i <= n * m; i++) {
		if (a[i] == ans) {
			ans1 = n * m - i + 1 ;
			break;
		}
	}
	int y = ceil((ans1 * 1.0) / (n * 1.0)); //yÊÇÁÐ
	cout << y << " ";
	if (y % 2 == 1) {
		int x = ans1 % n;
		if (x == 0) {
			cout << n;
		} else {
			cout << x;
		}
	}
	if (y % 2 == 0) {
		int x = n - ans1 % n;
		if (x == 1) {
			cout << n;
		} else {
			cout << x + 1;
		}
	}
	return 0;
}
