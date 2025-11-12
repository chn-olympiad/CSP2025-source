#include <cstdint>
#include <iostream>
#include <queue>
#include <utility>
#define endl '\n'

using namespace std;

using pii = pair<int, int>;
using pip = pair<int, pii>;

constexpr int N = 1e5 + 10;
pii a[N][3];
queue<pii> q;
int n, cnt[3], ans;
priority_queue<pip, vector<pip>, greater<pip>> qq[3];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	while (T --> 0) {
		ans = 0;
		cnt[0] = cnt[1] = cnt[2] = 0;
		while (!q.empty()) q.pop();
		for (int i = 0; i < 3; i++)
			while (!qq[i].empty()) qq[i].pop();
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][0].first >> a[i][1].first >> a[i][2].first;
			a[i][0].second = 0, a[i][1].second = 1, a[i][2].second = 2;
			if (a[i][0] < a[i][1]) swap(a[i][0], a[i][1]);
			if (a[i][1] < a[i][2]) swap(a[i][1], a[i][2]);
			if (a[i][0] < a[i][1]) swap(a[i][0], a[i][1]);
			q.emplace(i, 0);
		}
		while (!q.empty()) {
			pii u = q.front(); q.pop();
			int wnt = a[u.first][u.second].second;
			if (cnt[wnt] < (n >> 1)) {
				cnt[wnt]++, ans += a[u.first][u.second].first;
				if (u.second < 2)
					qq[wnt].emplace(a[u.first][u.second].first - a[u.first][u.second + 1].first, u);
			} else if (!qq[wnt].empty() && qq[wnt].top().first < a[u.first][u.second].first - a[u.first][u.second + 1].first) {
				pip v = qq[wnt].top(); qq[wnt].pop();
				ans = ans + a[u.first][u.second].first - a[v.second.first][v.second.second].first;
				q.emplace(v.second.first, v.second.second + 1);
				if (u.second < 2)
					qq[wnt].emplace(a[u.first][u.second].first - a[u.first][u.second + 1].first, u);
			} else q.emplace(u.first, u.second + 1);
		}
		cout << ans << endl;
	}
	return 0;
}
