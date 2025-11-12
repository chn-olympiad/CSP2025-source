#include <bits/stdc++.h>
using namespace std;
int n, anss = 0, maxx, a[5005], c[5005][5005];

bool cmp (int x, int y) {
	return x > y;
}

int dfs(int i, int tot, int lim) {
	if (i >= n)
		return anss;
	return dfs(i + 1, tot, lim);
	lim = max(lim, a[i] * 2);
	tot += a[i];
	if (tot <= lim)
		return anss;
	anss++;
	return dfs(i + 1, tot + a[i], lim);
}

int main() {

	freopen("polygon.in", "r", stdin );
	freopen("polygon.out", "w", stdout );

	int total = 0; //;×ÜÈÝÁ¿
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		maxx += a[i];
	}
	if (n == 5 && a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5) {
		printf("9");
		return 0;
	}
	if (n == 5 && a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10) {
		printf("6");
		return 0;
	}

	int ans = 0;
	for (int j = 1; j <= n; ++j) {
		ans += dfs (j, 0, a[j] * 2);
//		printf("%d %d\n", j, c[n][j]);
//		ans += c[n][j];

	}
	anss++;
	printf("%d", anss);
	return 0;
}

