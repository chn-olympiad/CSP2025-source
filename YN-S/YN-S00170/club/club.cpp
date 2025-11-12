#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int T, n;

struct A {
	int t[5], x[5];
} a[N];

bool cmp(A p, A q) {
	if (p.t[1] - p.t[2] != q.t[1] - q.t[2])
		return p.t[1] - p.t[2] > q.t[1] - q.t[2];
	return p.t[2] - p.t[3] > q.t[2] - q.t[3];
}

bool check(ll u) {
	int c[4] = {0, 0, 0, 0};
	ll tot = 0;
	for (int i = 1; i <= n; i++) {
		int x1 = a[i].x[1], x2 = a[i].x[2], x3 = a[i].x[3];
		if (c[x1] < n / 2) {
			c[x1]++;
			tot += a[i].t[1];
		} else if (c[x2] < n / 2) {
			c[x2]++;
			tot += a[i].t[2];
		} else if (c[x3] < n / 2) {
			c[x3]++;
			tot += a[i].t[3];
		} else
			return 0;
	}
	return tot >= u;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].t[1] >> a[i].t[2] >> a[i].t[3];
			a[i].x[1] = 1, a[i].x[2] = 2, a[i].x[3] = 3;
			if (a[i].t[1] < a[i].t[2]) {
				swap(a[i].t[1], a[i].t[2]);
				swap(a[i].x[1], a[i].x[2]);
			}
			if (a[i].t[1] < a[i].t[3]) {
				swap(a[i].t[1], a[i].t[3]);
				swap(a[i].x[1], a[i].x[3]);
			}
			if (a[i].t[2] < a[i].t[3]) {
				swap(a[i].t[2], a[i].t[3]);
				swap(a[i].x[2], a[i].x[3]);
			}
		}
		ll l = 0, r = 2e9, ans = 0;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			if (check(mid)) {
				l = mid + 1;
				ans = mid;
			} else
				r = mid - 1;
		}
		cout << ans << '\n';
	}
	return 0;
}