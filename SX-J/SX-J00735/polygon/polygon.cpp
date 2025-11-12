#include <bits/stdc++.h>
using namespace std;
int m[10000];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int p = 1; p <= n; p++) {
		cin >> m[p];
	}
	if (n < 3) {
		cout << 0 << endl;
		return 0;
	} else if (n == 3) {
		int b = max(m[1], m[2]);
		b = max(b, m[3]);
		if (b * 2 < m[1] + m[2] + m[3]) {
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
		return 0;
	} else {
		cout << n + 2 << endl;
	}
	return 0;
}