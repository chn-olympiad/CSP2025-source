#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
typedef long long ll;
typedef pair<ll, ll> pll;

struct nd {
	ll u, v, w;
};
ll n, m, k;
vector<nd> p;

ll f[maxn];
ll cnt[maxn];
ll c[11][maxn];
int ask(int x) {
	return f[x] == x ? x : f[x] = ask(f[x]);
}

void add(int x, int y) {
	int fx = ask(x), fy = ask(y);
	f[fx] = fy;
	cnt[fy] += cnt[fx];
}
vector<int> e[maxn];

bool check(int x, int y) {
	return ask(x) == ask(y);
}

void solve() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)

		f[i] = i, cnt[i] = 1;

	for (int i = 1; i <= m; i++) {

		ll u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		p.push_back({u, v, w});
	}

	for (int i = 1; i <= k; i++) {

		scanf("%lld", &c[i][0]);

		for (int j = 1; j <= n; j++)

			scanf("%lld", &c[i][j]);
	}

	for (int i = 1; i <= k; i++) {

		int f = 0;

		for (int j = 1; j <= n; j++)

			if (c[i][j] != 0)
				f = 1;

		if (f == 0) {
			cout << 0 << endl;
			return ;
		}
	}

	sort(p.begin(), p.end(), [](nd x, nd y) {
		return x.w < y.w;
	});
	ll ans = 0;

	for (nd X : p) {
		ll u = X.u, v = X .v, w = X.w;

		if (check(u, v))
			continue;
		ans += w;
		add(u, v);


		if (cnt[ask(1)] == n)
			break;
	}

	cout << ans << endl;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int t = 1;
//	cin >> t;

	while (t--)
		solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}