#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
ll h = 1, l = 1;
ll a[110];

ll cmp(ll x, ll y) {
	return x > y;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	cout << a[1];
	return 0;
}
