#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005], b[100005], c[100005];
long long ans = 0, cnt = 0;

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		ans = 0;
		cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		sort(a + 1, a + n + 1);
		int mid = n / 2;
		//cout << mid;
		for (int i = n; i >= mid + 1; i--) {
			ans += a[i];
			//cout << ans;
		}
		cout << ans;
	}
	return 0;
}