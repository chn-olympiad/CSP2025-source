#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define sz size
#define fi first
#define se second
#define pii pair<int, int>
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 1e5 + 5;

int T, n, d[N], cnt[5];
pii a[N][5];

void solve() {
	cin >> n;
	for (int i = 1, x; i <= n; i++)
		for (int j = 1; j <= 3; j++) {
			cin >> x;
			a[i][j] = {x, j};
		}
	for (int i = 1; i <= n; i++) sort(a[i] + 1, a[i] + 3 + 1, [](pii t, pii tt) {
		return t.fi > tt.fi;
	});
	int ans = 0;
	mem(cnt, 0);
	for (int i = 1; i <= n; i++) {
		d[i] = a[i][1].se;
		cnt[a[i][1].se]++;
		ans += a[i][1].fi;
	}
	for (int j = 1; j <= 3; j++)
		if (cnt[j] > n / 2) {
			vector<int> v;
			for (int i = 1; i <= n; i++)
				if (d[i] == j) v.pb(a[i][1].fi - a[i][2].fi);
			sort(all(v));
			int tot = 0;
			for (auto x : v) {
				ans -= x;
				if (++tot >= cnt[j] - n / 2) break;
			}
		}
	cout << ans << '\n';
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) solve();
	return 0;
}
