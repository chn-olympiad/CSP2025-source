#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N][4];
pair <int, int> b[N][4];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		b[i][1] = make_pair(a[i][1], 1);
		b[i][2] = make_pair(a[i][2], 2);
		b[i][3] = make_pair(a[i][3], 3);
		sort(b[i] + 1, b[i] + 4, greater <pair <int, int>>());
	}
	vector <priority_queue <int>> Q(4);
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		if (Q[b[i][1].second].size() < n / 2) {
			Q[b[i][1].second].emplace(-b[i][1].first + b[i][2].first);
			ans += b[i][1].first;
		} else {
			if (Q[b[i][1].second].top() + b[i][1].first > b[i][2].first) {
				ans += Q[b[i][1].second].top() + b[i][1].first;
				Q[b[i][1].second].pop();
				Q[b[i][1].second].emplace(-b[i][1].first + b[i][2].first);
			} else ans += b[i][2].first;
		}
	}
	cout << ans << '\n';
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) solve();
	return 0;
}