#include <bits/stdc++.h>
#define E(i, l, r) for(int i = l;i <= r;++ i)
using ll = long long;
using namespace std;
int tt;
namespace wangcy {
	const int N = 1e6 + 10;
	ll n, x, y, z, ans;
	inline ll max3(ll val1, ll val2, ll val3) {
		return max(val1, max(val2, val3));
	}
	struct node{
		ll a, b, c, mx;
	}a[N];
	vector <ll> dlt;
	inline void Main() {
		dlt.clear(), x = y = z = ans = 0;
		cin >> n;
		E(i, 1, n) cin >> a[i].a >> a[i].b >> a[i].c, a[i].mx = max3(a[i].a, a[i].b, a[i].c);
		E(i, 1, n) {
			ll mx = a[i].mx;
			if(a[i].a == mx) ++ x;
			else if(a[i].b == mx) ++ y;
			else ++ z;
			ans += mx;
		}
		ll mx = max3(x, y, z);
		if(mx <= n/2) return cout << ans << "\n", void();
		if(x == mx) {
			ll d = x - (n/2);
			E(i, 1, n) if(a[i].a == a[i].mx) dlt.emplace_back(a[i].a - max(a[i].b, a[i].c));
			stable_sort(dlt.begin(), dlt.end());
			E(i, 0, d - 1) ans -= dlt[i];
		} else if(y == mx) {
			ll d = y - (n/2);
			E(i, 1, n) if(a[i].b == a[i].mx) dlt.emplace_back(a[i].b - max(a[i].a, a[i].c));
			stable_sort(dlt.begin(), dlt.end());
			E(i, 0, d - 1) ans -= dlt[i];
		} else {
			ll d = z - (n/2);
			E(i, 1, n) if(a[i].c == a[i].mx) dlt.emplace_back(a[i].c - max(a[i].a, a[i].b));
			stable_sort(dlt.begin(), dlt.end());
			E(i, 0, d - 1) ans -= dlt[i];
		}
		return cout << ans << "\n", void();
	}
}
int main() {
	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> tt;
	while(tt --) wangcy::Main();
	return 0;
}
// freopen 
// IOS SYNC WITH STDIO
// CLEAR CASES
// long long

// Ex : 100pts.