#include <bits/stdc++.h>
using namespace std;
int a[11][11], b[111], c[111];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, l, i, k, jj, j;
	bool g;
	cin >> n >> m;
	l = n * m;
	for (i = 1; i <= l; i++)
		cin >> c[i];
	jj = c[1];
	sort(c + 1, c + l + 1);
	k = l;
	for (i = 1; i <= m; i++) {
		if (g) {
			for (j = 1; j <= n; j++) {
				a[j][i] = c[k--];
			}
			g = 0;
		} else {
			for (j = n; j >= 1; j--)
				a[j][i] = c[k--];
			g = 1;
		}
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)

			if (a[i][j] == jj) {
				cout <<  j << ' ' << i;
			}
	return 0;
}
