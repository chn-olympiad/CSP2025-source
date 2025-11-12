#include <bits/stdc++.h>
using namespace std;
long long n, m, a[105], c, r, R, k;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int s[n + 10][m + 10] = {0};
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	R = a[0];
	sort(a, a + n *m, cmp);
	for (int i = 1; i <= m; i++) {
		int hang = n, lie = m;
		for (int j = 1; j <= n; j++) {
			if (i % 2 != 0) {
				s[j][i] = a[k];
				k++;
			} else {
				s[hang--][lie] = a[k];
				k++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[j][i] == R) {
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}