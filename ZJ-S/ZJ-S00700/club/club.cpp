#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

int n, a[N][3], b[N][3];
int cnt[3], c[N];

void solve() {
	scanf("%d", &n);
	cnt[0] = cnt[1] = cnt[2] = 0;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		b[i][0] = 0;
		b[i][1] = 1;
		b[i][2] = 2;
		sort(b[i], b[i] + 3, [&](int x, int y) {
			return a[i][x] > a[i][y];
		});
		ans += a[i][b[i][0]];
		++cnt[b[i][0]];
	}
	int j = -1;
	if (cnt[0] > n / 2) j = 0;
	if (cnt[1] > n / 2) j = 1;
	if (cnt[2] > n / 2) j = 2;
	if (j != -1) {
		int V = 0;
		for (int i = 1; i <= n; ++i) {
			if (b[i][0] == j) {
				c[++V] = a[i][b[i][1]] - a[i][j];
			}
		}
		sort(c + 1, c + V + 1, greater<int>());
		int num = cnt[j] - n / 2;
		for (int i = 1; i <= num; ++i)
			ans += c[i];
	}
	printf("%d\n", ans);
}

int main() {
#ifndef XuYueming
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}
