#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, a[100] = {}, f, b[100] = {}, k = 0, l = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];

	}
	cin >> f;
	for (int o = f; o > 0; o--) {
		b[o] = f % 10;
		f = f / 10;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			if (l >= b[i]) {
				l = l + 1;
				break;
			} else {
				if (k < m) {
					k = k + 1;
				}
			}
		}
		if (a[i] == 0) {
			l = l + 1;
			break;
			cout << l;
		}

	}
	cout << k + m;
	return 0;
}