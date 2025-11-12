#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, m[100] = {}, l = 0, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m[i];
		k = i;
	}
	sort(m, m + k);
	for (int i = 0; i < n; i++) {
		if (m[i] + m[i - 1] + m[i + 1] > m[i + 1] ) {
			if (m[i] + m[i - 1] + m[i + 1] > 3 ) {
				if (m[i] + m[i - 1] + m[i + 1] > m[i] * 2 + m[i - 1] * 2 + m[i + 1] * 2) {
					l = l + 1;
				}
			}
		}
		if (m[i] + m[i - 1] + m[i + 1] + m[i + 2] > m[i + 2]) {
			if (m[i] + m[i - 1] + m[i + 1] + m[i + 2] > 3) {
				if (m[i] + m[i - 1] + m[i + 1] > m[i] * 2 + m[i - 1] * 2 + m[i + 1] * 2) {
					l = l + 1;
				}
			}

		}
	}
	cout << l;

	return 0;
}