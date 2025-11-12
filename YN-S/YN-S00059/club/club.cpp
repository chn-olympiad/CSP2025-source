#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
ll t;

struct node {
	ll x, y, z, maxn, id;
} a[N];

bool cmp(node x, node y) {
	return x.maxn > y.maxn;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		memset(a, 0, sizeof a);
		for (ll i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			if (a[i].x > a[i].y) {
				a[i].id = 1;
				a[i].maxn = a[i].x;
			} else {
				a[i].id = 2;
				a[i].maxn = a[i].y;
			}
			if (a[i].maxn < a[i].z) {
				a[i].id = 3;
				a[i].maxn = a[i].z;
			}
		}
		sort(a + 1, a + 1 + n, cmp);
		ll ans = 0, c1 = 0, c2 = 0, c3 = 0;
		for (int i = 1; i <= n; i++) {
			ans += a[i].maxn;
			if (a[i].id == 1)
				c1++;
			else if (a[i].id == 2)
				c2++;
			else
				c3++;
		}
		ll gap = 0;
		if (c1 > n / 2) {
			gap = c1 - n / 2;
			for (int i = n; i >= 1; i--) {
				if (a[i].id == 1) {
					gap--;
					ans -= a[i].maxn;
					ans += max(a[i].y, a[i].z);
				}
				if (gap == 0)
					break;
			}
		} else if (c2 > n / 2) {
			gap = c2 - n / 2;
			for (int i = n; i >= 1; i--) {
				if (a[i].id == 2) {
					gap--;
					ans -= a[i].maxn;
					ans += max(a[i].x, a[i].z);
				}
				if (gap == 0)
					break;
			}
		} else if (c3 > n / 2) {
			gap = c3 - n / 2;
			for (int i = n; i >= 1; i--) {
				if (a[i].id == 3) {
					gap--;
					ans -= a[i].maxn;
					ans += max(a[i].y, a[i].x);
				}
				if (gap == 0)
					break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}