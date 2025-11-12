#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int t, n, a[N][5];
map<int, int>mp;
vector<int>h;
int mx[N];

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		h.clear();
		int ans = 0;
		mp[1] = 0, mp[2] = 0, mp[3] = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			mx[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			int ma = -1;
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				if (a[i][j] > ma) {
					mx[i] = j;
					ma = a[i][j];
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			mp[mx[i]]++;
			ans += a[i][mx[i]];
		}
		int kk = 0;
		for (int i = 1; i <= 3; i++) {
			if (mp[i] > n / 2) {
				kk = mp[i];
				int kkk = i;
				for (int k = 1; k <= n; k++) {
					int mi = INT_MAX;
					if (mx[k] == kkk) {

						for (int j = 1; j <= 3; j++) {
							if (j != mx[k]) {
								mi = min(mi, a[k][mx[k]] - a[k][j]);
							}
						}
						h.push_back(mi);
					}
				}
			}
		}

		sort(h.begin(), h.end());
		for (int v : h) {
			ans -= v;
			kk--;
			if (kk <= n / 2)
				break;
		}
		cout << ans << endl;
	}
	return 0;
}