#include <bits/stdc++.h>
using namespace std;
int a[105], b[20][20], r, m, n, k = 0;


int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	r = a[1];
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				b[j][i] = a[i];
			}
		} else {
			for (int j = n; j >= 1; j--) {
				b[j][i] = a[i];
			}
		}


	}
	cout << n - 1 << " " << m;
	return 0;
}
