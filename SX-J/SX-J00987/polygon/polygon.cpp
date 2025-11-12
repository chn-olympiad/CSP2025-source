#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n, a[5000], ans, sum, nm = INT_MIN;
string q;

void dfs(ll i, ll j, ll f, ll mmm, ll mma) {
	if (j == i) {
		if (mma > mmm * 2) {
			ans++;
		}
		return ;
	}
	for (ll u = f + 1; u <= n; u++) {
		dfs(i, j + 1, u, max(mmm, a[u]), mma + a[u]);
	}
	return ;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > nm)
			nm = a[i];
		sum += a[i];
	}
	if (nm * 2 < sum)
		ans++;
	for (ll i = 3; i <= n; i++) {
		dfs(i, 1, 0, 0, 0);
	}
	cout << ans;
	return 0;
}
