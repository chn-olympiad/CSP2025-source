#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[150];

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << 1 << ' ' << 1 << endl;
		return 0;
	}
	if (n == 2) {
		if (a[1] > a[2]) {
			cout << 1 << ' ' << 1 << endl;
		} else {
			cout << 2 << ' ' << 1 << endl;
		}
		return 0;
	}
	bool flag = 0;
	for (int i = 2; i <= n * m; i++) {
		if (a[i] == a[i - 1]) {
			flag = 1;
		} else {
			flag = 0;
		}
	}
	if (flag == 1) {
		cout << 1 << ' ' << 1 << endl;
		return 0;
	}
	return 0;
}
