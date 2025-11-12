#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int z = 1; z <= t; z++) {
		long long n, sum = 0;
		cin >> n;
		int a[5][n + 2], p[n + 3], o[n + 3];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			sum = max(a[i][1], max(a[i][2], a[i][3]));
			o[i] = sum;
			for (int j = 1; j <= 3; j++) {
				if (sum == a[i][j]) {
					a[i][j] = -1;
					p[i] = j;
				}

			}
		}
		long a1 = 0, b1 = 0, c1 = 0;
		for (int i = 1; i <= n; i++) {
			if (p[i] == 1)
				a1++;
			if (p[i] == 2)
				b1++;
			if (p[i] == 3)
				c1++;
		}
		if (a1 <= n / 2 && b1 <= n / 2 && c1 <= n / 2) {
			long long g = 0;
			for (int i = 1; i <= n; i++) {
				g += o[i];
			}
			cout << g;
		}
	}

	return 0;
}
