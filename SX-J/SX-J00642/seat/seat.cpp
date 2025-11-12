#include <bits/stdc++.h>
using namespace std;
int n, m, a[15][15], p[105], t = 1, k;

bool cmp(int q, int h) {
	return q > h;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> p[i];
		if (i == 1)
			k = p[i];
	}
	sort(p + 1, p + n *m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				a[j][i] = p[t];
				t++;
			}
		} else {
			for (int j = n; j >= 1; j--) {
				a[j][i] = p[t];
				t++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == k) {
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}
















