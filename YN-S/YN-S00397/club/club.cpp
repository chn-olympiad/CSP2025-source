#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 50;
int a[N];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t, n, b, c;
	cin >> t;
	while (t--) {//ÌØÊâÐÔÖÊA
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b >> c;
		}
		sort(a + 1, a + n + 1, greater<int>());
	}
	int ans = 0;
	for (int i = 1; i <= n / 2; i++) {
		ans += a[i];
	}
	cout << ans;

	return 0;
}
