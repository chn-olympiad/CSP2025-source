#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, t, ans;
const ll maxn = 1e5 + 5;
ll a[maxn][4];
ll cnt[4];

inline void dfs(ll goal, ll i) {
	if (i >= n + 1)
		return;
	for (ll j = 1; j <= 3; j++) {
		if (cnt[j] >= n / 2)
			continue;
		else {
			ans = max(ans, goal + a[i][j]);
			cnt[j]++;
			dfs(goal + a[i][j], i + 1);
			cnt[j]--;
		}
	}
}

signed main() {
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	ll b[t + 5];
	ll k = 1;
	while (t--) {
		cin >> n;
		memset(a, 0, sizeof(a));
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= 3; j++)
				cin >> a[i][j];
		}
		ans = 0;
		memset(cnt, 0, sizeof(cnt));
		dfs(0, 1);
		b[k++] = ans;
	}
	for (ll i = 1; i < k; i++)
		cout << b[i] << endl;
}

