#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n, tn, d[N], v[N], b[N], tb, cnt1, cnt2, cnt3, sum1, sum2, sum3;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n), tn = n / 2;
		for (int i = 1, x, y, z; i <= n; i++) {
			scanf("%d%d%d", &x, &y, &z);
			int mx = max(x, max(y, z)), mn = min(x, min(y, z)), md = x + y + z - mx - mn;
			if (mx == x) ++cnt1, sum1 += mx, v[i] = 1;
			else if (mx == y) ++cnt2, sum2 += mx, v[i] = 2;
			else ++cnt3, sum3 += mx, v[i] = 3;
			d[i] = mx - md;
		}
		int tmx = max(cnt1, max(cnt2, cnt3));
		if (max(cnt1, max(cnt2, cnt3)) <= tn) {
			printf("%d\n", sum1 + sum2 + sum3);
		} else {
			int f = 0;
			if (tmx == cnt1) f = 1;
			else if (tmx == cnt2) f = 2;
			else f = 3;
			for (int i = 1; i <= n; i++) if (v[i] == f) b[++tb] = d[i];
			sort(b + 1, b + tb + 1);
			int ans = sum1 + sum2 + sum3;
			for (int i = 1; i <= tmx - tn; i++) ans -= b[i];
			printf("%d\n", ans);
		}
		cnt1 = cnt2 = cnt3 = sum1 = sum2 = sum3 = 0, tb = 0;
	}
	return 0;
}