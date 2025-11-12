#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
using ll = long long;
int a[N][3], pos[N];
priority_queue<int, vector<int>, greater<int> > q;
inline void work() {
	int n;
	cin >> n;
	while (q.size()) q.pop();
	ll ans = 0;
	int cnt[3] = {};
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		pos[i] = max_element(a[i], a[i] + 3) - a[i];
		ans += a[i][pos[i]], ++cnt[pos[i]];
	}
	for (int k = 0; k < 3; k++)
		if (cnt[k] > n / 2) {
			// cerr << "to there:" << endl;
			for (int i = 1; i <= n; i++)
				if (pos[i] == k)
					q.push(min(a[i][k] - a[i][k ? 0 : 1], a[i][k] - a[i][k == 2 ? 1 : 2]));
			// assert(q.size() == cnt[k]);
			while (q.size() > n / 2) ans -= q.top(), q.pop();
		}
	cout << ans << endl;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) work();
	// cerr << double(clock()) / CLOCKS_PER_SEC << endl;
	return 0;
}