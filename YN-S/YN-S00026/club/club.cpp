#include <bits/stdc++.h>
#define int long long
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		bool cnt1 = true, cnt2 = true;
		int a[100005], b[100005], c[100005];
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			cin >> b[i];
			cin >> c[i];
			if (b[i] != 0)
				cnt1 = false;
			if (c[i] != 0)
				cnt2 = false;
		}
		if (cnt1 == true && cnt2 == true) {
			sort(a + 1, a + 1 + n, cmp);
			int ans = 0;
			for (int i = 1; i <= n / 2; i++) {
				ans += a[i];
			}
			cout << ans << '\n';
		} else if (cnt1 == true || cnt2 == true) {
			cout << 0 << '\n';
		} else if (n == 2) {
			int no, ans = 0;
			if (a[1] >= b[1]) {
				if (a[1] >= c[1]) {
					ans += a[1];
					no = 1;
				} else {
					ans += c[1];
					no = 3;
				}
			} else {
				if (b[1] > c[1]) {
					ans += b[1];
					no = 2;
				} else {
					ans += c[1];
					no = 3;
				}
			}
			if (no == 1)
				ans += max(b[2], c[2]);
			if (no == 2)
				ans += max(a[2], c[2]);
			if (no == 3)
				ans += max(a[2], b[2]);
			cout << ans << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
	return 0;
}
