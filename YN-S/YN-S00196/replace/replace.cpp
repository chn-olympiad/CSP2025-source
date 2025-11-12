#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q, sum = 0;
	char m[105][105] = {0};
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= q; j++) {
			if (1 <= i && i <= n) {
				cin >> m[i][j];
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= q; j++) {
				if (1 + n + j <= q) {
					cin >> m[i][j];

					int(m[i][j]);
					sum = m[i][j];
				}
			}
		}
	}
	cout << m;
	return 0;
}