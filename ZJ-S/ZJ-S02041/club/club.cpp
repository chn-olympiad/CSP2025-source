#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int N = 1e5 + 7, M = 1e3;
LL n, dp[N], a[N][5], m;
int t1[N], t2[N], t3[N];
int cnt1, cnt2, cnt3;
void IOS() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	return ;
}
void file() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	return ;
}
void __init() {
	file();
	IOS();
	return ;
}
void solve() {
	cin >> n;
	cnt1 = cnt2 = cnt3 = 0;
	for (int i = 1; i <= n; ++i) {
		a[i][0] = INT_MAX;
		t1[i] = 0;
		t2[i] = 0;
		t3[i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 3; ++j) {
			cin >> a[i][j];
		}
		int x = a[i][1];
		int y = a[i][2];
		int z = a[i][3];
		if (x >= y && y >= z) {
			a[i][0] = min(a[i][0], (LL)x - y);
		}
		if (x >= z && z >= y) {
			a[i][0] = min(a[i][0], (LL)x - z);
		}
		if (y >= x && x >= z) {
			a[i][0] = min(a[i][0], (LL)y - x);
		}
		if (y >= z && z >= x) {
			a[i][0] = min(a[i][0], (LL)y - z);
		}
		if (z >= y && y >= x) {
			a[i][0] = min(a[i][0], (LL)z - y);
		}
		if (z >= x && x >= y) {
			a[i][0] = min(a[i][0], (LL)z - x);
		}
	}
	int m = n / 2;
	for (int i = 1; i <= n; ++i) {
		dp[i] = INT_MIN;
	}
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 3; ++j) {
			dp[i] = max(dp[i], dp[i - 1] + a[i][j]);
		}
		int x = a[i][1];
		int y = a[i][2];
		int z = a[i][3];
		if (x >= y && x >= z) {
			t1[++cnt1] = a[i][0];
		}
		if (y >= x && y >= z) {
			t2[++cnt2] = a[i][0];
		}
		if (z >= x && z >= y) {
			t3[++cnt3] = a[i][0];
		}
	}
	m = n / 2;
	int ans = dp[n];
	int x = max(cnt1, cnt2);
	int y = max(cnt2, cnt3);
	int k = max(x, y);
	if (k <= m) {
		cout << dp[n] << '\n';
		return ;
	}
	if (cnt1 > m) {
		sort (t1 + 1, t1 + cnt1 + 1);
		int d = cnt1 - m;
		for (int i = 1; i <= d; ++i) {
			ans -= t1[i];
		}
	}
	if (cnt2 > m) {
		sort (t2 + 1, t2 + cnt2 + 1);
		int d = cnt2 - m;
		for (int i = 1; i <= d; ++i) {
			ans -= t2[i];
		}
	}
	if (cnt3 > m) {
		sort (t3 + 1, t3 + cnt3 + 1);
		int d = cnt3 - m;
		for (int i = 1; i <= d; ++i) {
			ans -= t3[i];
		}
	}
	cout << ans << "\n";
	return ;
}
int main(void) {
	__init();
	LL _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}