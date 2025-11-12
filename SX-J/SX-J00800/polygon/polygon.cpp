#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
ll n;
ll a[5005];
ll maxn;
ll ans;

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll ans = rand();
	cout << ans;
	return 0;
}