#include <bits/stdc++.h>
#define int long long 

using namespace std;
const int N = 1e5 + 5;
int a[N][3];
vector <int> x;
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T --) {
		int n; cin >> n;
		for (int i = 1 ; i <= n ; i ++) 
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		int cnt[3] = {0, 0, 0};
		int ans = 0;
		for (int i = 1 ; i <= n ; i ++) {
			int mx = max({a[i][0], a[i][1], a[i][2]});
			if (mx == a[i][0]) {
				cnt[0] ++;
				ans += a[i][0];
			} else if (mx == a[i][1]) {
				cnt[1] ++;
				ans += a[i][1];
			} else if (mx == a[i][2]) {
				cnt[2] ++;
				ans += a[i][2];
			}
		}
		int w = -1;
		if (cnt[0] > n / 2) w = 0;
		if (cnt[1] > n / 2) w = 1;
		if (cnt[2] > n / 2) w = 2;
		if (w == -1) {
			cout << ans << '\n';
			continue;
		}
		x.clear();
		for (int i = 1 ; i <= n ; i ++) {
			int mx = max({a[i][0], a[i][1], a[i][2]});
			if (a[i][w] == mx) {
				int mx2 = 0;
				for (int j = 0 ; j < 3 ; j ++)
					if (j != w) mx2 = max(mx2, a[i][j]);
				x.push_back(mx - mx2);
			}
		}
		sort(x.begin(), x.end());
		int del = cnt[w] - n / 2;
		for (int v : x) {
			if (del) {
				ans -= v;
				del --;
			} else break;
		}
		cout << ans << '\n';
	}
	return 0;
}