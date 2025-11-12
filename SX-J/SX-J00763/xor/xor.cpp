#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, a[100100];
bool f;

ll yihuo() {
	ll res = 0, sum = 0;
	if (f == 1 && k == 0) {
		return 1;
	}
	for (ll i = 1, j = 1; j >= i && i <= n && j <= n; j++) {
		sum = a[i];
		for (ll t = i + 1; t <= j; t++) {
			sum ^= a[t];
		}
		if (i == j) {
			sum = a[i];
		}
		ll ans = 0 ;
		if (sum == k) {
			ans = j - i ;
		}
		res = max(ans, res);
		if (j == n) {
			i++;
			j = i;
		}
	}
	return res;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			f = 1;
		}
	}
	cout << yihuo();
}
