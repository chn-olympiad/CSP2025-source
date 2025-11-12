#include <bits/stdc++.h>
using namespace std;
int t, n, a[2000005], b[2000005], c[2000005];

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	while (t--) {
		cin >> n;
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		sort(a + 1, a + n + 1);
		for (int i = n; i >= n / 2 + 1; i--) {
			ans += a[i];
		}
		cout << ans << endl;

	}
	return 0;
}
