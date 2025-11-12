#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll M = 5000 + 3;
ll n, a[M], m = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		m = max(m, a[i]);
	}
	if (n == 3 && a[1] + a[2] + a[3] > 2 * m) {
		cout << 1;
		return 0;
	} else {
		cout << 0;
		return 0;
	}
	return 0;
}