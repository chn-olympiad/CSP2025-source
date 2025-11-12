#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int T, n, ans, a[N][3], b[N], c[N], cnt[3];

inline void solve() {
	cin >> n;
	ans = 0;
	cnt[0] = cnt[1] = cnt[2] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		b[i] = max_element(a[i], a[i] + 3) - a[i];
		ans += a[i][b[i]];
		++cnt[b[i]];
		c[i] = 0;
		for (int j = 0; j < 3; ++j) {
			if (b[i] != j) {
				c[i] = max(c[i], a[i][j]);
			}
		}
		c[i] = a[i][b[i]] - c[i];
	}
	int p = max_element(cnt, cnt + 3) - cnt;
	if (cnt[p] > (n >> 1)) {
		vector<int> tmp;
		for (int i = 1; i <= n; ++i) {
			if (b[i] == p) {
				tmp.emplace_back(c[i]);
			}
		}
		sort(tmp.begin(), tmp.end());
		tmp.resize(cnt[p] - (n >> 1));
		for (auto u: tmp) {
			ans -= u;
		}
	}
	cout << ans << "\n";
}

int main() {
	assert(freopen("club.in", "r", stdin));
	assert(freopen("club.out", "w", stdout));
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}