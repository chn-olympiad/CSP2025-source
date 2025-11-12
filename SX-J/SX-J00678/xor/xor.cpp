#include <bits/stdc++.h>
using namespace std;
int a[1010];
int f[1010][300];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= 255; j++) {
			f[i][j] = -1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			for (int j = 0; j <= 255; j++) {
				f[i][j] = f[i - 1][j];
			}
			if (k == 0) {
				f[i][0]++;
			}
			continue;
		}
		for (int j = 0; j <= 255; j++) {
			if (f[i - 1][j] == -1)
				continue;
			if (j == k)
				continue;
			//printf("%d %d  ", j, f[i - 1][j]);
			f[i][j ^a[i]] = f[i - 1][j];
			if ((j ^ a[i]) == k) {
				f[i][j ^a[i]]++;
			}
			//printf("%d %d %d  ", j, j ^a[i], f[i][j ^a[i]]);
		}
		f[i][0] = max(f[i - 1][k], f[i][k]);
		f[i][0] = max(0, f[i][0]);
		//printf("\n");
	}
	printf("%d", f[n][0]);
	return 0;
}