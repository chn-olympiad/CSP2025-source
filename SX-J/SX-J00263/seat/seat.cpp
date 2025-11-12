#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n, a[110], b[12][12];
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int asd = n * m, asdf;
	asdf = a[1];
	sort(a + 1, a + 1 + asd);
	int t = m * n;
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 0) {
			for (int j = n; j >= 1; j--) {
				b[j][i] = a[t];
				t--;
			}
		} else {

			for (int j = 1; j <= n; j++) {
				b[j][i] = a[t];
				t--;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (b[i][j] == asdf) {
				cout << j << " " << i;
			}
		}
	}
	return 0;
}
