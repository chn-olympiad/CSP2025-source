#include <bits/stdc++.h>
#define ll long long
#define mid ((l + r) >> 1)
#define lowbit(x) (x & -x)

using namespace std;

constexpr int N = 1e5 + 5;

int T, n;
int a[N][4], p[N], w[N], ord[N], cnt[4];

void Solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 3; ++j) {
			cin >> a[i][j];
		}
	}
	
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; ++i) {
		if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
			p[i] = 1;
			w[i] = (a[i][2] > a[i][3] ? 2 : 3);
		} else if (a[i][2] >= a[i][3]) {
			p[i] = 2;
			w[i] = (a[i][1] > a[i][3] ? 1 : 3);
		} else {
			p[i] = 3;
			w[i] = (a[i][1] > a[i][2] ? 1 : 2);
		}
		cnt[p[i]]++;
	}
	int k = 0;
	for (int i = 1; i <= 3; ++i) {
		if (cnt[i] > n / 2) {
			k = i;
			break;
		}
	}
	if (k) {
		int m = 0;
		for (int i = 1; i <= n; ++i) {
			if (p[i] == k) {
				ord[++m] = i;
			}
		}
		assert(m == cnt[k]);
		sort(ord + 1, ord + m + 1, [](int i, int j) {
			return a[i][p[i]] - a[i][w[i]] < a[j][p[j]] - a[j][w[j]];
		});
		for (int i = 1; i <= cnt[k] - n / 2; ++i) {
			p[ord[i]] = w[ord[i]];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += a[i][p[i]];
	}
	
	cout << ans << '\n';
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> T;
	while (T--) {
		Solve();
	}
	
	return 0;
}
