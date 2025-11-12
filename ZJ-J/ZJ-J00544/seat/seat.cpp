#include <bits/stdc++.h>

using namespace std;

int n, m, a[105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int t = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	int pos = 1;
	for (;; pos++) {
		if (a[pos] == t) break;
	}
	int x = 1, y = 1;
	bool f = 0;
	pos--;
	while (pos--) {
		if (y == n && f == 0 || y == 1 && f == 1) {
			f = !f;
			x++;
		}
		else if (!f) y++;
		else y--;
	}
	cout << x << ' ' << y;
	
	return 0;
}
