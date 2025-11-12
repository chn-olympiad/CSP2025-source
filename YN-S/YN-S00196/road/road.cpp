#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, a = 1, b[105], sum = 0, c = 9999999;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		if (n <= i + 1) {
			for (int q = 1; q <= 3; q++) {
				cin >> b[q];
			}
		}


		for (int j = 1; j <= k; j++) {
			if (n <= j + m + 1) {
				for (int p = 1; p <= n + 1; p++) {
					cin >> b[p];

					a = b[p] * i / j * k * m;
					sum = int (n / 2 + n) * 0.99999999 + a;
					if (sum < c) {
						swap(sum, c);
					}
				}
			}
		}


		cout << c;

	}
	return 0;
}