#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[1234567];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ll n, ma = -1, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		if (a[i] > ma) {
			ma = a[i];
		}
	}
	if (n < 3 or sum <= 2 * ma) {
		cout << 0;
		return 0;
	}

	return 0;
}