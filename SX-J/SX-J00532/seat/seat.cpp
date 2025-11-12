#include <bits/stdc++.h>
using namespace std;

int cmp(int a, int b) {
	return a > b;
}

int a[110], b[20][20];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m, r, k = 0;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	r = a[1];
	sort(a + 1, a + n *m, cmp);
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++)
				b[j][i] = a[++k];
		} else {
			for (int j = n; j >= 1; j--)
				b[j][i] = a[++k];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (b[i][j] == r) {
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}
