#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t, n, s[4], lim;

struct W {
	ll a[4], x, mx;
	int mxi;
} w[100005];
ll maxx, ans;

bool cmp(W l, W r) {
	return l.x > r.x;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		lim = n / 2, ans = 0;
		memset(s, 0, sizeof(s));
		for (int i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &w[i].a[1], &w[i].a[2], &w[i].a[3]);
			maxx = max(max(w[i].a[1], w[i].a[2]), w[i].a[3]);
			w[i].mx = maxx;
			if (w[i].a[1] == maxx)
				w[i].x = maxx - max(w[i].a[2], w[i].a[3]), w[i].mxi = 1;
			if (w[i].a[2] == maxx)
				w[i].x = maxx - max(w[i].a[1], w[i].a[3]), w[i].mxi = 2;
			if (w[i].a[3] == maxx)
				w[i].x = maxx - max(w[i].a[1], w[i].a[2]), w[i].mxi = 3;
		}
		sort(w + 1, w + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			if (w[i].x == 0)
				ans += w[i].mx;
			else {
				if (s[w[i].mxi] < lim)
					s[w[i].mxi]++, ans += w[i].mx;
				else
					ans += w[i].mx - w[i].x;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}