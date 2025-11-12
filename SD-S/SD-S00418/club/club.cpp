#include <bits/stdc++.h>
using namespace std;
int t, n;
bool f;
struct node {
	int x, y, z;
}a[100005];
bool cmp(node aa, node bb) {
	return aa.x > bb.x;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		f = true;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			if (!(a[i].y == 0 || a[i].z == 0)) {
				f = false;
			}
		}
		/* n == 2 */
		if (n == 2) {
			int ans1 = max(a[1].x + a[2].y, a[1].x + a[2].z);
			int ans2 = max(a[1].y + a[2].x, a[1].y + a[2].z);
			int ans3 = max(a[1].z + a[2].y, a[1].z + a[2].x);
			cout << max(ans1, max(ans2, ans3)) << endl;
		} else if (f) {
			sort(a + 1, a + n + 1, cmp);
			long long ans = 0;
			for (int i = 1; i <= n / 2; i++) {
				ans += a[i].x;
			}
			cout << ans << endl;
		}
	}
	return 0;
}
