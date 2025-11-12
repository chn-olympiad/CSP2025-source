#include <bits/stdc++.h>
using namespace std;
int n, a[5003], maxx = -999, h;
int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max (maxx, a[i]);
		h += a[i];
	}
	if (n < 3) {
		cout << 0;
	}
	if (n == 3) {
		if (h > maxx * 2) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
	return 0; 
}
