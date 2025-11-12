#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5+10;
ll a[N][3], b[N];
int cnt[3];
int n, tot;
ll ans;

void solve() {
	cnt[0] = cnt[1] = cnt[2] = 0;
	ans = 0;
	tot = 0;
	cin >> n;
	for (int i=1; i<=n; ++i) {
		for (int j=0; j<3; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i=1; i<=n; ++i) {
		if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) {
			++cnt[0];
			ans += a[i][0];
		} else if (a[i][1]>= a[i][2]) {
			++cnt[1];
			ans += a[i][1];
		} else {
			++cnt[2];
			ans += a[i][2];
		}
	}
	int m = n / 2;
	if (cnt[0] <= m && cnt[1] <= m && cnt[2] <= m) {
		cout << ans << '\n';
		return;
	}
	int tag = 0;
	if (cnt[1] > m) tag = 1;
	if (cnt[2] > m) tag = 2;
	
	for (int i=1; i<=n; ++i) {
		if (a[i][tag] == max({a[i][0], a[i][1], a[i][2]})) {
			ll tmp = -1e9;
			for (int j=0; j<3; ++j) {
				if (j != tag){
					tmp = max(-a[i][tag]+a[i][j], tmp);
				}
			}
			b[++tot] = tmp;
		}
	
	}
	
	int lev = cnt[tag] - m;
	sort(b+1, b+tot+1, greater<int>());
	for (int i=1; i<=lev; ++i) ans += b[i];
	cout << ans << '\n';
}

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}

