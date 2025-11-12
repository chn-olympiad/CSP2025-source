#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, c, t, a[10005];
	cin >> n, m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (a[i] > a[i + 1] && a[i] > a[i + 2] && a[i] > a[i + 3]) {
			c = 1;
			t = 1;
			cout << c << " " << t;
			break;
		}
	}
	return 0;
}