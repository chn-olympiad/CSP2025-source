#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 999;
ll n, m, ans, a[N], b[N], xh = 1, ZDZ;


int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << 0;
	} else if (n == 2) {
		cout << 0;
	} else {
		if (a[1] + a[2] < a[3]) {
			cout << 0;
		} else if (a[3] + a[2] < a[1]) {
			cout << 0;
		} else if (a[1] + a[3] < a[2]) {
			cout << 0;
		} else {
			cout << 1;
		}

	}
	return 0;
}
