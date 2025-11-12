#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int T, n;
int a[maxn][3], b[maxn], c[3], cnt;
int tp[maxn], dl[maxn];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		c[0] = c[1] = c[2] = 0; cnt = 0;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
			int mx = max(max(a[i][0], a[i][1]), a[i][2]);
			if (a[i][0] == mx) {
				tp[i] = 0; c[0]++;
				dl[i] = a[i][0] - max(a[i][1], a[i][2]);
			} else if (a[i][1] == mx) {
				tp[i] = 1; c[1]++; 
				dl[i] = a[i][1] - max(a[i][0], a[i][2]);
			} else if (a[i][2] == mx) {
				tp[i] = 2; c[2]++;
				dl[i] = a[i][2] - max(a[i][0], a[i][1]);
			}
			ans += mx;
		}
		if (c[0] <= n / 2 && c[1] <= n / 2 && c[2] <= n / 2) {
			printf("%d\n", ans);
			continue;
		}
		int m;
		if (c[0] > n / 2) m = 0;
		else if (c[1] > n / 2) m = 1;
		else if (c[2] > n / 2) m = 2;
		for (int i = 1; i <= n; i++) {
			if (tp[i] == m) b[++cnt] = dl[i];
		}
		sort(b + 1, b + cnt + 1);
		for (int i = 1; i <= cnt - n / 2; i++) {
			ans -= b[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}