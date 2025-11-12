#include <bits/stdc++.h>
using namespace std;
int t, n, mid;
long long a[3], ans, mb, mc, md, b[100500], c[100500], d[100500];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t > 0) {
		t--;
		scanf("%d", &n);
		mid = n / 2;
		ans = 0;
		mb = 0;
		mc = 0;
		md = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= 2; j++) {
				scanf("%lld", &a[j]);
			}
			if (a[0] >= a[1] && a[0] >= a[2]) {
				mb++;
				ans = ans + a[0];
				b[mb] = a[0] - max(a[1], a[2]);
			} else if (a[1] >= a[0] && a[1] >= a[2]) {
				mc++;
				ans = ans + a[1];
				c[mc] = a[1] - max(a[0], a[2]);
			} else {
				md++;
				ans = ans + a[2];
				d[md] = a[2] - max(a[1], a[0]);
			}
		}
		if (mb > mid) {
			sort(b + 1, b + 1 + mb);
			for (int i = 1; i <= (mb - mid); i++) {
				ans = ans - b[i];
			}
		}
		if (mc > mid) {
			sort(c + 1, c + 1 + mc);
			for (int i = 1; i <= (mc - mid); i++) {
				ans = ans - c[i];
			}
		}
		if (md > mid) {
			sort(d + 1, d + 1 + md);
			for (int i = 1; i <= (md - mid); i++) {
				ans = ans - d[i];
			}
		}
		printf("%lld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
