#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T;
int n;
int a[N][3], ans;
int c[N];
bool cmp(int x, int y) {
	return c[x] > c[y];
}
vector<int>v[3];

void solve() {
	ans = 0;
	for (int i = 0; i < 3; i++) v[i].clear();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		int mx = max({a[i][0], a[i][1], a[i][2]});
		if (mx == a[i][0]) v[0].push_back(i), c[i] = min(a[i][0] - a[i][1], a[i][0] - a[i][2]);
		else if (mx == a[i][1]) v[1].push_back(i), c[i] = min(a[i][1] - a[i][0], a[i][1] - a[i][2]);
		else v[2].push_back(i), c[i] = min(a[i][2] - a[i][0], a[i][2] - a[i][1]);
		ans += mx;
	}
	int mn = max({v[0].size(), v[1].size(), v[2].size()});
	if (mn * 2 <= n) {
		cout << ans << '\n';
		return;
	}
	for (int p = 0; p < 3; p++)
		if ((int)v[p].size() * 2 > n) {
			sort(v[p].begin(), v[p].end(), cmp);
			while ((int)v[p].size() * 2 > n) {
				int t = v[p].back();
				ans -= c[t];
				v[p].pop_back();
			}
		}
	cout << ans << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) solve();
	return 0;
}
