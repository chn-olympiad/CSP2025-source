#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5+10;
ll t, n, c[N];

struct node {
	ll a, b, c, z;
} a[N];

bool cmp(ll x, ll y) {
	return x < y;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		ll aa = 0, bb = 0, cc = 0, ans = 0;
		for (ll i = 1; i <= n; i++) {
			cin >> a[i].a >> a[i].b >> a[i].c;
			if (a[i].a >= a[i].b && a[i].a >= a[i].c) {
				a[i].z = 1;
				aa++;
				ans += a[i].a;
			} else if (a[i].b >= a[i].a && a[i].b >= a[i].c) {
				a[i].z = 2;
				bb++;
				ans += a[i].b;
			} else if (a[i].c >= a[i].b && a[i].c >= a[i].a) {
				a[i].z = 3;
				cc++;
				ans += a[i].c;
			}
		}
		ll o = 0, oo = 0;
		if (aa > n / 2)
			o = 1, oo = aa - n / 2;
		else if (bb > n / 2)
			o = 2, oo = bb - n / 2;
		else if (cc > n / 2)
			o = 3, oo = cc - n / 2;
		if (o == 0) {
			cout << ans << "\n";
			continue;
		} else {
			for (ll i = 1; i <= n; i++) {
				c[i] = 2e9;
				if (a[i].z == o) {
					if (o == 1)
						c[i] = min(a[i].a - a[i].b, a[i].a - a[i].c);
					else if (o == 2)
						c[i] = min(a[i].b - a[i].a, a[i].b - a[i].c);
					else if (o == 3)
						c[i] = min(a[i].c - a[i].b, a[i].c - a[i].a);
				}
			}
			sort(c + 1, c + n + 1, cmp);
			for (ll i = 1; i <= oo; i++)
				ans -= c[i];
			cout << ans << "\n";
		}
	}
	return 0;
}