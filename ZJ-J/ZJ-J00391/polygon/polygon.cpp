#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define io ios::sync_with_stdio(0), cin.tie(), cout.tie()
#define open(_io) freopen(_io".in", "r", stdin), freopen(_io".out", "w", stdout)
const ll _n = 5000 + 1, _m = 5000 * 5000 + 1, _mod = 998244353;
ll n, s, S = 0, a[_n], dp[_m];
int main(){
	io;
	open("polygon");
	cin >> n;
	for (ll i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (ll i = 3; i <= n; i++){
		s = 0;
		for (ll j = 1; j < i; j++) s += a[j];
		if (s <= a[i]) continue;
		if (s == a[i] + 1){S = (S + 1) % _mod; continue;}
		s -= a[i] + 1;
		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		for (ll j = 1; j < i; j++) for (ll k = s; k >= a[j]; k--) dp[k] = (dp[k] + dp[k - a[j]]) % _mod;
		for (ll k = 0; k <= s; k++) S = (S + dp[k]) % _mod;
	}cout << S;
	return 0;
}

