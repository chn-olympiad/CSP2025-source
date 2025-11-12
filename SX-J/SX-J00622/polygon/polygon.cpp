#include <bits/stdc++.h>
using namespace std;
int n, a[500000], ans = 0, m = INT_MIN, cnt = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n <= 2) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		m = max(m, a[i]);
		cnt += a[i];
	}
	if (n == 3) {
		if (cnt > m * 2) {
			cout << 1;
			return 0;
		} else
			cout << 0;
	}
	return 0;
}