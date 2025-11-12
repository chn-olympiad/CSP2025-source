#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T;
ll n, a[100005][5], p[100005], q[100005], t[5], ans, tot, p1, p2;

void dfs (ll no, ll val) {
	if (no > n) {
		ans = max(ans, val);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		tot++;
		if (t[i] <  n / 2) {
			t[i]++;
			dfs(no + 1, val + a[no][i]);
			t[i]--;
		}
	}
}

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			t[i] = 0;
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				if (j == 2) {
					p[i] = a[i][j];
				}
				if (j == 3) {
					q[i] = a[i][j];
				}
				if (a[i][j] != 0 && j > 1) {
					p1 = 0, p2 = 0;
				}
				if (a[i][j] != 0 && j > 2) {
					p2 = 0;
				}
			}
		}
		sort(p + 1, p + 1 + n, greater<ll>());
		sort(q + 1, q + 1 + n, greater<ll>());
		if (p1 == 1) {
			for (int i = 1; i <= n / 2; i++) {
				ans += p[i];
			}
			cout << endl;
			continue;
		}
		dfs(1, 0);
		cout << ans << endl;
	}
	return 0;
}