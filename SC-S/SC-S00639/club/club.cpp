#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;

priority_queue <int> q[5];

void solve () {
	cin >> n; int a[5] = {} , cnt1 = 0 , cnt2 = 0 , cnt3 = 0;
	int ans = 0;
	for (int i = 1;i <= 3;i ++) while (!q[i].empty ()) q[i].pop();
	for (int i = 1;i <= n;i ++) {
		int x , y , z; cin >> x >> y >> z;
		int mx = max (x , max (y , z));
		a[1] = x; a[2] = y; a[3] = z;
		sort (a + 1 , a + 1 + 3);
		if (a[3] == x) ans += x , cnt1 ++ , q[1].push (a[2] - a[3]);
		else if (a[3] == y) ans += y , cnt2 ++ , q[2].push (a[2] - a[3]);
		else ans += z , cnt3 ++ , q[3].push (a[2] - a[3]);
	}
	if (cnt1 > n / 2) {
		while (q[1].size() > n / 2) ans += q[1].top() , q[1].pop();
		cout << ans << '\n';
	}
	else if (cnt2 > n / 2) {
		while (q[2].size() > n / 2) ans += q[2].top() , q[2].pop();
		cout << ans << '\n';
	}
	else if (cnt3 > n / 2) {
		while (q[3].size() > n / 2) ans += q[3].top() , q[3].pop();
		cout << ans << '\n';
	}
	else cout << ans << '\n';
}

signed main () {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen ("club.in" , "r" , stdin);
	freopen ("club.out" , "w" , stdout);
	int T; cin >> T; while (T --) solve ();
	return 0;
}