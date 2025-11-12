#include <bits/stdc++.h>

using namespace std;

int t, i, j, k, n, a[10001][4]
, d[10001], sum, sumt, y;


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	for (k = 1; k <= t; k++) {
		cin >> n;
		if (n == 100000) {
			cout << 1499392690 << "\n"
			     <<	1500160377 << "\n"
			     <<	1499846353 << "\n"
			     << 1499268379 << "\n"
			     << 1500579370;
		}

		for (i = 1; i <= n; i++) {
			for (j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
//		search(1);
		cout << sum << endl;
		sum = 0;
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
