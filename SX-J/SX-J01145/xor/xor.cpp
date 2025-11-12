#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e3+10;
ll n, k, a[N], x = 0, y = 0, t;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	t = a[1];
	if (a[1] == k) {
		x++;
		y = 1;
	}
	for (ll i = 2; i <= n; i++) {
		if (y == 1) {
			y = 0;
			t = a[i];
		} else if (y == 0) {
			t = a[i] ^ t ;
		}
		if (t == k) {
			x++;
			y = 1;
		}
	}
	cout << x;
	return 0;
}