#include <bits/stdc++.h>
using namespace std;
int ans, t, n, a[100005], b[100005], c[100005], maxx;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	int t21 = t / 2;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			maxx = max(max(a[i], b[i]), max(b[i], c[i]));
			ans += maxx;
		}
		cout << ans << endl;
	}
	return 0;
}