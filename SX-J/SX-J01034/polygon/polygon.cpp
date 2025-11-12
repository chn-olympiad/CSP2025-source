#include <bits/stdc++.h>
#define ll long long
const ll N = 1e5+10;
using namespace std;
ll n;
ll a[N];
ll s[N];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		ans = max(ans, a[i]);
	}
	ll cnt = 0;
	if (n == 3) {
		if (s[n] > ans * 2) {
			cnt++;
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
