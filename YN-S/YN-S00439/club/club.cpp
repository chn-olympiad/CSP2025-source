#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, a[N][8], ans, sum, cnt[8], n;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		cnt[1] = 0;
		cnt[2] = 0;
		cnt[3] = 0;
		for (int i = 1; i <= n; i++) {
			if (max(a[i][1], max(a[i][2], a[i][3])) == a[i][1] && cnt[1] <= n / 2) {
				ans += a[i][1];
				cnt[1]++;
			} else if (max(a[i][1], max(a[i][2], a[i][3])) == a[i][2] && cnt[2] <= n / 2) {
				ans += a[i][2];
				cnt[2]++;
			} else if (max(a[i][1], max(a[i][2], a[i][3])) == a[i][3] && cnt[3] <= n / 2) {
				ans += a[i][3];
				cnt[3]++;
			}
		}
		cout << ans << endl;
	}

	return 0;
}