#include <bits/stdc++.h>
using namespace std; const int N = 100005;
int n, a[4][N], val[N];
struct node {
	int val, id;
	bool operator<(const node &tmp) const {
		if (val != tmp.val) return val < tmp.val;
		return id < tmp.id;
	}
} b[N];
void work() {
	cin >> n;
	vector<node> g[4];
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int p = 0, mx = -1;
		for (int j = 1; j <= 3; ++j) {
			cin >> a[j][i];
			if (a[j][i] > mx) mx = a[j][i], p = j;
		}
		val[i] = -1;
		for (int j = 1; j <= 3; ++j)
			if (j != p) val[i] = max(val[i], a[j][i]);
		g[p].push_back(node{mx - val[i], i});
		ans += mx;
	}
	for (int i = 1; i <= 3; ++i)
		if (g[i].size() > n / 2) {
			stable_sort(g[i].begin(), g[i].end());
			int cnt = g[i].size();
			for (int j = 0; cnt > n / 2; ++j) {
				ans -= g[i][j].val; --cnt;
			}
		}
	cout << ans << '\n';
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) work(); return 0;
}