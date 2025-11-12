#include <bits/stdc++.h>
int n, dn, a[131072][3], d[131072];
int main() {
	freopen("club.in", "rb", stdin);
	freopen("club.out", "wb", stdout);
	int T;
	for(scanf("%d", &T); T--; ) {
		scanf("%d", &n), dn = n / 2;
		int cnt[3] = {0, 0, 0};
		long long ans = 0;
		for(int i = 1; i <= n; i++)
			scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]),
			d[i] = std::max_element(a[i], a[i] + 3) - a[i],
			ans += a[i][d[i]], cnt[d[i]]++;
		int p = std::max_element(cnt, cnt + 3) - cnt;
		if(cnt[p] > dn) {
			std::vector<int> o;
			for(int i = 1; i <= n; i++)
				if(d[i] == p)
					std::sort(a[i], a[i] + 3),
					o.push_back(a[i][2] - a[i][1]);
			std::sort(o.begin(), o.end());
			for(int i = 0; i < cnt[p] - dn; i++)
				ans -= o[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
