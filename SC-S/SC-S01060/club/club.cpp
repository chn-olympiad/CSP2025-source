
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 1e5 + 10;
typedef array<ll, 3> pi3;
pi3 a[N];
ll t, n, ans;
vector<ll> tong[3];
vector<ll> uppd[3];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while (t--) {
		uppd[0].clear(); uppd[1].clear(); uppd[2].clear();
		tong[0].clear(); tong[1].clear(); tong[2].clear();
		ans = 0;
		scanf("%lld", &n);
		for (ll i = 1; i <= n; ++i) {
			scanf("%lld%lld%lld", &a[i][0], &a[i][1], &a[i][2]);
			ll id = 0;
			if (a[i][1] > a[i][id])	id = 1;
			if (a[i][2] > a[i][id])	id = 2;
			ans += a[i][id], tong[id].push_back(i);
		}
		for (ll i = 0; i < 3; ++i) {
			ll m = tong[i].size();
			for (ll j = 0, id = 0, now = 0; j < m; ++j) {
				now = 0;
				id = tong[i][j];
				if (i != 0)	now = max(now, a[id][0]);
				if (i != 1)	now = max(now, a[id][1]);
				if (i != 2)	now = max(now, a[id][2]);
				uppd[i].push_back(now - a[id][i]);
			}
		}
		for (ll i = 0; i < 3; ++i) {
			ll m = uppd[i].size();
			sort(uppd[i].begin(), uppd[i].end());
			if (2 * m > n) {
				for (ll j = n / 2; j < m; ++j) {
					ans += uppd[i][j];
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
