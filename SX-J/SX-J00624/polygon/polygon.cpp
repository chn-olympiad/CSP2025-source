#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	bool f = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1)
			f = 1;
	}
	sort(a + 1, a + n + 1);
	if (!f) {
		cout << n - 2;
	} else {
		if (n <= 3) {
			if (n <= 2) {
				cout << 0;
			} else {
				if (a[1] + a[2] + a[3] > a[3] * 2) {
					cout << 1;
				} else {
					cout << 0;
				}
			}
		}
	}
	return 0;
}
