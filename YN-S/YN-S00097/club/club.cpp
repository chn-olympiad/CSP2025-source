#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
typedef long long ll;
typedef pair<ll, ll> pll;

ll a[maxn][5];
ll n;
struct nd {
	ll val, cb, id;
};
bool vis[maxn];
ll cnt[10];

ll st(int i) {
	vector<pll> v;

	for (int j = 1; j <= 3; j++)

		v.push_back({a[i][j], j});
	sort(v.begin(), v.end());
	return v[2].second;
}

ll nd(int i) {
	vector<pll> v;

	for (int j = 1; j <= 3; j++)

		v.push_back({a[i][j], j});
	sort(v.begin(), v.end());
	return v[1].second;
}
priority_queue<pll, vector<pll>, greater<pll>> q[4];
ll c[maxn];

void solve() {
	cin >> n;

	for (int i = 1; i <= 3; i++) {

		while (!q[i].empty())
			q[i].pop();
	}

	for (int i = 1; i <= n; i++)

		for (int j = 1; j <= 3; j++)

			scanf("%lld", &a[i][j]);

	for (int i = 1; i <= n; i++) {

		q[st(i)].push({a[i][st(i)] - a[i][nd(i)], i});
		c[i] = st(i);
	}

	ll m = n / 2;

	for (int j = 1; j <= 3; j++) {

		while (q[j].size() > m) {
			pll x = q[j].top();
			q[j].pop();
			int id = x.second;
			c[id] = nd(id);
		}
	}

	ll ans = 0;

	for (int i = 1; i <= n; i++)

		ans += a[i][c[i]];
	printf("%lld \n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = 1;
	cin >> t;

	while (t--)
		solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}