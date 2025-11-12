#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 5;

int n, a[N][4];

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 3; j++)
			cin >> a[i][j];
	vector<int> v[4];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int p = 0; a[i][p] = -1;
		for (int j = 1; j <= 3; j++) {
			if (a[i][p] <= a[i][j]) p = j;	
		}
		v[p].push_back(i);
		ans += a[i][p];
	}
	for (int k = 1; k <= 3; k++) {
		int o = v[k].size();
		if (o <= n / 2) continue;
		int ne = o - (n / 2);
		vector<int> q;
		for (auto b : v[k]) {
			int h = 0;
			for (int j = 1; j <= 3; j++) if (j != k) h = max(h, a[b][j]);
			q.push_back(h - a[b][k]);
		}
		sort (q.begin(), q.end());
		int i = (int)q.size() - 1;
		while (ne--) {
			ans += q[i];
			i--;
		}
	}
	cout << ans << "\n";
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	int _; cin >> _;
	while (_--) solve();
	return 0;
}
