#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m,  b;
	long long a[105][105];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	b = a[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == n) {
				if (a[i][j] < a[i][j + 1]) {
					swap(a[i][j], a[i][j + 1]);
				}
			} else if (i % n == 1 && i > 1) {
				if (a[i][j] < a[i][j + 1]) {
					swap(a[i][j], a[i][j + 1]);
				}
			} else {
				if (a[i][j] < a[i + 1][j]) {
					swap(a[i][j], a[i + 1][j]);
				}
			}

		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == b) {
				cout << i << " " << j;
			}
		}
	}
	return 0;
}