#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a[11][11], q = 1;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] > a[1][1]) {
				q++;
			}
		}
	}
	if ((q / m) % 2 == 1) {
		cout << (q / n) + 1 << " " << n + 1 - (q % n);
	} else {
		cout << (q / n) + 1 << " " << q % n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
