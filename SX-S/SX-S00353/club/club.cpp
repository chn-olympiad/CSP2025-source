#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, vis[N], A, B, C;

struct Ed {
	int x, y, z, id, ma, mi;
} a[N];

bool cmp(Ed t, Ed tt) {
	if (t.ma - t.mi == tt.ma - tt.mi) {
		return t.ma > tt.ma;
	}
	return t.ma - t.mi > tt.ma - tt.mi;
}

void solve() {
	memset(vis, 0, sizeof(vis));
	A = 0, B = 0, C = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		a[i].id = i;
		a[i].ma = max({a[i].x, a[i].y, a[i].z});
		a[i].mi = ((a[i].x + a[i].y + a[i].z) - a[i].ma - min({a[i].x, a[i].y, a[i].z}));

	}
	sort(a + 1, a + 1 + n, cmp);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int ma = a[i].ma;
		int mi = a[i].mi;
		if (a[i].x == ma) {
			if (A == n / 2) {
				ans = ans + mi;
			} else {
				ans = ans + ma;
				A++;
			}
		} else if (a[i].y == ma) {
			if (B == n / 2) {
				ans = ans + mi;
			} else {
				ans = ans + ma;
				B++;
			}
		} else {
			if (C == n / 2) {
				ans = ans + mi;
			} else {
				ans = ans + ma;
				C++;
			}
		}
	}
	cout << ans << endl;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
