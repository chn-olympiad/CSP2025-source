#include <bits/stdc++.h>
using namespace std;
struct node {
	int id;
	int val;
	int a[3];
};
vector<node> v[4];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		int ans = 0;
		v[1].clear();
		v[2].clear();
		v[3].clear();
		for (int i = 1; i <= n; i++) {
			node x;
			cin >> x.a[1] >> x.a[2] >> x.a[3];
			int mx = max(max(x.a[1], x.a[2]), x.a[3]);
			if (x.a[1] == mx) {
				x.val = mx - max(x.a[2], x.a[3]);
				v[1].emplace_back(x);
			} else if (x.a[2] == mx) {
				x.val = mx - max(x.a[1], x.a[3]);
				v[2].emplace_back(x);
			} else if (x.a[3] == mx) {
				x.val = mx - max(x.a[1], x.a[2]);
				v[3].emplace_back(x);
			}
			ans += mx; 
		} 
		if (v[1].size() > n / 2) {
			sort(v[1].begin(), v[1].end(), [](node a, node b) {
				return a.val < b.val;
			});
			for (int i = 0; i < v[1].size() - n / 2; i++) {
				ans -= v[1][i].val;
			}
		}
		if (v[2].size() > n / 2) {
			sort(v[2].begin(), v[2].end(), [](node a, node b) {
				return a.val < b.val;
			});
			for (int i = 0; i < v[2].size() - n / 2; i++) {
				ans -= v[2][i].val;
			}
		}
		if (v[3].size() > n / 2) {
			sort(v[3].begin(), v[3].end(), [](node a, node b) {
				return a.val < b.val;
			});
			for (int i = 0; i < v[3].size() - n / 2; i++) {
				ans -= v[3][i].val;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
