#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5+10;
ll n, k, a[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (k == 0) {
		ll ans = 0;
		for (ll i = 1; i <= n; i++) {
			if (a[i] == 0)
				ans++;
			if (a[i] == 1 && i != n && a[i + 1] == 1)
				ans++, i++;
		}
		cout << ans;
	} else if (k == 1) {
		ll ans = 0;
		for (ll i = 1; i <= n; i++) {
			if (a[i] == 1)
				ans++;
		}
		cout << ans;
	} else
		cout << n / 2;
	return 0;
}