#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		long long ans = 0;
		int n;
		cin >> n;
		if (n == 2) {
			int a1, a2, a3, s1, s2, s3;
			cin >> a1 >> a2 >> a3 >> s1 >> s2 >> s3;
			int maxa = max(a1, max(a2, a3));
			int maxs = max(s1, max(s2, s3));
			if (maxa == a1 && maxs != s1) {
				ans += maxa + maxs;
			} else if (maxa == a2 && maxs != s2) {
				ans += maxa + maxs;
			} else if (maxa == a3 && maxs != s3) {
				ans += maxa + maxs;
			}
			cout << ans << "\n";
			continue;
		}
		int hh, mm;
		for (int i = 1; i <= n; i++) {
			cin >> hh >> a[i] >> mm;
		}
		sort(a + 1, a + n + 1);
		for (int i = n; i > n / 2; i--) {
			ans += a[i];
		}
		cout << ans << "\n";
	}

	return 0;
}