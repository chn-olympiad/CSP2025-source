#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], b[105][105];

int main() {
	//freopen(seat.in, "r", stdin);
	//freopen(seat.out, "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		sort(a[i + 1], a[i], a[i + 1] > a[i]);
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (b[i == m][j]) {
				for (int k = m; k >= 1; k++) {
					b[i][k];
				}
			}
		}
	}
	return 0;
}