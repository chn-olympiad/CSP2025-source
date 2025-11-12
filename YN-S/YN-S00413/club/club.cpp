#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t;

struct node {
	int x, y, z;
} a[N];

int cmp(node x, node y) {
	return x.x > y.x;
}

int cmp1(node x, node y) {
	return x.y > y.y;
}

int cmp2(node x, node y) {
	return x.z > y.z;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int n, club1 = 0, club2 = 0, club3 = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		if (n == 2) {
			int ans = -1;
			ans = max(ans, max(a[1].x + a[2].y, max(a[1].x + a[2].z, max(a[1].y + a[2].x, max(a[1].y + a[2].z, max(a[1].z + a[2].x,
			                                        a[1].z + a[2].y))))));
			cout << ans << endl;
		} else if (a[1].y == 0 && a[1].z == 0) {
			int ans = 0;
			sort(a + 1, a + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++) {
				ans += a[i].x;
			}
			cout << ans << endl;
		} else if (a[1].x == 0 && a[1].z == 0) {
			int ans = 0;
			sort(a + 1, a + n + 1, cmp1);
			for (int i = 1; i <= n / 2; i++) {
				ans += a[i].y;
			}
			cout << ans << endl;
		} else if (a[1].x == 0 && a[1].y == 0) {
			int ans = 0;
			sort(a + 1, a + n + 1, cmp2);
			for (int i = 1; i <= n / 2; i++) {
				ans += a[i].z;
			}
			cout << ans << endl;
		} else {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				int maxx = -1;
				maxx = max(maxx, max(a[i].x, max(a[i].y, a[i].z)));
				ans += maxx;
			}
			cout << ans << endl;
		}
	}
	return 0;
}