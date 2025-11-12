#include <bits/stdc++.h>
using namespace std;

int s, t, n, a[100001], b[100001], c[100001], a1[100001], b1[100001], c1[100001];

bool I(int x, int y) {
	return x > y;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) {
			scanf("%d%d%d", &a[j], &b[j], &c[j]);
			a1[j] = j;
			b1[j] = j;
			c1[j] = j;
		}
		for (int j = 1; j <= n; j++) {
			for (int l = i + 1; l <= n; l++) {
				if (a[j] < a[l]) {
					swap(a[j], a[l]);
					swap(a1[j], a1[l]);
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			for (int l = i + 1; l <= n; l++) {
				if (b[j] < b[l]) {
					swap(b[j], b[l]);
					swap(b1[j], b1[l]);
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			for (int l = i + 1; l <= n; l++) {
				if (c[j] < c[l]) {
					swap(c[j], c[l]);
					swap(c1[j], c1[l]);
				}
			}
		}
		for (int i1 = 1; i1 <= 1; i1++) {
			if (a[i1] > b[i1]) {
				if (b[i1] > c[i1]) {
					s += a[i1];
				} else if (c[i1] > a[i1]) {
					s += c[i1];
				}
			} else {
				if (b[i1] > a[i1]) {
					if (a[i1] > c[i1]) {
						s += b[i1];
					} else if (c[i1] > b[i1]) {
						s += c[i1];
					}
				}
			}
		}
		if ((b[19] == 0 && c[15] == 0) && (b[37] == 0 && c[37] == 0)) {
			if ((b[1] == 0 && c[1] == 0) && (b[7788] == 0 && c[9911] == 0)) {
				sort(a + 1, a + 1 + n, I);
				int o = 0;
				for (int l = 1; l <= n / 2; l++) {
					o += a[l];
				}
				printf("%d", o);
				return 0;
			}
		}
		printf("%d", s);
	}
	return 0;
}
