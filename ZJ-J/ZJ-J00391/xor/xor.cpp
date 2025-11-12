#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define io ios::sync_with_stdio(0), cin.tie(), cout.tie()
#define open(_io) freopen(_io".in", "r", stdin), freopen(_io".out", "w", stdout)
const ll _n = 5e5 + 1;
ll n, k, a[_n], s[_n], dp[_n];
int main(){
	io;
	open("xor");
	cin >> n >> k;
	for (ll r = 1; r <= n; r++){
		cin >> a[r], s[r] = s[r - 1] ^ a[r], dp[r] = dp[r - 1];
		ll sl = s[r] ^ k;
		for (ll l = 0; l < r; l++) if (s[l] == sl) dp[r] = max(dp[r], dp[l] + 1);
	}cout << dp[n];
	return 0;
}

