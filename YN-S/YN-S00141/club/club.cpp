//cl csp-s T1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 5;

struct node {
	ll id, val;
} a[N][5], vis[5];

bool cmp(node x, node y) {
	return x.val > y.val;
}
ll c[N], tot;

bool ccmp(ll x, ll y) {
	return x > y;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		ll ans = 0;
		ll n;
		cin >> n;
		vis[1].val = vis[2].val = vis[3].val = 0;
		vis[1].id = 1, vis[2].id = 2, vis[3].id = 3;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j].val;
				a[i][j].id = j;
			}
			sort(a[i] + 1, a[i] + 1 + 3, cmp);
			vis[a[i][1].id].val++;
			ans += a[i][1].val;
		}
		sort(vis + 1, vis + 1 + 3, cmp);
		tot = 0;
		if (vis[1].val > n / 2) {
			int x = vis[1].val - (n / 2);
			for (int i = 1; i <= n; i++) {
				if (a[i][1].id == vis[1].id) {
					c[++tot] = a[i][2].val - a[i][1].val;
				}
			}
			sort(c + 1, c + 1 + tot, ccmp);
			for (int i = 1; i <= x; i++) {
				ans += c[i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}