#include <bits/stdc++.h>
using namespace std;
int n, a[10000], ans, vis[60000], pj, mm;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n < 3) {
		cout << 0 << endl;
		return 0;
	}
	if (n == 3) {
		if (a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1]) {
			cout << 1 << endl;
			return 0;
		}
		cout << 0 << endl;
		return 0;
	}
	cout << 0 << endl;
	return 0;
}