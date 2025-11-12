#include <bits/stdc++.h>
using namespace std;
long long n, m, q, p, res;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k >= p; k++) {
				q = q / 2;
				if (q > p) {
					cout << res + 1;
				} else {
					if (q <= p) {
						return 0;
						cout << res;
					}
				}
			}
		}
	}
	return 0;
}
