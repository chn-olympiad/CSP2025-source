#include <bits/stdc++.h>
using namespace std;
int n;
int a[105], b[105], c;
int d, e;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) {
			e = 1;
		}
	}
	if (e == 0) {
		cout << n - 2;
		return 0;
	}
	e = 0;
	d = max(a[1], a[n]);
	for (int i = 1; i <= n; i++) {
		if (a[i] == d) {
			continue;
		}
		c += a[i];
	}
	if (c > d) {
		cout << n - 2;
	}
	return 0;
}
