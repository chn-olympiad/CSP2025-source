#include <bits/stdc++.h>
using namespace std;
int n, m, f[105], p[100][100], k, i, j, l, w;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	k = m * n;
	for (int h = 0; h < k; h++) {
		scanf("%d", &f[h]);
	}
	w = f[0];
	sort(f, f + k, cmp);
	p[0][0] = f[0];
	while (k != l) {
		if (j % 2 == 0) {
			while (i + 1 < n) {
				p[i++][j] = f[l++];
			}
			p[i][j++] = f[l++];
		} else {
			while (i - 1 >= 0) {
				p[i--][j] = f[l++];
			}
			p[i][j++] = f[l++];
		}
		p[i][j] = f[l];
	}
	for (int c = 0; c < n; c++) {
		for (int r = 0; r < m; r++) {
			if (w == p[c][r]) {
				printf("%d %d", r + 1, c + 1);
				return 0;
			}
		}
	}
	return 0;
}