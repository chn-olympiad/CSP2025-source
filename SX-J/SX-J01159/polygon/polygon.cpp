#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n[5010];
ll a;
ll ans;

void dfs(ll i, ll zz) {
	if (i > a)
		return;
	if (n[i] < zz) {
		ans++;
		ans %= 998244353;
	}
	dfs(i + 1, zz + n[i]);
	dfs(i + 1, zz);
	return;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> a;
	for (ll i = 1; i <= a; i++) {
		cin >> n[i];
	}
	sort(n + 1, n + 1 + a);
	dfs(1, 0);
	cout << ans;
	return 0;
}
