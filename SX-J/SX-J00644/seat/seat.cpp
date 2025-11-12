#include <bits/stdc++.h>
using namespace std;
int h[20][20];
int a[20][20];

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> h[i][j];
		}
	}
	sort( h + 1, h + 1 + n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] = h[j][i];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j % 2 == 0) {
				a[j][n - i + 1] = h[i][j];
			} else {
				continue;
			}
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			if (a[i][j] == h[1][1]) {
				cout << i << " " << j << endl;
			}
		}
	}
	return 0;
}
