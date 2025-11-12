#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e3+10;
ll n, a[N], m = 0, s = 0, t[N], v = 0, w = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		m = max(a[i], m);
		s += a[i];
	}
	if (m < s * 2) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}