#include <bits/stdc++.h>
using namespace std;
long long t, n;
long long a[100005][5];
long long ans = 0;
long long cnt[4], flag[100005][5];
bool ff = 0;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		ff = 0;
		memset(flag, -1, sizeof(flag));
		bool f = 1;
		long long maxn = -3;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				maxn = max(maxn, a[i][j]);
			}
			ans += maxn;
		}
		cout << ans << endl;
	}
	return 0;
}
