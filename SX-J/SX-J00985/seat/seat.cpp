#include <bits/stdc++.h>

using namespace std;

int a[101], b[11][11];
int n, m, i, j = 1, t, a1;

int cmp(int c, int d) {
	return c > d;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;

	for (i = 1; i <= n * m; i++)
		cin >> a[i];
	a1 = a[1];

	sort(a + 1, a + n *m + 1, cmp);

	for (i = 1; i <= n; i++) {
		if (i % 2 == 0)
			for (j = m; j >= 1; j--)
				b[i][j] = a[++t];
		else
			for (j = 1; j <= m; j++)
				b[i][j] = a[++t];
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (b[i][j] == a1) {
				cout << i << " " << j;
				break;
			}
		}
		if (j < m)
			break;
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
