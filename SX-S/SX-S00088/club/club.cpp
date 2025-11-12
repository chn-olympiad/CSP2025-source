#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define int long long
using namespace std;
const int maxn = 2e3 + 5;
ll t, cnt[4], ans, a[maxn][maxn], anss = -1, n;

void dfs(int x) {
	if (x == n) {
		for (int i = 1; i <= 3; i++) {
			if (cnt[i] < n / 2) {
				ans += a[x][i];
				anss = max(anss, ans);
				ans -= a[x][i];
			}
		}
		return ;
	}
	for (int i = 1; i <= 3; i++) {
		if (cnt[i] < n / 2) {
			cnt[i]++;
			ans += a[x][i];
			dfs(x + 1);
			ans -= a[x][i];
			cnt[i]--;
		}
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		ans = 0;
		anss = -1;
		memset(cnt, 0, sizeof(cnt));
		memset(a, 0, sizeof(a));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		dfs(1);
		cout << anss << endl;
	}
	return 0;
}

