#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define pb push_back
#define edl cout << '\n';
#define debug cout << '*';
const int N= 5e3+10;
//const int M= (1<<20)+15;
const int mod = 998244353;
ll a[N];
int cnt[N];
ll dp[N][N];
int n;
void solve(int t) {//yi di t gen mu gun wei zui da de 
	dp[0][0] = 1;
	rep(i, 1, n) {
		rep(j, 0, a[t]) {
			dp[i][j] = 0;
			dp[i][j] += dp[i-1][j];
			dp[i][j] = (dp[i][j]+mod)%mod;
			if (i!=t&&a[i]<=a[t]&&j>=a[i]) dp[i][j] += dp[i-1][j-a[i]];
			dp[i][j] = (dp[i][j]+mod)%mod;
		}
	}
//	if (t == 1) {
//		rep(i, 1, n) {
//			rep(j, 0, a[t]) cout << dp[i][j] << ' ';edl
//		}
//	}
}

ll quickpow(int p) {
	ll x = 2;
	ll ans = 1;
	while (p) {
		if (p&1) ans = ans*x%mod;
		x = x*x%mod;
		p >>= 1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) cnt[a[i]] ++;
	ll ans = 0;
	rep(i, 1, n) {
		solve(i);
//		ll res = 0;
		rep(j, 0, a[i]) {
			ans -= dp[n][j];
			ans = (ans+mod)%mod;
//			res += dp[n][j];
		}
//		cout << res << '\n';
	}
	ans += quickpow(n);
	ans %= mod;
	rep(i, 1, 5e3) {
		ll t = cnt[i]*(cnt[i]-1)/2;
		ans += t;
		ans %= mod;
	}
	cout << (ans-1+mod)%mod;
	return 0;
}
