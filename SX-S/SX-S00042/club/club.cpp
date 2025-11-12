#include <bits/stdc++.h>
#define ll long long
#define PII pair <int, int>
#define fi first
#define se second
#define debug() cout << "-----------\n";
using namespace std;
const int MAXN = 1e5 + 10;
const int INF = 1e9;

int n;
vector <int> q[5];
PII a[MAXN][5];

bool cmp (PII x, PII y) {
	return x.fi > y.fi;
}

signed main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);

	ios :: sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);

	int t;
	cin >> t;
	while (t --) {
		q[1] = q[2] = q[3] = {};
		for (int i = 1; i <= 100000; ++ i) {
			for (int j = 1; j <= 3; ++ j) {
				a[i][j] = {0, 0};
			}
		}

		cin >> n;
		ll ans = 0;
		for (int i = 1; i <= n; ++ i) {
			cin >> a[i][1].fi >> a[i][2].fi >> a[i][3].fi;
			a[i][1].se = 1, a[i][2].se = 2, a[i][3].se = 3;
			sort (a[i] + 1, a[i] + 4, cmp);
			q[a[i][1].se].push_back (a[i][1].fi - a[i][2].fi);
			ans += a[i][1].fi;
		}

		int maxid;
		if (q[1].size () >= q[2].size () && q[1].size () >= q[3].size ())
			maxid = 1;
		else if (q[2].size () >= q[1].size () && q[2].size () >= q[3].size ())
			maxid = 2;
		else
			maxid = 3;

		sort (q[maxid].begin (), q[maxid].end ());
		int i = 0, sz = q[maxid].size ();
		while (sz > n / 2) {
			ans -= q[maxid][i ++];
			sz --;
		}

		cout << ans << '\n';
	}

	return 0;
}
