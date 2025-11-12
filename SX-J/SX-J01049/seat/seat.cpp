#include <bits/stdc++.h>
using namespace std;

long long seat[105][105], a[10005], n, m, k = 1, seatrr, seatrx, seatry;

bool cmp(long long b, long long c) {
	return b > c;
}

int main() {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	seatrr = a[1];

	sort(a + 1, a + n *m + 1, cmp);

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (i % 2 == 1) {
				seat[j][i] = a[k++];
				if (seat[j][i] == seatrr) {
					seatrx = j;
					seatry = i;
				}
			} else {
				//i%2 == 0
				seat[n - j + 1][i] = a[k++];
				if (seat[n - j + 1][i] == seatrr) {
					seatrx = n - j + 1;
					seatry = i;
				}
			}
		}
	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << seat[i][j] << " ";
		}
		cout << endl;
	}*/

	cout << seatry << " " << seatrx;

	return 0;
}
