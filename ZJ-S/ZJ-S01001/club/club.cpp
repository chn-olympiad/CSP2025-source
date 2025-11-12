#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
priority_queue <int, vector <int>, greater <int> > q[4];
int ans, n, a[N][4], T;
signed main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	ios :: sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> T;
	while (T--) {
		ans = 0;
		for (int i = 1; i <= 3; i++)
			while (!q[i].empty ())
				q[i].pop ();
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		for (int i = 1; i <= n; i++) {
			int mx = 0, mex = 0;
			for (int j = 1; j <= 3; j++) {
				if (a[i][j] >= a[i][mx]) {
					mex = mx;
					mx = j;
				}
				else if (a[i][j] >= a[i][mex])
					mex = j;
			}
			q[mx].push (a[i][mx] - a[i][mex]);
			ans += a[i][mx];
			if (q[mx].size () > n / 2) {
				int x = q[mx].top ();
				q[mx].pop ();
				ans -= x;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}