#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN = 1e5+10, N = 1e6+10;
ll t;
ll n;
ll a[300005];
ll mem1, mem2, mem3;

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6];
		if (n == 2)
			cout << max(a[1] + a[5], max(a[1] + a[6], max(a[2] + a[4], max(a[2] + a[6], max(a[3] + a[4], a[3] + a[5])))));
	}
	return 0;
}
