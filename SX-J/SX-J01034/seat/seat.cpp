#include <bits/stdc++.h>
#define ll long long
const ll N = 100;
using namespace std;
ll a[N];
ll n, m;
ll ans;

bool cmp(ll c, ll b) {
	return c > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;
	ll zhs = n;
	ll cnt = n * m;
	for (ll i = 1; i <= cnt; i++) {
		cin >> a[i];
	}

	ll sum = a[1];
	sort(a + 1, a + cnt + 1, cmp);
	for (ll i = 1; i <= cnt; i++) {
		if (a[i] == sum) {
			ans = i;
			break;
		}
	}
	ll ls = 0;
	if (ans % zhs == 0) {
		ls = ans / zhs;
	} else {
		ls = ans / zhs + 1;
	}
	ll ys = ans % zhs;
	ll hs = 0;
	ll lls = ls;
	if (lls % 2 == 0) {
		if (ans % zhs == 0) {
			hs = 1;
		} else {
			hs = zhs - ys + 1;
		}
	} else if (lls % 2 != 0) {
		if (ans % zhs == 0) {
			hs = zhs;
		} else {
			hs = ys;
		}
	}
	cout << ls << " " << hs;
	return 0;
}
