#include <iostream>
#include <algorithm>
int T = 1;
int n, a[100005][3];
int c[100005], se[100005], cnt1, cnt2, cnt3;
int h[100005], cc;
void solve() {
	int res = 0;
	scanf("%d", &n);
	cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[i][1] = x, a[i][2] = y, a[i][3] = z;
		if (x >= y && y >= z) {
			c[i] = 1, se[i] = 2, ++cnt1, res += x;
		} else if (x >= z && z >= y) {
			c[i] = 1, se[i] = 3, ++cnt1, res += x;
		} else if (y >= x && x >= z) {
			c[i] = 2, se[i] = 1, ++cnt2, res += y;
		} else if (y >= z && z >= x) {
			c[i] = 2, se[i] = 3, ++cnt2, res += y;
		} else if (z >= x && x >= y) {
			c[i] = 3, se[i] = 1, ++cnt3, res += z;
		} else {
			c[i] = 3, se[i] = 2, ++cnt3, res += z;
		}
	}
	int pos = -1;
	if (cnt1 > n / 2) pos = 1;
	else if (cnt2 > n / 2) pos = 2;
	else if (cnt3 > n / 2) pos = 3;
	if (pos == -1) {
		printf("%d\n", res);
		return;
	}
	cc = 0;
	for (int i = 1; i <= n; i++) {
		if (c[i] == pos)
			h[++cc] = a[i][c[i]] - a[i][se[i]];
	}
	std::sort(h + 1, h + 1 + cc);
	for (int i = 1; i <= cc - n / 2; i++)
		res -= h[i];
	printf("%d\n", res);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
