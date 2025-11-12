#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define pli pair<ll, int> 
#define fi first
#define se second
const int N = 1e5+10;
int a[N][3];
int b[N];
bool flag[N];
void solve() {
	int n;
	cin >> n;
	rep(i, 1, n) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	int c[3] = {0, 0, 0};
//	int x=0, y=0, z=0;
	ll ans = 0;
	rep(i, 1, n) {
		int maxx = 0;
		rep(j, 0, 2) {
			maxx = max(maxx, a[i][j]);
		}
		if (maxx==a[i][0]) {
			c[0] ++;
			b[i] = 0;
			ans += a[i][0];
		} else if (maxx==a[i][1]) {
			c[1] ++;
			b[i] = 1;
			ans += a[i][1];
		} else {
			c[2] ++;
			b[i] = 2;
			ans += a[i][2];
		}
	}
	int s;
	int maxx = 0;
	rep(i, 0, 2) {
		if (maxx < c[i]) {
			maxx = c[i];
			s = i;
		}
	}
	if (maxx <= n/2) {
		cout << ans << '\n';
		return;
	}
	int t = maxx - n/2;
	priority_queue <pli, vector <pli >, greater<pli > > pq;
	rep(i, 1, n) {
		if (b[i]==s) {
			int x = (s+1)%3;
			int y = (s+2)%3;
			pq.push({a[i][s]-a[i][x], i});
			pq.push({a[i][s]-a[i][y], i});
		}
	}
	rep(i, 1, n) flag[i] = 0;
	int p = 0;
	while (p < t) {
		int x = pq.top().fi;
		int y = pq.top().se;
		pq.pop();
		if (flag[y]) continue;
		flag[y] = 1;
//		cout << x << ' ' << y << ' ' << p << '\n';
		ans -= x;
		p ++;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T --) {
		solve();
	}
	return 0;
}
