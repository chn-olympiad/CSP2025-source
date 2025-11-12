#include <bits/stdc++.h>
using namespace std;



















int a[100000][4], t, z[100000] = {0}, k[4], b[100000] = {0}, v, n, h = 0, w = 0, s[4] = {0}, f, g = 0, d1[2] = {{1}, {2}},
d2[2]







= {{1}, {-1}}, d3[2] = {{-1}, {-2}};

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	for (int p = 0; p < t; ++p) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= 3; ++j) {
				scanf("%d", &a[i][j]);
				if (a[i][j] > z[i]) {
					z[i] = a[i][j];
					v = j;
				}
			}
			s[v]++;
		}
		for (int i = 1; i <= 3; ++i) {
			if (s[i] >= v) {
				v = s[i];
			}
		}
		if (v <= n / 2) {
			for (int i = 1; i <= n; ++i) {
				w += z[i];
			}
			printf("%d", w);
		}
		int q = w;
		if (v > n / 2) {
			v = 0;
			for (int i = 1; i <= 3; ++i) {
				if (s[i] >= v) {
					v = s[i];
					f = i;
				}
			}
			while (v > n / 2) {
				for (int i = 1; i <= 3; ++i) {
					k[i] = s[i];
				}
				for (int i = 1; i <= n; ++i) {
					for (int j = 1; j <= 3; ++j) {
						if (a[i][j] > b[i]) {
							k[j]--;
							for (int m = 0; m <= 1; ++m) {
								if (f == 1) {
									b[i] = a[i][j + d1[m]];
									k[j + d1[m]]++;
								}
								if (f == 2) {
									b[i] = a[i][j + d2[m]];
									k[j + d2[m]]++;
								}
								if (f == 3) {
									b[i] = a[i][j + d3[m]];
									k[j + d3[m]]++;
								}
								z[i] = b[i];
								for (int c = 1; c <= n; ++c) {
									h += z[c];
								}
								if (h >= g && h < q) {
									g = h;
								}
							}
						}
					}
				}
				v = 0;
				for (int i = 1; i <= 3; ++i) {
					if (s[i] >= v) {
						v = k[i];
					}
				}
			}
			printf("%d", g);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}