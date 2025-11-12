#include <bits/stdc++.h>
using namespace std;
#defind int long long
const int N = 1e5+5;
int t, n, a[N], b[N], c[N];
const int MAXN = 2e9;

signed main() {
	int num = 0, ans = 0;
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i] >> b[i] >> c[i];
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		sort(c + 1, c + n + 1);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					num = a[i][1] + a[j][2] + a[k][3];
					if (num >= ans) {
						ans = num;
					}
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}





