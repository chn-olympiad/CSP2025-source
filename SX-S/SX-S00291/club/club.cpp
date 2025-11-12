#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll a[100], b[100], c[100], n, t, ans;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t ;
	while (t--) {
		cin >> n;
		ans = 0;
		memset(a, 0, sizeof a);
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 2; j <= n + 1; j++) {
				if (a[j] <= a[j - 1])
					swap( a[j], a[j - 1]);
			}
		}
		for (int i = n + 1; i > n / 2 + 1; i--) {
			ans += a[i];

		}
		cout << ans << "\n";
	}
	return 0;
}