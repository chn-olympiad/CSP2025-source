#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6+10;
ll n, m, a[N], ans, wz;

bool cmp(ll x, ll y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << "1 1";
		return 0;
	}
	for (ll i = 1; i <= n * m; i++)
		cin >> a[i];
	ans = a[1];
	ll sz = n * m;
	sort(a + 1, a + 1 + sz, cmp);
	for (ll i = 1; i <= n * m; i++) {
		if (a[i] == ans)
			wz = i;
	}
	ll x = ans % wz, y = ans % n;
	if (x == 0)
		x = 1;
	if (y == 0)
		y = 1;
	cout << x << " " << y;
	return 0;
}