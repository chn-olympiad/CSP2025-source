#include <bits/stdc++.h>
using namespace std;
/*
about 20 minutes
60 pts
*/
const int mod = 998244353;
#define ll long long
ll n, ans, maxx;
vector<ll> a;
void dfs(int sum, int maxx, int id) {
	if (id == n) return;
	for (int i = id; i < n; i ++ ) {
		if (sum + a[i] > a[i] * 2) {
			ans ++;
			ans %= mod;
		}
		dfs(sum + a[i], a[i], i + 1);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	a.resize(n);
	for (auto& i: a) cin >> i, maxx = max(maxx, i);
	if (maxx == 1) {
		for (int i = 3; i <= n; i ++ ) {
			ll kl = 2;
			int f = 0;
			ll p = 1;
			for (int j = 2; j <= n; j ++ ) {
				p *= j;
				if (p % kl == 0 && p > kl) {
					p /= kl;
					kl ++;
				}
				if (kl > i && f == 0) {
					f = 1;
					kl = 2;
				}
				if (kl > n - i && f == 1) {
					f = 2;
					kl = 1;
				}
				if (f == 2) kl = 1;
				p %= mod;
			}
			if (f == 0) {
				for (;kl <= i; kl ++ ) p /= kl;
				kl = 2;
				f = 1;
			}
			if (f == 1) for (;kl <= n - i; kl ++ ) p /= kl;
			ans += p;
			ans %= mod;
		}
		cout << ans;
		return 0;
	}
	ans = 0;
	sort(a.begin(), a.end());
	dfs(0, 0, 0);
	cout << ans;
	return 0;
}